#include "main.h"
#include <iostream>
//#include "oc.h"

using namespace std;

int main() {
	/*
	  size_t t = 10;
	  matrix<double, Dynamic, Dynamic> m(t, t);
	  m.transpose();
	*/
	OCPath l, r1(1), r2(2), r3(5);

	l = r1 * r3 * r2;
  vector<nodeType> t = r1.getPath();

  for (auto el : l.getPath()) {
	  cout << el << endl;
  }

  ToyWeight n(1);

  OCWeightedPath<ToyWeight> wp1(n, r1), wp2(n, r2);
  wp1 * wp2;

  //ToyWeightedPath p(n);

  return 0;
}
