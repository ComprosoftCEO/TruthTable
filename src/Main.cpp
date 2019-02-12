#include <stdio.h>

#include <TruthTable.h>
#include <UnaryStatement.h>
#include <BinaryStatement.h>
#include <StatementList.h>

#include "Parser/truthtable.tab.h"
#include "Parser/truthtable.yy.h"


//Internal Methods
static bool build_truth_table(const char* input, TruthTable& table, StatementList*& list);
static StatementList* parse_statement(const char* input, TruthTable& table);



//
// Program entry point
//
int main(int argc, char** argv) {

	if (argc < 2) {
		printf("Usage: %s <statement1> <statement2> ...\n",argv[0]);
		return 0;
	}


	TruthTable all_tables[argc-1];
	StatementList* all_lists[argc-1];

	//Build all of the tables
	for (int i = 1; i < argc; ++i) {
		if (!build_truth_table(argv[i], all_tables[i-1], all_lists[i-1])) {
			//Free the other lists
			for (int j = i-1; j>=0; --j) {delete(all_lists[j]);}
			return 1;
		}
	}

	//Print all of the tables
	for (int i = 0; i < (argc-1); ++i) {
		if (i > 0) {printf("\n");}
		all_tables[i].print_table();
		delete(all_lists[i]);
	}

	return 0;
}



//
// Build a single truth table, but don't print it
//
static bool build_truth_table(const char* input, TruthTable& table, StatementList*& list) {

	list = parse_statement(input, table);
	if (!list) {return false;}

	list->build_table();

	return true;
}



//
// Parse the statement from a string input, returning NULL on failure
//
static StatementList* parse_statement(const char* input, TruthTable& table) {

	StatementList* list = nullptr;
	yyscan_t scanner;          
	YY_BUFFER_STATE buf;


	yylex_init(&scanner);
	buf = yy_scan_string(input,scanner);
	
	int result = yyparse(scanner,list, table);

	yy_delete_buffer(buf, scanner);
	yylex_destroy(scanner);


	if (result != 0) {
		return delete(list), nullptr;
	}
	return list;
}
