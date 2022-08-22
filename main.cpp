#include "main.h"

using namespace std;

int main()
{
	cout << "toto" << endl;

  size_t t = 10;
	matrix<double, Dynamic, Dynamic> m(t, t);
	m.transpose();

	return 0;
}

#define N 200

void gemm(double A[][N], double B[][N], double C[][N]) {
	

}