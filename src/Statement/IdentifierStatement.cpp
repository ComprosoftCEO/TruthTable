//Represents a generic variable name
#include <IdentifierStatement.h>
using std::string;



//
// Constructor
//
IdentifierStatement::IdentifierStatement(TruthTable& table, const std::string& name):
  TruthStatement(table),
  name(name) {}



//
// Getter
//
const std::string& IdentifierStatement::getName() const {
	return this->name;
}



//
// Build table for an Identifier statement
//
void IdentifierStatement::build_table() {
	this->table.add_identifier(this->name);
}



//
// Evaluate the statement
//
bool IdentifierStatement::evaluate_statement() const {
	return this->table.get_identifier_value(this->name);
}


//
// Convert to string
//
string IdentifierStatement::to_string() const {
	return this->name;
}

