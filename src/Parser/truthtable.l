%{
	#include <TruthTable.h>
	#include "truthtable.tab.h"

	//Track line numbers for parsed tokens
	#define YY_USER_ACTION                                             \
	yylloc->first_line = yylloc->last_line;                            \
	yylloc->first_column = yylloc->last_column;                        \
	if (yylloc->last_line == yylineno)                                 \
		yylloc->last_column += yyleng;                                 \
	else {                                                             \
		yylloc->last_line = yylineno;                                  \
		yylloc->last_column = yytext + yyleng - strrchr(yytext, '\n'); \
	}
%}



%option yylineno noyywrap 8bit nodefault                        
%option reentrant bison-bridge bison-locations 
%%

[a-zA-Z][a-zA-Z0-9]*		{yylval->str = new std::string(yytext); 	return IDENTIFIER;}
~							{yylval->uop = UnaryOperator::NOT;			return NOT;}
&							{yylval->bop = BinaryOperator::AND;			return AND;}
[+]							{yylval->bop = BinaryOperator::OR;			return OR;}
->							{yylval->bop = BinaryOperator::IMPLIES;		return IMPLIES;}
[<]-[>]						{yylval->bop = BinaryOperator::IFF;			return IFF;}
=							{yylval->bop = BinaryOperator::EQUAL;		return EQUAL;}
!=							{yylval->bop = BinaryOperator::NOT_EQUAL;	return NOT_EQUAL;}
.							{return yytext[0];}
\n							/* Ignore new lines */
