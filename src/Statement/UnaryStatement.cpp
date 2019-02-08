//Represents a unary expression
#include <UnaryStatement.h>
using std::string;


//
// Constructor
//
UnaryStatement::UnaryStatement(UnaryOperator op, TruthStatement* stmt):
	stmt(stmt),
	op(op) {}


//
// Destructor
//
UnaryStatement::~UnaryStatement() {
	delete(this->stmt);
}



//
// Build Unary Statement
//
void UnaryStatement::build_statement(TruthTable& table) const {
	this->stmt->build_statement(table);
	table.add_column(this);
}


//
// Convert to string
//
string UnaryStatement::to_string() const {

	string stmt = this->stmt->to_string();
	string op = operator_symbol(this->op);

	return "(" + op + stmt + ")";
}
