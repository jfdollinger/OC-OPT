#include <iostream>
#include "main.h"
//#include "oc.h"

using namespace std;

int main()
{
  /*
    size_t t = 10;
  	matrix<double, Dynamic, Dynamic> m(t, t);
  	m.transpose();
  */
  OCUnitPath r1(1), r2(2);
  OCPath l;

  l = l * r1 * r2;

  cout << l.hops() << endl;

  for(auto el : l.getPath()) {
    cout << el << endl;
  }
  
  //Weight<int, int> *w = new Weight<int, int>(1, 2);
  ToyWeight n(1, 2);
  n.update(3, 4);
  
	return 0;
}
