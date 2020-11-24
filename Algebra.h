#pragma once

#include <vector>

template <typename T>
class vector {
	std::vector<T> els;

};

template <typename T, int M, int N>
struct matrix_storage {
	matrix_storage(const size_t, const size_t) {}
	T els[M * N];
};

static const int Dynamic = -1;

template <typename T>
struct matrix_storage<T, Dynamic, Dynamic> {
	matrix_storage(const size_t m, const size_t n) : els(new T[m * n]) {}
	~matrix_storage() { delete[] els; }

	T* els;
};


template <typename T, int M, int N>
class matrix {

private:
	int row;
	int col;

	matrix_storage<T, M, N> storage;

public:
	matrix() {
		
	}

	matrix(int m, int n) : storage(m, n) {

	}

	void transpose() {
		/*for (int i = 0; i < ) {
			for () {

			}
		}*/
	}

	T& operator [](const size_t i) { }

	T& operator ()(const size_t i, const size_t j) {
		return storage.els[i * M + j];
	}

  matrix<T, M, N> operator *() {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {

        }
      }
    }
  }


};

