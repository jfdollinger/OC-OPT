#pragma once

#include <vector>

#include "misc.h"

template <typename T, int M, int N>
struct matrix_storage {
  T els[M * N];
  
	matrix_storage(const size_t, const size_t) {}

  inline T& operator [](const size_t i) {
    return els[i];
  }
};

static const int Dynamic = -1;

template <typename T>
struct matrix_storage<T, Dynamic, Dynamic> {
  T* els;
  size_t cnt;

	matrix_storage(const size_t m, const size_t n) : els(new T[m * n]) {}
	~matrix_storage() { delete[] els; }

  inline T& operator [](const size_t i) {
    return els[i];
  }
};


template <typename T, int M, int N>
class matrix {

private:
	matrix_storage<T, M, N> storage;

public:
	matrix();
	matrix(size_t m, size_t n);

	void transpose();
  matrix<T, M, N> multiply(const matrix<T, M, N> a, const matrix<T, M, N> b);

	inline T& operator [](const size_t i) { 

  }

	inline T& operator ()(const size_t i, const size_t j) {
		return els[i * M + j];
	}

  inline matrix<T, M, N> operator *(const matrix<T, M, N> b) {
    return multiply(*this, b);
  }

};


#include "algebra.cpp"

