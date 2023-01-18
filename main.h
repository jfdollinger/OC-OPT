#pragma once

#include "oc.h"
#include <iostream>
#include <tuple>

using std::get;
using std::tuple;

//#include "algebra.h"

// TODO: Référencez ici les en-têtes supplémentaires nécessaires à votre
// programme.

class ToyWeight : public OCWeight<int, int> {
public:
	ToyWeight(int a, int b) : OCWeight<int, int>(a, b) {
     //OCWeight<int, int>::constraints = NULL;
	}

	void update(int a, int b) {
		std::get<0>(weight) = std::get<0>(weight) + a;
		std::get<1>(weight) = std::get<1>(weight) + b;
	}

	bool check(ConstraintsType &constraints) {
    return std::get<0>(weight) <= std::get<0>(constraints)
      && std::get<1>(weight) <= std::get<1>(constraints);
	}
};

class ToyWeightedPath : OCWeightedPath<int, int> {
public:
	ToyWeightedPath(OCPath *p, ToyWeight *w) : OCWeightedPath(p, w) {
	}
};