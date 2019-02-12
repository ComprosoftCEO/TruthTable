//Literal boolean statement
#include <LiteralStatement.h>
#include <TruthTable.h>
#include <ClassComparer.h>
#include <typeinfo>		/* For std::bad_cast */
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
// Literal Statement Equality Operator
//
bool LiteralStatement::operator==(const TruthStatement& stmt) const {
	try {
		const LiteralStatement& other = dynamic_cast<const LiteralStatement&>(stmt);
		return (this->value == other.value);

	} catch (std::bad_cast ex) {
		return false;
	}
}



//
// Convert to string
//
string LiteralStatement::to_string() const {
	return this->table.get_truth_string(this->value);
}

