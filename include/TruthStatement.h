//Abstract Truth Table Statement class
#ifndef TRUTH_STATEMENT_HEADER
#define TRUTH_STATEMENT_HEADER

#include <string>
#include <TruthTable.h>


class TruthStatement {

protected:
	TruthTable& table;

public:
	TruthStatement(TruthTable& table);
	virtual ~TruthStatement() = default;

	virtual void build_table() = 0;
	virtual bool evaluate_statement() const = 0;
	virtual std::string to_string() const = 0;
};


#endif	/* Truth Statement Header Included */
