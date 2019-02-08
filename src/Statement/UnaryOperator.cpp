//Unary Operator Helper Methods
#include <UnaryStatement.h>
#include <map>
#include <functional>
using std::function;
using std::string;
using std::map;


//Single entry
struct OperatorData {
	string symbol;
	function<bool(bool)> func;
};



static const map<UnaryOperator,OperatorData> OPERATOR_DATA = {
	{UnaryOperator::NOT,	{"~",   [](bool input) -> bool {return !input;}}},
};



//
// Get the operator symbol
//
const std::string& operator_symbol(UnaryOperator op) {
	return OPERATOR_DATA.find(op)->second.symbol;
}




//
// Execute a unary function
//
bool evaluate_operator(UnaryOperator op, bool input) {
	return OPERATOR_DATA.find(op)->second.func(input);
}

