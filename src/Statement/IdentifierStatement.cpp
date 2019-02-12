//Represents a generic variable name
#include <IdentifierStatement.h>
#include <TruthTable.h>
#include <typeinfo>		/* For std::bad_cast */
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
// Identifier Statement Equality Operator
//
bool IdentifierStatement::operator==(const TruthStatement& stmt) const {
	try {
		const IdentifierStatement& other = dynamic_cast<const IdentifierStatement&>(stmt);
		return this->name == other.name;

	} catch (std::bad_cast ex) {
		return false;
	}
}


//
// Build table for an Identifier statement
//
void IdentifierStatement::build_table(bool allow_duplicate) {
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

