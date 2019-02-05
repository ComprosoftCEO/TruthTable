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


class BinaryStatement: public TruthStatement {

private:
	TruthStatement* left;		// Freed upon destruction
	TruthStatement* right;		// Freed upon destruction
	BinaryOperator op;

public:
	BinaryStatement(TruthStatement* left, BinaryOperator op, TruthStatement* right);
	virtual ~BinaryStatement();

};


#endif	/* Binary Statement Header Included */
