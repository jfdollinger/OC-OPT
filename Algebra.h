#pragma once

#include <vector>

template <typename T>
class vector {
	std::vector<T> els;

	T operator [](size_t i) {
		return els[]
	}
};

template <typename T, int M, int N>
struct matrix_storage {
	matrix_storage(const size_t, const size_t) {}
	T els[M][N];
};

static const int Dynamic = -1;

template <typename T>
struct matrix_storage<T, Dynamic, Dynamic> {
	matrix_storage(const size_t m, const size_t n) : els((T *)new T[m][n]) {}
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
		cout << "toto" << endl;
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
		return els[i][j];
	}


};

