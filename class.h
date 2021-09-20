#include <iostream>
#include <cmath>

#pragma once

namespace Line{
  
  class Curve{
    private:
      double a,l;
    public:
       Curve& setParam(double a0, double l0) : a(a0), l(l0) {return *this}
    };
}
