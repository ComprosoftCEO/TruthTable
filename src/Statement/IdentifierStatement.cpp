//Represents a generic variable name
#include <IdentifierStatement.h>
using std::string;



//
// Constructor
//
IdentifierStatement::IdentifierStatement(const std::string& name):
  name(name),
  table(nullptr) {}



//
// Getter
//
const std::string& IdentifierStatement::getName() const {
	return this->name;
}



//
// Build table for an Identifier statement
//
void IdentifierStatement::build_table(TruthTable& table) {
	table.add_identifier(this->name);
	this->table = &table;
}



//
// Evaluate the statement
//
bool IdentifierStatement::evaluate_statement() const {
	if (!table) {return false;	/* Should NOT happen */}
	return this->table->get_identifier_value(this->name);
}


//
// Convert to string
//
string IdentifierStatement::to_string() const {
	return this->name;
}

