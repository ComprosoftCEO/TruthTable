//Represents a generic variable name
#include <IdentifierStatement.h>
using std::string;



//
// Constructor
//
IdentifierStatement::IdentifierStatement(const std::string& name):
  name(name),
  current(true) {}



//
// Getter
//
const std::string& IdentifierStatement::getName() const {
	return this->name;
}



//
// Build Identifier Statement
//
void IdentifierStatement::build_statement(TruthTable& table) const {
	table.add_identifier(this->name, (bool*) &this->current);
}



//
// Evaluate the statement
//
bool IdentifierStatement::evaluate_statement() const {
	return this->current;
}


//
// Convert to string
//
string IdentifierStatement::to_string() const {
	return this->name;
}

