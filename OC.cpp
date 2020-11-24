// OC.cpp : définit le point d'entrée de l'application.
//

#include "OC.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;

	matrix<double, Dynamic, Dynamic> m(10, 10);
	m.transpose();

	return 0;
}

#define N 200

void gemm(double A[][N], double B[][N], double C[][N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {

			}
		}
	}

}