//Group of several independent statements to include in one table
#ifndef STATEMENT_LIST_HEADER
#define STATEMENT_LIST_HEADER

#include <TruthStatement.h>
#include <vector>


class StatementList {

private:
	std::vector<TruthStatement*> all_statements;

public:
	StatementList() = default;
	~StatementList();

	void add_statement(TruthStatement* stmt);
	void build_table();
};


#endif	/* Statement List Header Included */
