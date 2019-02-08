//Binary Operator Helper Methods
#include <BinaryStatement.h>
#include <map>
#include <functional>
using std::function;
using std::string;
using std::map;


//Single entry
struct OperatorData {
	string symbol;
	function<bool(bool,bool)> func;
};



static const map<BinaryOperator,OperatorData> OPERATOR_DATA = {
	{BinaryOperator::AND,		{"&",   [](bool left, bool right) -> bool {return left && right;}}},
	{BinaryOperator::OR,		{"+",   [](bool left, bool right) -> bool {return left || right;}}},
	{BinaryOperator::IMPLIES,	{"->",  [](bool left, bool right) -> bool {return (!left) || right;}}},
	{BinaryOperator::IFF,		{"<->", [](bool left, bool right) -> bool {return left == right;}}},
	{BinaryOperator::EQUAL, 	{"=",   [](bool left, bool right) -> bool {return left == right;}}},
	{BinaryOperator::NOT_EQUAL,	{"!=",  [](bool left, bool right) -> bool {return left != right;}}},
};



//
// Get the operator symbol
//
const std::string& operator_symbol(BinaryOperator op) {
	return OPERATOR_DATA.find(op)->second.symbol;
}




//
// Execute a binary function
//
bool evaluate_operator(BinaryOperator op, bool left, bool right) {
	return OPERATOR_DATA.find(op)->second.func(left,right);
}
