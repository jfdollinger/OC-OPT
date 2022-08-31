#include <iostream>
#include "main.h"
#include "oc.h"

using namespace std;

int main()
{
  /*
    size_t t = 10;
  	matrix<double, Dynamic, Dynamic> m(t, t);
  	m.transpose();
  */
  UnitPath r1(1), r2(2);
  Path l;

  l = l * r1 * r2;

  cout << l.getHops() << endl;

  for(auto el : l.getPath()) {
    cout << el << endl;
  }
  

  
	return 0;
}
