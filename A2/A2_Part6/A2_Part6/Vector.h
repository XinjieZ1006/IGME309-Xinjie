#pragma once
#include <iostream>
#include <cmath>
#include <vector>
template <typename T>
class Vector
{
public:
	Vector(T x = 0, T y = 0, T z = 0);

	// arithmetics
	Vector operator + (const Vector& other) const
	{
		return Vector(x + other.x, y + other.y, z + other.z);
	}
	Vector operator - (const Vector& other) const
	{
		return Vector(x - other.x, y - other.y, z - other.z);
	}
	Vector operator * (T scalar) const
	{
		return Vector(x * scalar, y * scalar, z * scalar);
	}
	T X() const
	{
		return x;
	}
	T Y() const
	{
		return y;
	}
	T Z() const
	{
		return z;
	}
	// dot product
	T dot(const Vector& other);
	// cross product
	Vector cross(const Vector& other);
	// normalization
	Vector Normalize();
	void Print();
private:
	T x, y, z;
};

template<typename T>
inline Vector<T>::Vector(T x, T y, T z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template<typename T>
inline T Vector<T>::dot(const Vector& other)
{
	return (x * other.x + y * other.y + z * other.z);
	// a dot b = x1x2 + y1y2 + z1z2
}

template<typename T>
inline Vector<T> Vector<T>::cross(const Vector& other)
{
	return Vector(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
	// s1 = a2b3 - a3b2
	// s2 = a3b1 - a1b3
	// s3 = a1b2 - a2b1
}

template<typename T>
inline Vector<T> Vector<T>::Normalize()
{
	T mag = std::sqrt(x * x + y * y + z * z);
	if (mag == 0)
	{
		std::cout << "cannot normalize a zero vector!" << std::endl;
		return *this; // cannot normalize a zero vector
	}
	return Vector(x / mag, y / mag, z / mag);
}

template<typename T>
inline void Vector<T>::Print()
{
	std::cout <<"\033[31m"<< "x: " << x <<"\033[32m"<< " y: " << y << "\033[34m"<<" z: " << z  << "\033[0m" << std::endl;
}
