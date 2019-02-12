#include <stdio.h>

#include <TruthTable.h>
#include <BinaryStatement.h>
#include <UnaryStatement.h>

#include "Parser/truthtable.tab.h"
#include "Parser/truthtable.yy.h"


static TruthStatement* parse_statement(const char* input, TruthTable& table);



//
// Program entry point
//
int main(int argc, char** argv) {

	if (argc < 2) {
		printf("Usage: %s <statement>\n",argv[0]);
		return 0;
	}

	TruthTable table;
	TruthStatement* stmt = parse_statement(argv[1], table);
	if (!stmt) {return 1;}

	stmt->build_table();

	table.print_table();	

	delete(stmt);
	return 0;
}



//
// Parse the statement from a string input, returning NULL on failure
//
static TruthStatement* parse_statement(const char* input, TruthTable& table) {

	TruthStatement* stmt = nullptr;
	yyscan_t scanner;          
	YY_BUFFER_STATE buf;


	yylex_init(&scanner);
	buf = yy_scan_string(input,scanner);
	
	int result = yyparse(scanner,stmt, table);

	yy_delete_buffer(buf, scanner);
	yylex_destroy(scanner);


	if (result != 0) {
		return delete(stmt), nullptr;
	}
	return stmt;
}
