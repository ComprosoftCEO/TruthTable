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
// Build table for a binary statement
//
void BinaryStatement::build_table(TruthTable& table) const {
	this->left->build_table(table);
	this->right->build_table(table);
	table.add_column(this);
}


//
// Evaluate the statement
//
bool BinaryStatement::evaluate_statement() const {
	bool left = this->left->evaluate_statement();
	bool right = this->right->evaluate_statement();
	return evaluate_operator(this->op,left,right);
}


//
// Convert to string
//
string BinaryStatement::to_string() const {

	string left = this->left->to_string();
	string right = this->right->to_string();
	string op = operator_symbol(this->op);

	return "("+ left + op + right + ")";
}
