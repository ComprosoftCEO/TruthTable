//Represents a unary expression
#ifndef UNARY_STATEMENT_HEADER
#define UNARY_STATEMENT_HEADER


#include <TruthStatement.h>
#include <string>



enum class UnaryOperator {
	NOT
};



class UnaryStatement: public TruthStatement {

private:
	TruthStatement* stmt;		// Freed on destruction
	UnaryOperator op;

public:
	UnaryStatement(UnaryOperator op, TruthStatement* stmt);
	virtual ~UnaryStatement();
};


#endif	/* Unary Statement Header Included */
