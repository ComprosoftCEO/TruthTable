//Represents a two-part statement (like A or B)
#ifndef BINARY_STATEMENT_HEADER
#define BINARY_STATEMENT_HEADER


#include <TruthStatement.h>


enum class BinaryOperator {
	AND,
	OR,
	IMPLIES,
	IFF,
	EQUAL,
	NOT_EQUAL,
};


const std::string& operator_symbol(BinaryOperator op);
bool evaluate_operator(BinaryOperator op, bool left, bool right);



class BinaryStatement: public TruthStatement {

private:
	TruthStatement* left;		// Freed upon destruction
	TruthStatement* right;		// Freed upon destruction
	BinaryOperator op;

public:
	BinaryStatement(TruthStatement* left, BinaryOperator op, TruthStatement* right);
	virtual ~BinaryStatement();

	virtual void build_table(TruthTable& table) const;
	virtual bool evaluate_statement() const;
	virtual std::string to_string() const;
};


#endif	/* Binary Statement Header Included */
