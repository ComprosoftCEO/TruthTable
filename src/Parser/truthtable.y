%define api.pure full
%locations

%parse-param { yyscan_t scanner } 
%lex-param {yyscan_t scanner}
%parse-param {TruthStatement* statement}

%code top {
	#include <cstdio>
	#include <cstdlib>
	#include <string>

	#include <IdentifierStatement.h>
	#include <UnaryStatement.h>
	#include <BinaryStatement.h>
}

%code requires {
	// Declare stuff from Flex that Bison needs to know about:
	typedef void* yyscan_t;
}

%code {
	int yylex(YYSTYPE* yylvalp, YYLTYPE* yyllocp, yyscan_t scanner);
	static void yyerror(YYLTYPE* yyllocp, yyscan_t unused, TruthStatement* statement, const char* msg);
}

%union {
	TruthStatement* stmt;	// Statement
	std::string* str;		// Identifier name
	UnaryOperator uop;		// Unary operator
	BinaryOperator bop;		// Binary Operator
}

%destructor {delete($$);} <str> <stmt>

//Terminal Types
%token <str> IDENTIFIER
%left  <bop> EQUAL NOT_EQUAL
%left  <bop> IMPLIES IFF
%left  <bop> AND OR
%right <uop> NOT

//Nonterminal Types
%type <stmt> statement
%type <stmt> unary_statement binary_statement

%%

//Top level function
statement
	:	IDENTIFIER							{$$ = new IdentifierStatement(*$1); delete($1);}
	|	unary_statement						{$$ = $1;}
	|	binary_statement					{$$ = $1;}
	|	'(' statement ')'					{$$ = $2;}

unary_statement
	:	NOT	statement	{$$ = new UnaryStatement($1,$2);}

binary_statement
	:	statement AND statement			{$$ = new BinaryStatement($1,$2,$3);}
	|	statement OR  statement			{$$ = new BinaryStatement($1,$2,$3);}
	|	statement IMPLIES statement		{$$ = new BinaryStatement($1,$2,$3);}
	|	statement IFF statement			{$$ = new BinaryStatement($1,$2,$3);}


%%


static void yyerror(YYLTYPE* yyllocp, yyscan_t unused, TruthStatement* stmt, const char *msg) {
	fprintf(stderr, "%s! [Line %d:%d]\n",
		msg,yyllocp->first_line, yyllocp->first_column);
}
