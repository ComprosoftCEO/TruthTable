%{
	#include <IdentifierStatement.h>
	#include <UnaryStatement.h>
	#include <BinaryStatement.h>

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

([Tt][Rr][Uu][Ee]|T|1)		{yylval->val = true;  return LITERAL;}
([Ff][Aa][Ll][Ss][Ee]|F|0)	{yylval->val = false; return LITERAL;}

[a-zA-Z][a-zA-Z0-9]*		{yylval->str = new std::string(yytext); 	return IDENTIFIER;}
[~!]						{yylval->uop = UnaryOperator::NOT;			return NOT;}
&							{yylval->bop = BinaryOperator::AND;			return AND;}
[|+]						{yylval->bop = BinaryOperator::OR;			return OR;}
[\^]						{yylval->bop = BinaryOperator::XOR;			return XOR;}
->							{yylval->bop = BinaryOperator::IMPLIES;		return IMPLIES;}
(~>)|(!>)|-					{yylval->bop = BinaryOperator::NOT_IMPLIES;	return NOT_IMPLIES;}
[<]-[>]						{yylval->bop = BinaryOperator::IFF;			return IFF;}
=							{yylval->bop = BinaryOperator::EQUAL;		return EQUAL;}
!=							{yylval->bop = BinaryOperator::NOT_EQUAL;	return NOT_EQUAL;}

[][()\{\}:.;<>'"_^|$~+\-&`@%=*/\\!?#,]		{return yytext[0];}

.			/* Ignore spaces */
\n			/* Ignore new lines */
