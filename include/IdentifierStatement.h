//Represents a generic variable name
#ifndef IDENTIFIER_STATEMENT_HEADER
#define IDENTIFIER_STATEMENT_HEADER

#include <TruthStatement.h>
#include <string>



class IdentifierStatement: public TruthStatement {

private:
	std::string name;
	bool current;

public:
	IdentifierStatement(const std::string& name);
	const std::string& getName() const;

	virtual void build_table(TruthTable& table) const;
	virtual bool evaluate_statement() const;
	virtual std::string to_string() const;
};



#endif	/* Identifier Statement Header Included */
