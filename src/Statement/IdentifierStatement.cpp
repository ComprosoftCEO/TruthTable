//Represents a generic variable name
#include <IdentifierStatement.h>
using std::string;



//
// Constructor
//
IdentifierStatement::IdentifierStatement(const std::string& name):
	name(name) {}



//
// Getter
//
const std::string& IdentifierStatement::getName() const {
	return this->name;
}
