//Abstract Truth Table Statement class
#ifndef TRUTH_STATEMENT_HEADER
#define TRUTH_STATEMENT_HEADER

#include <string>


class TruthStatement {

protected:
	class TruthTable& table;

public:
	TruthStatement(TruthTable& table);
	virtual ~TruthStatement() = default;

	//Comparison operators
	virtual bool operator==(const TruthStatement& other) const = 0;
	bool operator!=(const TruthStatement& other) const;

	//Truth-table functions
	virtual void build_table() = 0;
	virtual bool evaluate_statement() const = 0;
	virtual std::string to_string() const = 0;
};


#endif	/* Truth Statement Header Included */
