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

  
  ToyWeight::setConstraints(new ToyWeight::ConstraintsType(0, 0));

  ToyWeight n(1, 2);
  n.update(3, 4);

  //ToyWeightedPath p(n);

  return 0;
}
