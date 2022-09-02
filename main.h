#pragma once

#include <iostream>
#include <tuple>
#include "oc.h"

using std::tuple;
using std::get;

//#include "algebra.h"


// TODO: Référencez ici les en-têtes supplémentaires nécessaires à votre programme.


class ToyWeight : OCWeight<int, int> {
public:
  ToyWeight(int a, int b) : OCWeight<int, int>(a, b) { }

  void update(int a, int b) {
    std::get<0>(args) = std::get<0>(args) + a;
    std::get<1>(args) = std::get<1>(args) + a;
  }
};