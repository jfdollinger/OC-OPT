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

  ToyWeight n0(1), n1(3);

  OCWeightedPath<ToyWeight> wp1(n0, r1), wp2(n1, r2), wp3(n1, r3);
  OCWeightedPath<ToyWeight>::setConstraints(ToyWeight::MetricsType(10));
  
  wp1 = wp1 * wp2 * wp3;
  //wp1 = wp1 * wp2;

  std::cout << wp1.toString();

  //ToyWeightedPath p(n);
  

  return 0;
}
