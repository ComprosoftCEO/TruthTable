//Truth Statement Implementation
#include <TruthStatement.h>
using std::string;


//
// Constructor
//
TruthStatement::TruthStatement(TruthTable& table):
  table(table) {}



//
// Not Equls To
//
bool TruthStatement::operator!=(const TruthStatement& other) const {
	return !(*this == other);
}



//
// Hash operator
//
size_t TruthStatement::hash_class() const noexcept {
	std::hash<string> hasher;
	return hasher(this->to_string());
}
