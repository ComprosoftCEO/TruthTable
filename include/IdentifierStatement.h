//Represents a generic variable name
#ifndef IDENTIFIER_STATEMENT_HEADER
#define IDENTIFIER_STATEMENT_HEADER

#include <TruthStatement.h>
#include <string>



class IdentifierStatement: public TruthStatement {

private:
	std::string name;

public:

	IdentifierStatement(TruthTable& table, const std::string& name);

	const std::string& getName() const;

	virtual bool operator==(const TruthStatement& other) const;

	virtual void build_table(bool allow_duplicate = false);
	virtual bool evaluate_statement() const;
	virtual std::string to_string() const;
};



#endif	/* Identifier Statement Header Included */
