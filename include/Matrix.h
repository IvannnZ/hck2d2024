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
  Matrix(size_t rows, size_t columns) : rows_(rows), columns_(columns) {
    elements_.resize(rows * columns);
  };

  double &operator[](size_t row, size_t column) {
    return elements_[row * columns_ + column];
  }

  double operator[](size_t row, size_t column) const {
    return elements_[row * columns_ + column];
  }

  bool operator==(Matrix matrix) const {
    if (rows_ != matrix.rows_ || columns_ != matrix.columns_) {
      return false;
    }
    for (size_t i = 0; i < rows_; i++) {
      for (size_t j = 0; j < columns_; j++) {
        if (matrix[i, j] != (*this)[i, j]) {
          return false;
        }
      }
    }
    return true;
  };

  Matrix operator*(const Matrix &matrix) const {
    assert(this->rows_ != matrix.columns_);
    Matrix result_matrix(this->rows_, matrix.columns_);
    for (size_t i = 0; i < this->rows_; i++) {
      for (size_t j = 0; j < matrix.columns_; j++) {
        result_matrix[i, j] = 0;
        for (size_t k = 0; k < matrix.rows_; k++) {
          result_matrix[i, j] += (*this)[i, k] * matrix[k, j];
        }
      }
    }
    return result_matrix;
  };

  Matrix operator+(Matrix matrix) const {
    assert(this->rows_ != matrix.rows_ || this->columns_ != matrix.columns_);
    Matrix result_matrix(rows_, columns_);
    for (size_t i = 0; i < rows_; i++) {
      for (size_t j = 0; j < columns_; j++) {
        result_matrix[i, j] = (*this)[i, j] + matrix[i, j];
      }
    }
    return result_matrix;
  };

  double det() const;

  Matrix dotProduct(double lambda) const {
    Matrix MatrixLambda = Matrix(this->rows_, this->columns_);
    for (size_t i = 0; i < rows_; i++) {
      for (size_t j = 0; j < columns_; i++) {
        MatrixLambda[i, j] = (*this)[i, j] * lambda;
      }
    }
    return MatrixLambda;
  };
  size_t rows() const { return rows_; };
  size_t columns() const { return columns_; };
};

} // namespace hck2d2024