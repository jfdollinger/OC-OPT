#include "algebra.h"

template <typename T, int M, int N>
matrix<T, M, N>::matrix() {

}

template <typename T, int M, int N>
matrix<T, M, N>::matrix(size_t m, size_t n) : storage(m, n) {

}

template <typename T, int M, int N>
void matrix<T, M, N>::transpose() {
  matrix<T, M, N> m = *this;
  
  for(int i = 0; i < M; ++i) {
    for(int j = i + 1; j < N; ++j) {
      swap<T>(m(i, j), m(j, i));
    }
  }
}

template <typename T, int M, int N>
matrix<T, M, N> matrix<T, M, N>::multiply(const matrix<T, M, N> a, const matrix<T, M, N> b) {
  matrix<T, M, N> c = matrix<T, M, N>();
  
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {

      }
    }
  }
}


 