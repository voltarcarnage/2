#include "headers/class.h"

namespace Line{

  double Curve::getY(double x) const { return sqrt((-pow(a,2) * pow(x,2) + 2*a*pow(x,3) + pow(l,2) * pow(x,2) - pow(x,4)) / (pow(a,2) - 2*a*x + pow(x,2))); }

  double Curve::getDistance(double phi) const { return  std::abs(a/cos(phi * M_PI / 180) + l); }

  double Curve::getRa() const { return pow((l + a), 2)/l; }

  double Curve::getRc() const { return pow((l - a), 2)/l; }

  double Curve::getRo() const { return l*sqrt(pow(l,2) - pow(a,2))/(2*a); }

  double Curve::getSquare() const { return a*sqrt(pow(l,2) - pow(a,2)) - 2*a*l * log((l + sqrt(pow(l,2) - pow(a,2)))/a) + pow(l,2) * acos((a/l) * 180.0 / M_PI); }

  double Curve::getInflectPoints1() const { return pow(a,2)/pow((-pow(a,3) + sqrt(pow(a,2) * pow(l,4) - 2*pow(a,4)*pow(l,2)) + a * pow(l,2)),1/3) + pow((-pow(a,3) + sqrt(pow(a,2) * pow(l,4) - 2*pow(a,4)*pow(l,2)) + a * pow(l,2)),1/3); }

  double Curve::getInflectPoints2() const { return -pow(((1 + sqrt(3))*pow(a,2))/(2 * (-pow(a,3) + sqrt(pow(a,2)*pow(l,4) - 2*pow(a,4)*pow(l,2)) + a*pow(l,2))),1/3) - 1/2*(1 - sqrt(3))*pow((-pow(a,3) + sqrt(pow(a,2) * pow(l,4) - 2*pow(a,4)*pow(l,2)) + a * pow(l,2)),1/3); }

}
