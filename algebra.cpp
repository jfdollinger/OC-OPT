#include "algebra.h"

#define min(a, b) ((a < b) ? (a) : (b))

void dmm(int P, int M) {
	int i, j, k, ii, jj, kk;

	int A[M][M], B[M][M], C[M][M];

#pragma omp parallel for
	for (i = 0; i < M; ++i) {
		for (j = 0; j < M; ++j) {
			C[i][j] = 0;
		}
	}

#pragma omp parallel for
	for (i = 0; i < M; i += 32) {
		for (k = 0; k < M; k += 32) {
			for (j = 0; j < M; j += 32) {
				for (ii = i; ii < min(i + 32, M); ++ii) {
					for (kk = k; kk < min(k + 32, M); ++kk) {
						for (jj = j; jj < min(j + 32, M); ++jj) {
							C[ii][jj] += A[ii][kk] * B[kk][jj];
						}
					}
				}
			}
		}
	}
}

template <typename T, int M, int N> matrix<T, M, N>::matrix() {
}

template <typename T, int M, int N>
matrix<T, M, N>::matrix(size_t m, size_t n) : storage(m, n) {
}

template <typename T, int M, int N> void matrix<T, M, N>::transpose() {
	matrix<T, M, N> m = *this;

	for (int i = 0; i < M; ++i) {
		for (int j = i + 1; j < N; ++j) {
			swap<T>(m(i, j), m(j, i));
		}
	}
}

template <typename T, int M, int N>
matrix<T, M, N>
matrix<T, M, N>::multiply(const matrix<T, M, N> a, const matrix<T, M, N> b) {
	matrix<T, M, N> c = matrix<T, M, N>();

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
			}
		}
	}
}
