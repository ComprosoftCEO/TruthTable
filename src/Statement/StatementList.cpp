//Group of several independent statements to include in one table
#include <StatementList.h>


//
// Destructor
//
StatementList::~StatementList() {
	for (auto stmt = this->all_statements.begin(); stmt != this->all_statements.end(); ++stmt) {
		delete(*stmt);
	}
}



//
// Add a statement to the list
//
void StatementList::add_statement(TruthStatement* stmt) {
	this->all_statements.push_back(stmt);
}



//
// Build the table
//
void StatementList::build_table() {
	//Build table for all inside pieces
	for (auto stmt = this->all_statements.begin(); stmt != this->all_statements.end(); ++stmt) {
		(*stmt)->build_table(true);
	}
}
