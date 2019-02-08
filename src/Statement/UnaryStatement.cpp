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
// Build table for Unary statement
//
void UnaryStatement::build_table(TruthTable& table) {
	this->stmt->build_table(table);
	table.add_column(this);
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
