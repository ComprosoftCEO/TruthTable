//Functional class to compare two classes
#ifndef CLASS_COMPARER_HEADER
#define CLASS_COMPARER_HEADER


//Compare classes using operator==
template <typename T>
class ClassComparer {

public:
	bool operator()(const T& left, const T& right) const {
		return (left == right);
	}
};



//Special case for pointer types
template <typename T>
class ClassComparer<T*> {

public:
	bool operator()(const T* left, const T* right) const {

		if (left == right) {
			return true;
		} else if ((left == nullptr) || (right == nullptr)) {
			return false;
		}

		ClassComparer<T> compare;
		return compare(*left,*right);
	}
};



#endif	/* Class Comparer Header Included */
