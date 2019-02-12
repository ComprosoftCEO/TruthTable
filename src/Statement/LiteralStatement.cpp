//Literal boolean statement
#include <LiteralStatement.h>
using std::string;



//
// Constructor
//
LiteralStatement::LiteralStatement(TruthTable& table, bool value):
  TruthStatement(table),
  value(value) {}




//
// Build table for a literal value
//
void LiteralStatement::build_table() {
}


//
// Evaluate the statement
//
bool LiteralStatement::evaluate_statement() const {
	return this->value;
}


//
// Convert to string
//
string LiteralStatement::to_string() const {
	return this->table.get_truth_string(this->value);
}

