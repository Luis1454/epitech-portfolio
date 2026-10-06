/*
** EPITECH PROJECT, 2024
** Matrix.hpp
** File description:
** Matrix
*/

#ifndef MATRIX_HPP_
#define MATRIX_HPP_
    #include <cmath>
    #include <iostream>
    #include <climits>
    #include <vector>

class Vector3d;

template <typename T>
class Matrix {
    public:
        Matrix();
        Matrix(int rows, int cols);
        Matrix(const Matrix &matrix);
        ~Matrix();

        static Matrix<T> zeros(int rows, int cols);
        static Matrix<T> ones(int rows, int cols);
        static Matrix<T> rotation(Vector3d a, Vector3d b);

        void set(int row, int col, double value);
        double get(int row, int col) const;
        
        void print();

        void zeros();
        void ones();

        void identity();

        void transpose();
        void inverse();
        void adjoint();
        double determinant();
        double determinant(int rows, int cols);
        double determinant(Matrix<T> matrix);

        Matrix<T> transposed();

        Matrix<T> &operator=(const Matrix &matrix);
        Matrix<T> operator+(const Matrix &matrix);
        Matrix<T> operator-(const Matrix &matrix);
        Matrix<T> operator*(const Matrix &matrix);
        Matrix<T> operator%(const Matrix &matrix);
        Matrix<T> operator^(const Matrix &matrix);
        Matrix<T> operator|(const Matrix &matrix);
        Matrix<T> operator~();
        Matrix<T> operator!();
        Matrix<T> operator-();
        Matrix<T> operator+();
        Matrix<T> operator++();
        Matrix<T> operator--();
        Matrix<T> operator+=(const Matrix &matrix);
        Matrix<T> operator-=(const Matrix &matrix);
        Matrix<T> operator*=(const Matrix &matrix);
        Matrix<T> operator%=(const Matrix &matrix);
        Matrix<T> operator^=(const Matrix &matrix);
        Matrix<T> operator|=(const Matrix &matrix);

        operator double() const;

        bool operator==(const Matrix &matrix);
        bool operator!=(const Matrix &matrix);
        bool operator<(const Matrix &matrix);
        bool operator>(const Matrix &matrix);
        bool operator<=(const Matrix &matrix);
        bool operator>=(const Matrix &matrix);
        Matrix<T> operator()(int row, int col);
        Matrix<T> operator[](int index);

        double operator()(int row, int col) const;
        double operator[](int index) const;

        Matrix<T> operator=(double value);

    private:
        int _rows;
        int _cols;
        std::vector<std::vector<T>> _values;
};

template class Matrix<double>;
template class Matrix<float>;
template class Matrix<int>;
template class Matrix<char>;
template class Matrix<bool>;

#endif /* !MATRIX_HPP_ */