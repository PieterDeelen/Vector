#ifndef VECTOR_H_
#define VECTOR_H_

#include <ostream>
#include <initializer_list>
#include <cassert>
#include <stdexcept>

template<typename Type, size_t Size>
class Vector {
public:
	Vector(Type elements[Size]);
	Vector(const Vector<Type, Size>& other);

	Vector();
	Vector(Type x);
	Vector(Type x, Type y);
	Vector(Type x, Type y, Type z);
	Vector(Type x, Type y, Type z, Type w);

	double& operator[](int index);
	const double& operator[](int index) const;

	Vector<Type, Size>& operator+=(const Vector<Type, Size>& other);
	Vector<Type, Size>& operator-=(const Vector<Type, Size>& other);

	bool operator==(const Vector<Type, Size>& other) const;
	bool operator!=(const Vector<Type, Size>& other) const;

private:
	Type elements[Size];

	void initialize(size_t offset, size_t size);
};

template<typename Type, size_t Size>
inline Vector<Type, Size>::Vector(Type elements[Size]) {
	for (size_t i = 0; i < Size; i++) {
		this->elements[i] = elements[i];
	}
}

template<typename Type, size_t Size>
inline Vector<Type, Size>::Vector(const Vector<Type, Size>& other) {
	for (size_t i = 0; i < Size; i++) {
		elements[i] = other.elements[i];
	}
}

template<typename Type, size_t Size>
inline Vector<Type, Size>::Vector() {
	constexpr size_t arity = 0;
	static_assert(Size >= 0, "");
	initialize(arity, Size);
}

template<typename Type, size_t Size>
inline Vector<Type, Size>::Vector(Type x) {
	constexpr size_t arity = 1;
	static_assert(Size >= arity, "");
	elements[0] = x;
	initialize(arity, Size);
}

template<typename Type, size_t Size>
inline Vector<Type, Size>::Vector(Type x, Type y) {
	constexpr size_t arity = 2;
	static_assert(Size >= arity, "");
	elements[0] = x;
	elements[1] = y;
	initialize(arity, Size);
}
template<typename Type, size_t Size>
inline Vector<Type, Size>::Vector(Type x, Type y, Type z) {
	constexpr size_t arity = 3;
	static_assert(Size >= arity, "");
	elements[0] = x;
	elements[1] = y;
	elements[2] = z;
	initialize(arity, Size);
}

template<typename Type, size_t Size>
inline Vector<Type, Size>::Vector(Type x, Type y, Type z, Type w) {
	constexpr size_t arity = 4;
	static_assert(Size >= arity, "");
	elements[0] = x;
	elements[1] = y;
	elements[2] = z;
	elements[3] = w;
	initialize(arity, Size);
}

template<typename Type, size_t Size>
inline bool Vector<Type, Size>::operator ==(const Vector<Type, Size>& other) const {
	for (size_t i = 0; i < Size; i++) {
		if (elements[i] != other.elements[i]) {
			return false;
		}
	}
	return true;
}

template<typename Type, size_t Size>
inline bool Vector<Type, Size>::operator !=(const Vector<Type, Size>& other) const {
	return !(*this == other);
}

template<typename Type, size_t Size>
void Vector<Type, Size>::initialize(size_t offset, size_t size) {
	for (size_t i = offset; i < Size; i++) {
		elements[i] = 0.0;
	}
}

template<typename Type, size_t Size>
inline double& Vector<Type, Size>::operator [](int index) {
	return elements[index];
}

template<typename Type, size_t Size>
inline const double& Vector<Type, Size>::operator [](int index) const {
	return elements[index];
}

template<typename Type, size_t Size>
inline Vector<Type, Size>& Vector<Type,Size>::operator+=(const Vector<Type, Size>& other) {
	for (size_t i = 0; i < Size; i++) {
		elements[i] += other.elements[i];
	}
	return *this;
}

template<typename Type, size_t Size>
inline Vector<Type, Size>& Vector<Type,Size>::operator-=(const Vector<Type, Size>& other) {
	for (size_t i = 0; i < Size; i++) {
		elements[i] -= other.elements[i];
	}
	return *this;
}

template<typename Type, size_t Size>
inline Vector<Type, Size> operator+(const Vector<Type, Size>& lhs, const Vector<Type, Size>& rhs) {
	Vector<Type, Size> result;
	for (size_t i = 0; i < Size; i++) {
		result[i] = lhs[i] + rhs[i];
	}
	return result;
}

template<typename Type, size_t Size>
inline Vector<Type, Size> operator-(const Vector<Type, Size>& lhs, const Vector<Type, Size>& rhs) {
	Vector<Type, Size> result;
	for (size_t i = 0; i < Size; i++) {
		result[i] = lhs[i] - rhs[i];
	}
	return result;
}

template<typename Type, size_t Size>
inline Vector<Type, Size> operator*(const Vector<Type, Size>& lhs, Type rhs) {
	Vector<Type, Size> result;
	for (size_t i = 0; i < Size; i++) {
		result[i] = lhs[i] * rhs;
	}
	return result;
}

template<typename Type, size_t Size>
inline Vector<Type, Size> operator*(Type lhs, const Vector<Type, Size>& rhs) {
	return rhs * lhs;
}

template<typename Type, size_t Size>
inline Type dot(const Vector<Type, Size>& lhs, const Vector<Type, Size>& rhs) {
	Type result = 0.0;
	for (size_t i = 0; i < Size; i++) {
		result += lhs[i] * rhs[i];
	}
	return result;
}

template<typename Type, size_t Size>
inline std::ostream& operator <<(std::ostream& out, Vector<Type, Size>& v) {
	for (size_t i = 0; i < Size; i++) {
		out << v[i] << " ";
	}
	return out;
}

#endif /* VECTOR_H_ */
