#include "main.h"

using namespace std;

int main()
{
	cout << "toto" << endl;

	matrix<double, Dynamic, Dynamic> m(10, 10);
	m.transpose();

	return 0;
}

#define N 200

void gemm(double A[][N], double B[][N], double C[][N]) {
	

}