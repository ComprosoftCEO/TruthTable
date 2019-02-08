//Implementation of the TruthTable class
#include <TruthTable.h>
#include <TruthStatement.h>
#include <cstdio>		/* For printf   */
#include <algorithm>	/* For std::max */
using std::string;
using std::max;


//
// Default Constructor
//
TruthTable::TruthTable():
  TruthTable("T","F") {}


//
// Initializing Constructor
//
TruthTable::TruthTable(const string& true_str, const string& false_str):
  true_str(true_str),
  false_str(false_str) {}


//
// Add an identifier to the list
//
void TruthTable::add_identifier(const string& identifier, bool* value) {
	this->all_identifiers.insert(identifier);
	this->identifier_width[identifier] = max(
		{true_str.length(), false_str.length(), identifier.length()}
	);
	this->identifier_value[identifier] = value;
}



//
// Add a column to the list
//
void TruthTable::add_column(const TruthStatement* statement) {
	this->all_columns.push_back(statement);
	this->column_width[statement] = max(
		{true_str.length(), false_str.length(), statement->to_string().length()}
	);
}




//
// Print out the entire table
//
void TruthTable::print_table() const {

	this->print_header();
	do {
		this->print_single_row();
	} while (this->compute_next_row());

}



//
// Print out the header
//
void TruthTable::print_header() const {

	printf("|");

	//Print out variables
	for (auto identifier = this->all_identifiers.begin(); identifier != this->all_identifiers.end(); ++identifier) {
		int width = this->identifier_width.find(*identifier)->second;
		printf("%*s|",width,identifier->c_str());
	}

	printf("|");

	//Print out expressions
	for (auto column = this->all_columns.begin(); column != this->all_columns.end(); ++column) {
		int width = this->column_width.find(*column)->second;
		printf("%*s|",width,(*column)->to_string().c_str());
	}

	printf("\n");
}



//
// Print a single expression row
//
void TruthTable::print_single_row() const {
	printf("|");

	//Print out variables
	for (auto identifier = this->all_identifiers.begin(); identifier != this->all_identifiers.end(); ++identifier) {
		int width = this->identifier_width.find(*identifier)->second;
		bool* value = this->identifier_value.find(*identifier)->second;
		printf("%*s|",width,this->get_truth_string(*value));
	}

	printf("|");

	//Print out expressions
	for (auto column = this->all_columns.begin(); column != this->all_columns.end(); ++column) {
		int width = this->column_width.find(*column)->second;
		bool value = (*column)->evaluate_statement();
		printf("%*s|",width,this->get_truth_string(value));
	}

	printf("\n");
}



//
// Get the string associated with a truth value
//
const char* TruthTable::get_truth_string(bool value) const {
	return value ? this->true_str.c_str() : this->false_str.c_str();
}



//
// Compute the next row of values
//
bool TruthTable::compute_next_row() const {

	for (auto identifier = this->all_identifiers.rbegin(); identifier != this->all_identifiers.rend(); ++identifier) {
		bool* value = this->identifier_value.find(*identifier)->second;

		if (*value) {*value = false; return true;}
		else {*value = true;}
	}

	return false;
}
