//Literal boolean statement
#ifndef LITERAL_STATEMENT_HEADER
#define LITERAL_STATEMENT_HEADER


#include <TruthStatement.h>


class LiteralStatement: public TruthStatement {

private:
	bool value;
	TruthTable* table;

public:
	LiteralStatement(bool value);

	virtual void build_table(TruthTable& table);
	virtual bool evaluate_statement() const;
	virtual std::string to_string() const;
};

#endif
