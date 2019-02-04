
#include <string>

enum class UnaryOperator {
	NOT
};

enum class BinaryOperator {
	AND,
	OR,
	IMPLIES,
	IFF
};


class TruthStatement {

};


class IdentifierStatement: public TruthStatement {

public:
	IdentifierStatement(const std::string& name);
};


class UnaryStatement: public TruthStatement {

public:
	UnaryStatement(UnaryOperator op, TruthStatement* stmt);
};

class BinaryStatement: public TruthStatement {

public:
	BinaryStatement(TruthStatement* left, BinaryOperator op, TruthStatement* right);
};
