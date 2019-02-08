//Represents a unary expression
#ifndef UNARY_STATEMENT_HEADER
#define UNARY_STATEMENT_HEADER


#include <TruthStatement.h>
#include <string>



enum class UnaryOperator {
	NOT
};

const std::string& operator_symbol(UnaryOperator op);
bool evaluate_operator(UnaryOperator op, bool input);




class UnaryStatement: public TruthStatement {

private:
	TruthStatement* stmt;		// Freed on destruction
	UnaryOperator op;

public:
	UnaryStatement(UnaryOperator op, TruthStatement* stmt);
	virtual ~UnaryStatement();

	virtual void build_statement(TruthTable& table) const;
	virtual bool evaluate_statement() const;
	virtual std::string to_string() const;
};


#endif	/* Unary Statement Header Included */
