#pragma once

#include "oc_wp.h"

#include <iostream>
#include <tuple>

using namespace std;
using std::get;
using std::tuple;

//#include "algebra.h"

// TODO: Référencez ici les en-têtes supplémentaires nécessaires à votre
// programme.

class ToyWeight : public AbstractOCWeight<ToyWeight, int> {
public:
  ToyWeight() : AbstractOCWeight<ToyWeight, int>() {
    
  }

	ToyWeight(int a) : AbstractOCWeight<ToyWeight, int>(a) {
		// OCWeight<int, int>::constraints = NULL;
	}

	ToyWeight operator*(ToyWeight &right) {
    return ToyWeight(get<0>(weight) + get<0>(right.weight));
	}

  bool operator<=(tuple<int> &right) {
    return true;
  }
};

/*class ToyWeightedPath : OCWeightedPath<int, int> {
public:
	ToyWeightedPath(OCPath *p, ToyWeight *w) : OCWeightedPath(p, w) {
	}
};*/