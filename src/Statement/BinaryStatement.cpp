//Represents a two-part statement (like A or B)
#include <BinaryStatement.h>
using std::string;


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



//
// Binary build Statement
//
void BinaryStatement::build_statement(TruthTable& table) const {
	this->left->build_statement(table);
	this->right->build_statement(table);
	table.add_column(this);
}


//
// Convert to string
//
string BinaryStatement::to_string() const {

	string left = this->left->to_string();
	string right = this->right->to_string();
	string op = operator_symbol(this->op);

	return " "+ left + op + right + " ";
}
