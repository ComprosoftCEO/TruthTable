//Truth Statement Implementation
#include <TruthStatement.h>



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
