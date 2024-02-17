#pragma once

#include <cassert>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <process.h>
#include <vector>
namespace hck2d2024 {


class Matrix {
private:
    size_t rows_;
    size_t columns_;
    std::vector<double> elements_;

public:
    Matrix(size_t rows, size_t columns) 
    : rows_(rows), columns_(columns) {
        elements_.resize(rows * columns);
    };
    

    double &operator[](size_t row, size_t column) {
        return elements_[row * columns_ + column];
    }

    double operator[](size_t row, size_t column) const {
        return elements_[row * columns_ + column];;
    }
    
    //Matrix matr(2,2) = [1,2,3,4];


    bool operator==(Matrix matrix) const {
        if (this->rows_ != matrix.rows_ || this->columns_ != matrix.columns_){
            return false;
        }
        for (int i = 0; i<rows_; i++){
            for (int j = 0; j<columns_; j++){
                if (matrix[i, j] != (*this)[i,j]){
                    return false;
                }
            }
        }
        return true;
    };

    Matrix operator*(Matrix matrix)const{
        assert(this->rows_ != matrix.columns_);// разваливаемся же?
        Matrix result_matrix(this->rows_, matrix.columns_);
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < matrix.columns_; j++) {
                *result_matrix[i,j] = 0;
                for (int k = 0; k < matrix.rows_; k++) {
                    *result_matrix[i,j] += *(*this)[i,k] * *matrix[k,j];
                }
            }
        }
        return result_matrix;
    };

    Matrix operator+(Matrix matrix)const{
        assert(this->rows_ != matrix.rows_ || this->columns_ != matrix.columns_);// разваливаемся же?
        Matrix result_matrix(rows_, columns_);
        for (int i = 0; i < rows_; i++){
            for (int j = 0; j<columns_; j++){
                *result_matrix[i,j] = *(*this)[i,j] + *matrix[i,j];
            }
        }
        return result_matrix;
    };

    double det()const;

    Matrix multiplyScalar (double lambda)const{
        Matrix MatrixLambda = Matrix(this->rows_, this->columns_);
        for(int i =0; i< rows_;i++){
            for(int j = 0; j < columns_; i++ ){
                *MatrixLambda[i,j] =  *(*this)[i,j] * lambda; 
            }
        }
        return MatrixLambda;
    };
    size_t Rows() const{
        return rows_;
    };
    size_t Columns_() const{
        return rows_;
    };


};






}