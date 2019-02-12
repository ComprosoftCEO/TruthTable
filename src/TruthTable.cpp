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
void TruthTable::add_identifier(const string& identifier) {
	this->all_identifiers.insert(identifier);
	this->identifier_width[identifier] = max(
		{true_str.length(), false_str.length(), identifier.length()}
	);
	this->identifier_value[identifier] = true;
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
// Clear everything from the table
//
void TruthTable::clear_table() {
	this->all_identifiers.clear();
	this->identifier_width.clear();
	this->identifier_value.clear();
	this->all_columns.clear();
	this->column_width.clear();
}


//
// Get the value of an identifier
//
bool TruthTable::get_identifier_value(const string& identifier) const {
	return this->identifier_value.find(identifier)->second;
}


//
// Get the string associated with a truth value
//
const std::string& TruthTable::get_truth_string(bool value) const {
	return value ? this->true_str : this->false_str;
}




//
// Print out the entire table
//
void TruthTable::print_table() {

	this->print_header();
	this->print_border();

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
		size_t width = this->identifier_width.find(*identifier)->second;
		print_centered(*identifier,width);
		printf("|");
	}

	printf("|");

	//Print out expressions
	for (auto column = this->all_columns.begin(); column != this->all_columns.end(); ++column) {
		size_t width = this->column_width.find(*column)->second;
		print_centered((*column)->to_string(),width);
		printf("|");
	}

	printf("\n");
}



//
// Print the single-line border between the top and True/False values
//
void TruthTable::print_border() const {

	printf("|");

	//Print out variables
	for (auto identifier = this->all_identifiers.begin(); identifier != this->all_identifiers.end(); ++identifier) {
		size_t width = this->identifier_width.find(*identifier)->second;
		print_horizontal_line(width);
		printf("|");
	}

	printf("|");

	//Print out expressions
	for (auto column = this->all_columns.begin(); column != this->all_columns.end(); ++column) {
		size_t width = this->column_width.find(*column)->second;
		print_horizontal_line(width);
		printf("|");
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
		size_t width = this->identifier_width.find(*identifier)->second;
		bool value = this->identifier_value.find(*identifier)->second;

		print_centered(this->get_truth_string(value), width);
		printf("|");
	}

	printf("|");

	//Print out expressions
	for (auto column = this->all_columns.begin(); column != this->all_columns.end(); ++column) {
		size_t width = this->column_width.find(*column)->second;
		bool value = (*column)->evaluate_statement();

		print_centered(this->get_truth_string(value), width);
		printf("|");
	}

	printf("\n");
}




void TruthTable::print_centered(const std::string& to_print, size_t width) {

	size_t left_margin = 0, right_margin = 0;
	size_t string_width = to_print.length();

	if (string_width < width) {
		left_margin = ((width - string_width) / 2);
		right_margin = width - (string_width + left_margin);
	}

	printf("%*s%*s%*s",
		(int) left_margin, "",
		(int) (string_width), to_print.c_str(),
		(int) right_margin, ""
	);

}



//
// Print a line of dashes
//
void TruthTable::print_horizontal_line(size_t width) {
	for (size_t i = 0; i < width; ++i) {
		printf("-");
	}
}



//
// Compute the next row of values
//
bool TruthTable::compute_next_row() {

	for (auto identifier = this->all_identifiers.rbegin(); identifier != this->all_identifiers.rend(); ++identifier) {
		bool& value = this->identifier_value[*identifier];

		if (value) {value = false; return true;}
		else {value = true;}
	}

	return false;
}
