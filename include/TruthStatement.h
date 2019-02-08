//Abstract Truth Table Statement class
#ifndef TRUTH_STATEMENT_HEADER
#define TRUTH_STATEMENT_HEADER

#include <string>
#include <TruthTable.h>


class TruthStatement {

public:
	virtual ~TruthStatement() = default;

	virtual void build_statement(TruthTable& table) const = 0;
	virtual bool evaluate_statement() const;
	virtual std::string to_string() const;
};


#endif	/* Truth Statement Header Included */
