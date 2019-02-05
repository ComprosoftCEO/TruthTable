//Represents a unary expression
#include <UnaryStatement.h>



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
