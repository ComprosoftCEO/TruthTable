%define api.pure full
%locations

%parse-param { yyscan_t scanner } 
%lex-param {yyscan_t scanner}
%parse-param {TruthStatement* statement}

%code top {
	#include <cstdio>
	#include <cstdlib>
	#include <string>
	#include <TruthTable.h>
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
	UnaryOperator  uop;		// Unary operator
	BinaryOperator bop;		// Binary operator
}

%destructor {delete($$);} <str> <stmt>

//Terminal Types
%token <str> IDENTIFIER
%left IMPLIES IFF
%left AND OR
%right NOT

//Nonterminal Types
%type <stmt> statement
%type <uop> unary_operator
%type <bop> binary_operator

%%

//Top level function
statement
	:	IDENTIFIER							{$$ = new IdentifierStatement(*$1); delete($1);}
	|	unary_operator statement			{$$ = new UnaryStatement($1,$2);}
	| 	statement binary_operator statement	{$$ = new BinaryStatement($1,$2,$3);}
	|	'(' statement ')'					{$$ = $2;}

unary_operator
	:	NOT			{$$ = UnaryOperator::NOT;}

binary_operator
	:	AND			{$$ = BinaryOperator::AND;}
	|	OR			{$$ = BinaryOperator::OR;}
	|	IMPLIES		{$$ = BinaryOperator::IMPLIES;}
	|	IFF			{$$ = BinaryOperator::IFF;}


%%


static void yyerror(YYLTYPE* yyllocp, yyscan_t unused, TruthStatement* stmt, const char *msg) {
	fprintf(stderr, "%s! [Line %d:%d]\n",
		msg,yyllocp->first_line, yyllocp->first_column);
}
