//Generic class hasher interface
#ifndef CLASS_HASHER_HEADER
#define CLASS_HASHER_HEADER

#include <cstddef>	/* For size_t */

template <typename T>
class ClassHasher {

public:
	std::size_t operator()(const T& value) const noexcept {
		return value.hash_class();
	}
};

//Partial specilizaiton for a pointer type
template <typename T>
class ClassHasher<T*> {

public:
	std::size_t operator()(const T* value) const noexcept {
		const ClassHasher<T> hasher;
		if (value == nullptr) {return std::hash<T*>()(value);}
		return hasher(*value);
	}
};




//Interface for hashing a class
class Hashable {

public:
	virtual std::size_t hash_class() const noexcept = 0;
};


#endif	/* Class Hasher Included */
