#include "class.h"

namespace Line{

  double Curve::getY(double x) const
  {
    double y  = sqrt((-pow(a,2) * pow(x,2) + 2*a*pow(x,3) + pow(l,2) * pow(x,2) - pow(x,4)) / (pow(a,2) - 2*a*x + pow(x,2)));
    return y;
  }

  double Curve::getDistance(double phi) const
  {
    double r = a/cos(phi * M_PI / 180) + l;
    return std::abs(r);
  }

  double Curve::getRa() const
  {
    double r1 = pow((l + a), 2)/l;
    return r1;
  }

  double Curve::getRc() const
  {
    double r2 = pow((l - a), 2)/l;
    return r2;
  }

  double Curve::getRo() const
  {
    double r3 = l*sqrt(pow(l,2) - pow(a,2))/(2*a);
    return r3;
  }

  double Curve::getSquare() const
  {
    double s = a*sqrt(pow(l,2) - pow(a,2)) - 2*a*l * log((l + sqrt(pow(l,2) - pow(a,2)))/a) + pow(l,2) * acos((a/l) * 180.0 / M_PI);
    return s;
  }

  double Curve::getInflectPoints1() const
  {
    double x = pow(a,2)/pow((-pow(a,3) + sqrt(pow(a,2) * pow(l,4) - 2*pow(a,4)*pow(l,2)) + a * pow(l,2)),1/3) + pow((-pow(a,3) + sqrt(pow(a,2) * pow(l,4) - 2*pow(a,4)*pow(l,2)) + a * pow(l,2)),1/3);
    return x;
  }

  double Curve::getInflectPoints2() const
  {
    double x = -pow(((1 + sqrt(3))*pow(a,2))/(2 * (-pow(a,3) + sqrt(pow(a,2)*pow(l,4) - 2*pow(a,4)*pow(l,2)) + a*pow(l,2))),1/3) - 1/2*(1 - sqrt(3))*pow((-pow(a,3) + sqrt(pow(a,2) * pow(l,4) - 2*pow(a,4)*pow(l,2)) + a * pow(l,2)),1/3);
    return x;
  }

}
