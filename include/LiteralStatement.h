//Literal boolean statement
#ifndef LITERAL_STATEMENT_HEADER
#define LITERAL_STATEMENT_HEADER


#include <TruthStatement.h>


class LiteralStatement: public TruthStatement {

private:
	bool value;

public:
	LiteralStatement(TruthTable& table, bool value);

	virtual bool operator==(const TruthStatement& other) const;

	virtual void build_table(bool allow_duplicate = false);
	virtual bool evaluate_statement() const;
	virtual std::string to_string() const;
};

#endif
