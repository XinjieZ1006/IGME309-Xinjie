#pragma once
#include <iostream>
#include <vector>
#include "Vector.h"
template <typename T>
class Matrix
{
public:
	// constructor
	Matrix(int rows, int cols);
	Matrix(const std::vector<std::vector<T>>& data);
	Matrix<T> operator+(const Matrix<T>& other) const;
	Matrix<T> operator-(const Matrix<T>& other) const;
	Matrix<T> operator*(const Matrix<T>& other) const;
	Vector<T> operator*(const Vector<T>& v) const;
	Matrix<T> operator*(T scalar) const;
	Matrix<T> Transpose() const;
	Matrix<T> Inverse() const;
	Matrix<T> Cofactor(const std::vector<std::vector<T>>& matrix, int row, int col) const;
	T Determinant()const;
	T DeterminantHelper(const std::vector<std::vector<T>>& matrix)const;
	void Print();
private:
	int row, col;
	std::vector<std::vector<T>> data;
};

template<typename T>
inline Matrix<T>::Matrix(int rows, int cols)
{
	row = rows;
	col = cols;
	data.resize(rows, std::vector<T>(cols));
}

template<typename T>
inline Matrix<T>::Matrix(const std::vector<std::vector<T>>& data)
{
	row = data.size();
	col = data[0].size();
	this->data = data;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
{
	Matrix<T> result(row, col);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			result.data[i][j] = data[i][j] + other.data[i][j];
		}
	}
	return result;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const
{
	Matrix<T> result(row, col);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			result.data[i][j] = data[i][j] - other.data[i][j];
		}
	}
	return result;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const
{
	Matrix result(row, other.col);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < other.col; ++j)
		{
			for (int k = 0; k < col; ++k)
			{
				result.data[i][j] += data[i][k] * other.data[k][j];
			}
		}
	}
	return result;
}

template<typename T>
inline Vector<T> Matrix<T>::operator*(const Vector<T>& v) const
{
	return Vector<T>(
		data[0][0] * v.X() + data[0][1] * v.Y() + data[0][2] * v.Z(),
		data[1][0] * v.X() + data[1][1] * v.Y() + data[1][2] * v.Z(),
		data[2][0] * v.X() + data[2][1] * v.Y() + data[2][2] * v.Z()
		);
}

template<typename T>
inline Matrix<T> Matrix<T>::operator*(T scalar) const
{
	Matrix<T> result(row, col);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			result.data[i][j] = data[i][j] * scalar;
		}
	}
	return result;
}

template<typename T>
inline Matrix<T> Matrix<T>::Transpose() const
{
	Matrix<T> result(col, row);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			result.data[j][i] = data[i][j];
		}
	}
	return result;
}

template<typename T>
inline Matrix<T> Matrix<T>::Inverse() const
{
	if (row != col)
	{
		throw std::invalid_argument("Inverse only works for square matrices.");
	}
	T det = Determinant();
	if (det == 0)
	{
		throw std::invalid_argument("Inverse of a singular matrix does not exist.");
	}
	Matrix<T> adj(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Matrix<T> cofactor = Cofactor(data, i, j);
			adj.data[j][i] = std::pow(-1, i+j) * cofactor.DeterminantHelper(cofactor.data); // Transpose cofactor
		}
	}
	return adj * (1 / det);
}

template<typename T>
inline Matrix<T> Matrix<T>::Cofactor(const std::vector<std::vector<T>>& matrix,int row,int col) const
{
	std::vector<std::vector<T>> cofactor;
	for (int i = 0; i < matrix.size(); ++i)
	{
		if (i == row)
		{
			continue;
		}
		std::vector<T> newRow;
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			if (j == col)
			{
				continue;
			}
			newRow.push_back(matrix[i][j]);
		}
		cofactor.push_back(newRow);
	}
	return Matrix<T>(cofactor);
}

template<typename T>
inline T Matrix<T>::Determinant() const
{
	if (row != col)
	{
		throw std::invalid_argument("Determinant only works for square matrices.");
	}
	return(DeterminantHelper(data));

}

template<typename T>
inline T Matrix<T>::DeterminantHelper(const std::vector<std::vector<T>>& matrix) const
{
	if (matrix.size() == 2) // base case for 2x2 matrix
	{
		return(matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
	}
	T det = 0;
	for (int i = 0; i < matrix[0].size(); ++i)
	{
		Matrix<T> cofactor = Cofactor(matrix, 0, i);
		det += std::pow(-1, i) * matrix[0][i] * cofactor.DeterminantHelper(cofactor.data); // get det by finding the cofactors of elements in first row
	}
	return det;
}

template<typename T>
inline void Matrix<T>::Print()
{
	std::cout << std::endl;
	for (auto& i : data)
	{
		for (auto& j : i)
		{
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
}
