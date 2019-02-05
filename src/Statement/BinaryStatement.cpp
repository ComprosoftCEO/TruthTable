//Represents a two-part statement (like A or B)
#include <BinaryStatement.h>



//
// Constructor
//
BinaryStatement::BinaryStatement(TruthStatement* left, BinaryOperator op, TruthStatement* right):
	left(left),
	right(right),
	op(op) {}



//
// Destructor
//
BinaryStatement::~BinaryStatement() {
	delete(this->left);
	delete(this->right);
}
