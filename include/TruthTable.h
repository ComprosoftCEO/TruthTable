//Main classes for the TruthTable
#ifndef TRUTH_TABLE_HEADER
#define TRUTH_TABLE_HEADER


#include <set>
#include <vector>
#include <map>
#include <string>


//Forward declare the class
class TruthStatement;


class TruthTable {

private:
	std::string true_str, false_str;

	//List of identifiers and how many spaces wide to make them
	std::set<std::string> all_identifiers;
	std::map<std::string,int> identifier_width;
	std::map<std::string,bool> identifier_value;

	//List of expressions and how many spaces wide to make them
	std::vector<const TruthStatement*> all_columns;
	std::map<const TruthStatement*,int> column_width;


public:

	TruthTable();
	TruthTable(const std::string& true_str, const std::string& false_str);

	void add_identifier(const std::string& identifier);
	void add_column(const TruthStatement* statement);

	bool get_identifier_value(const std::string& identifier) const;

	void print_table();

	const char* get_truth_string(bool value) const;


private:
	void print_header() const;
	void print_single_row() const;
	bool compute_next_row();
};



#endif	/* Truth Table Header Included */
