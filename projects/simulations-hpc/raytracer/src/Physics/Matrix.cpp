/*
** EPITECH PROJECT, 2024
** Matrix.cpp
** File description:
** Matrix
*/

#include "../../include/Physics/Matrix.hpp"
#include "../../include/Physics/Vector.hpp"

template <typename T>
Matrix<T>::Matrix()
{
    _rows = 0;
    _cols = 0;
}

template <typename T>
Matrix<T>::Matrix(int rows, int cols)
{
    _rows = rows;
    _cols = cols;
    _values.resize(rows);
    for (int i = 0; i < rows; i++)
        _values[i].resize(cols);
}

template <typename T>
Matrix<T>::Matrix(const Matrix &matrix)
{
    _rows = matrix._rows;
    _cols = matrix._cols;
    _values = matrix._values;
}

template <typename T>
Matrix<T>::~Matrix() {}

template <typename T>
Matrix<T> Matrix<T>::zeros(int rows, int cols)
{
    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.set(i, j, 0);
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::ones(int rows, int cols)
{
    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.set(i, j, 1);
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::rotation(Vector3d a, Vector3d b)
{
    Matrix result(3, 3);
    double angle = std::acos(a.dot(b) / (a.norm() * b.norm()));
    double c = std::cos(angle);
    double s = std::sin(angle);
    double t = 1 - c;

    result.set(0, 0, t * a.getX() * a.getX() + c);
    result.set(0, 1, t * a.getX() * a.getY() - s * a.getZ());
    result.set(0, 2, t * a.getX() * a.getZ() + s * a.getY());
    result.set(1, 0, t * a.getX() * a.getY() + s * a.getZ());
    result.set(1, 1, t * a.getY() * a.getY() + c);
    result.set(1, 2, t * a.getY() * a.getZ() - s * a.getX());
    result.set(2, 0, t * a.getX() * a.getZ() - s * a.getY());
    result.set(2, 1, t * a.getY() * a.getZ() + s * a.getX());
    result.set(2, 2, t * a.getZ() * a.getZ() + c);
    return result;
}

template <typename T>
void Matrix<T>::set(int row, int col, double value)
{
    if (row < 0 || row >= _rows || col < 0 || col >= _cols)
        return;
    _values[row][col] = value;
}

template <typename T>
double Matrix<T>::get(int row, int col) const
{
    if (row < 0 || row >= _rows || col < 0 || col >= _cols)
        return 0;
    return _values[row][col];
}

template <typename T>
void Matrix<T>::zeros()
{
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _values[i][j] = 0;
}

template <typename T>
void Matrix<T>::ones()
{
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _values[i][j] = 1;
}

template <typename T>
void Matrix<T>::identity()
{
    if (_rows != _cols)
        return;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _values[i][j] = i == j ? 1 : 0;
}

template <typename T>
void Matrix<T>::transpose()
{
    Matrix result(_cols, _rows);

    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            result.set(j, i, _values[i][j]);
    *this = result;
}

template <typename T>
Matrix<T> Matrix<T>::transposed()
{
    Matrix<T> result(_cols, _rows);

    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            result.set(j, i, _values[i][j]);
    return result;
}

template <typename T>
void Matrix<T>::print()
{
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++)
            std::cout << _values[i][j] << " ";
        std::cout << std::endl;
    }
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix &matrix)
{
    _rows = matrix._rows;
    _cols = matrix._cols;
    _values = matrix._values;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &matrix)
{
    Matrix result(_rows, _cols);

    if (_rows != matrix._rows || _cols != matrix._cols)
        return result;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            result.set(i, j, _values[i][j] + matrix.get(i, j));
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &matrix)
{
    Matrix result(_rows, _cols);

    if (_rows != matrix._rows || _cols != matrix._cols)
        return result;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            result.set(i, j, _values[i][j] - matrix.get(i, j));
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &matrix)
{
    Matrix result(_rows, matrix._cols);

    if (_cols != matrix._rows)
        return result;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < matrix._cols; j++)
            for (int k = 0; k < _cols; k++)
                result.set(i, j, result.get(i, j) + _values[i][k] * matrix.get(k, j));
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator%(const Matrix &matrix)
{
    Matrix result(_rows, _cols);

    if (_rows != matrix._rows || _cols != matrix._cols)
        return result;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            result.set(i, j, _values[i][j] * matrix.get(i, j));
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator^(const Matrix &matrix)
{
    Matrix result(_rows, _cols);

    if (_rows != matrix._rows || _cols != matrix._cols)
        return result;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            result.set(i, j, std::pow(_values[i][j], matrix.get(i, j)));
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator|(const Matrix &matrix)
{
    Matrix result(_rows, _cols);

    if (_rows != matrix._rows || _cols != matrix._cols)
        return result;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            result.set(i, j, std::pow(_values[i][j], 1 / matrix.get(i, j)));
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator~()
{
    Matrix result(_rows, _cols);

    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            result.set(i, j, -_values[i][j]);
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator!()
{
    Matrix result(_rows, _cols);

    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            result.set(i, j, 1 / _values[i][j]);
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-()
{
    Matrix result(_rows, _cols);

    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            result.set(i, j, -_values[i][j]);
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator+()
{
    Matrix result(_rows, _cols);

    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            result.set(i, j, _values[i][j]);
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator++()
{
    Matrix result(_rows, _cols);

    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            result.set(i, j, _values[i][j] + 1);
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator--()
{
    Matrix result(_rows, _cols);

    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            result.set(i, j, _values[i][j] - 1);
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator+=(const Matrix &matrix)
{
    if (_rows != matrix._rows || _cols != matrix._cols)
        return *this;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if constexpr (std::is_same_v<T, bool>)
                _values[i][j] = _values[i][j] || matrix.get(i, j);
            else
                _values[i][j] += matrix.get(i, j);
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-=(const Matrix &matrix)
{
    if (_rows != matrix._rows || _cols != matrix._cols)
        return *this;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if constexpr (std::is_same_v<T, bool>)
                _values[i][j] = _values[i][j] && !matrix.get(i, j);
            else
                _values[i][j] -= matrix.get(i, j);
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*=(const Matrix &matrix)
{
    if (_cols != matrix._rows)
        return *this;
    Matrix result(_rows, matrix._cols);

    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < matrix._cols; j++)
            for (int k = 0; k < _cols; k++)
                result.set(i, j, result.get(i, j) + _values[i][k] * matrix.get(k, j));
    *this = result;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator%=(const Matrix &matrix)
{
    if (_rows != matrix._rows || _cols != matrix._cols)
        return *this;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if constexpr (std::is_same_v<T, bool>)
                _values[i][j] = _values[i][j] && matrix.get(i, j);
            else
                _values[i][j] *= matrix.get(i, j);
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator^=(const Matrix &matrix)
{
    if (_rows != matrix._rows || _cols != matrix._cols)
        return *this;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _values[i][j] = std::pow(_values[i][j], matrix.get(i, j));
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator|=(const Matrix &matrix)
{
    if (_rows != matrix._rows || _cols != matrix._cols)
        return *this;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _values[i][j] = std::pow(_values[i][j], 1 / matrix.get(i, j));
    return *this;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix &matrix)
{
    if (_rows != matrix._rows || _cols != matrix._cols)
        return false;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_values[i][j] != matrix.get(i, j))
                return false;
    return true;
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix &matrix)
{
    return !(*this == matrix);
}

template <typename T>
bool Matrix<T>::operator<(const Matrix &matrix)
{
    if (_rows != matrix._rows || _cols != matrix._cols)
        return false;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_values[i][j] >= matrix.get(i, j))
                return false;
    return true;
}

template <typename T>
bool Matrix<T>::operator>(const Matrix &matrix)
{
    if (_rows != matrix._rows || _cols != matrix._cols)
        return false;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_values[i][j] <= matrix.get(i, j))
                return false;
    return true;
}

template <typename T>
bool Matrix<T>::operator<=(const Matrix &matrix)
{
    if (_rows != matrix._rows || _cols != matrix._cols)
        return false;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_values[i][j] > matrix.get(i, j))
                return false;
    return true;
}

template <typename T>
bool Matrix<T>::operator>=(const Matrix &matrix)
{
    if (_rows != matrix._rows || _cols != matrix._cols)
        return false;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_values[i][j] < matrix.get(i, j))
                return false;
    return true;
}

template <typename T>
Matrix<T> Matrix<T>::operator()(int row, int col)
{
    Matrix result(_rows - 1, _cols - 1);

    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (i != row && j != col)
                result.set(i < row ? i : i - 1, j < col ? j : j - 1, _values[i][j]);
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator[](int index)
{
    Matrix result(_rows, _cols);

    if (index < 0 || index >= _rows)
        return result;
    for (int i = 0; i < _cols; i++)
        result.set(index, i, _values[index][i]);
    return result;
}

template <typename T>
Matrix<T>::operator double() const
{
    return _values[0][0];
}

template <typename T>
double Matrix<T>::operator()(int row, int col) const
{
    return _values[row][col];
}

template <typename T>
double Matrix<T>::operator[](int index) const
{
    return _values[index][0];
}

template <typename T>
Matrix<T> Matrix<T>::operator=(double value)
{
    _values[0][0] = value;
    return *this;
}