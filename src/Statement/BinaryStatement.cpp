//Represents a two-part statement (like A or B)
#include <BinaryStatement.h>
#include <TruthTable.h>
#include <ClassComparer.h>
#include <typeinfo>		/* For std::bad_cast */
using std::string;


//
// Constructor
//
BinaryStatement::BinaryStatement(TruthTable& table, TruthStatement* left, BinaryOperator op, TruthStatement* right):
  TruthStatement(table),
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
// Binary Statement Equality Operator
//
bool BinaryStatement::operator==(const TruthStatement& stmt) const {
	try {
		const BinaryStatement& other = dynamic_cast<const BinaryStatement&>(stmt);

		ClassComparer<const TruthStatement*> comparer;
		return (this->op == other.op) && comparer(this->left,other.left) && comparer(this->right,other.right);

	} catch (std::bad_cast ex) {
		return false;
	}
}


//
// Build table for a binary statement
//
void BinaryStatement::build_table(bool allow_duplicate) {
	this->left->build_table();
	this->right->build_table();
	this->table.add_column(this,allow_duplicate);
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
