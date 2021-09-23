#include <iostream>
#include <cmath>

#pragma once

namespace Line{

  class Curve{
    private:
      double a,l;
    public:
       Curve(double a0, double l0) : a(a0), l(l0) {}
       double getY(double x) const;
       double getDistance(double phi) const;
       double getRa() const;
       double getRc() const;
       double getRo() const;
       double getSquare() const;
       double getInflectPoints1() const;
       double getInflectPoints2() const;

    };

}
