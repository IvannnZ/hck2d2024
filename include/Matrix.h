#pragma once

#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <process.h>
#include <vector>
namespace hck2d2024 {


class Matrix {

public:

Matrix(size_t rows, size_t columns){
        rows_ = rows;
        columns_ = columns;

        *arr = new double[rows * columns];
    };

    ~Matrix(){
        delete [] *arr;
    }
    
    double* operator[](size_t rows, size_t columns)const{
        return arr[rows_ * rows + columns];
    };


    bool operator==(Matrix matrix)const{
        if (this->rows_ != matrix.rows_ || this->columns_ != matrix.columns_){
            return false;
        }
        for (int i = 0; i<rows_; i++){
            for (int j = 0; j<columns_; j++){
                if (*matrix[i, j] != *(*this)[i,j]){
                    return false;
                }
            }
        }
        return true;
    };

    Matrix operator*(Matrix mat)const;

    Matrix operator+(Matrix mat)const{};

    double determinant()const;

    Matrix multiplyScalar (double num)const{
        
    };

    


private:
    size_t rows_;
    size_t columns_;
    double *arr[];


};






}