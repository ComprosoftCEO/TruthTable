%define api.pure full
%locations

%parse-param { yyscan_t scanner } 
%lex-param {yyscan_t scanner}
%parse-param {TruthStatement*& statement} {TruthTable& table}

%code top {
	#include <cstdio>
	#include <cstdlib>
	#include <string>

	#include <IdentifierStatement.h>
	#include <LiteralStatement.h>
	#include <UnaryStatement.h>
	#include <BinaryStatement.h>

	#include <StatementList.h>
}

%code requires {
	// Declare stuff from Flex that Bison needs to know about:
	typedef void* yyscan_t;
}

%code {
	int yylex(YYSTYPE* yylvalp, YYLTYPE* yyllocp, yyscan_t scanner);
	static void yyerror(YYLTYPE* yyllocp, yyscan_t unused, TruthStatement*& statement, TruthTable& table, const char* msg);
}

%union {
	TruthStatement* stmt;	// Statement
	StatementList* list;	// List
	std::string* str;		// Identifier name
	UnaryOperator uop;		// Unary operator
	BinaryOperator bop;		// Binary Operator
	bool val;				// Boolean value
}

%destructor {delete($$);} <str> <stmt> <list>

//Terminal Types
%token <str> IDENTIFIER
%token <val> LITERAL
%left  <bop> EQUAL NOT_EQUAL
%left  <bop> IMPLIES NOT_IMPLIES IFF
%left  <bop> AND OR XOR
%right <uop> NOT

//Nonterminal Types
%type <stmt> statement
%type <stmt> unary_statement binary_statement

%%

//Top level function
code: statement							{statement = $1;}

statement
	:	IDENTIFIER						{$$ = new IdentifierStatement(table,*$1); delete($1);}
	|	LITERAL							{$$ = new LiteralStatement(table,$1);}
	|	unary_statement					{$$ = $1;}
	|	binary_statement				{$$ = $1;}
	|	'(' statement ')'				{$$ = $2;}
	|	'[' statement ']'				{$$ = $2;}

unary_statement
	:	NOT	statement					{$$ = new UnaryStatement(table,$1,$2);}

binary_statement
	:	statement AND statement			{$$ = new BinaryStatement(table,$1,$2,$3);}
	|	statement OR  statement			{$$ = new BinaryStatement(table,$1,$2,$3);}
	|	statement XOR statement			{$$ = new BinaryStatement(table,$1,$2,$3);}
	|	statement IMPLIES statement		{$$ = new BinaryStatement(table,$1,$2,$3);}
	|	statement NOT_IMPLIES statement	{$$ = new BinaryStatement(table,$1,$2,$3);}
	|	statement IFF statement			{$$ = new BinaryStatement(table,$1,$2,$3);}
	|	statement EQUAL statement		{$$ = new BinaryStatement(table,$1,$2,$3);}
	|	statement NOT_EQUAL statement	{$$ = new BinaryStatement(table,$1,$2,$3);}


%%


static void yyerror(YYLTYPE* yyllocp, yyscan_t unused, TruthStatement*& stmt, TruthTable& table, const char *msg) {
	fprintf(stderr, "%s! [Line %d:%d]\n",
		msg,yyllocp->first_line, yyllocp->first_column);
}
