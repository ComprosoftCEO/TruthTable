//Represents a unary expression
#include <UnaryStatement.h>
#include <TruthTable.h>
#include <ClassComparer.h>
#include <typeinfo>		/* For std::bad_cast */
using std::string;


//
// Constructor
//
UnaryStatement::UnaryStatement(TruthTable& table, UnaryOperator op, TruthStatement* stmt):
  TruthStatement(table),
  stmt(stmt),
  op(op) {}


//
// Destructor
//
UnaryStatement::~UnaryStatement() {
	delete(this->stmt);
}



//
// Unary Statement Equality Operator
//
bool UnaryStatement::operator==(const TruthStatement& stmt) const {
	try {
		const UnaryStatement& other = dynamic_cast<const UnaryStatement&>(stmt);

		ClassComparer<const TruthStatement*> comparer;
		return (this->op == other.op) && comparer(this->stmt,other.stmt);

	} catch (std::bad_cast ex) {
		return false;
	}
}



//
// Build table for Unary statement
//
void UnaryStatement::build_table() {
	this->stmt->build_table();
	this->table.add_column(this);
}


//
// Evaluate the statement
//
bool UnaryStatement::evaluate_statement() const {
	bool value = this->stmt->evaluate_statement();
	return evaluate_operator(this->op,value);
}


//
// Convert to string
//
string UnaryStatement::to_string() const {

	string stmt = this->stmt->to_string();
	string op = operator_symbol(this->op);

	return "(" + op + stmt + ")";
}
