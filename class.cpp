#include "class.h"

namespace Line{

  double Curve::getY(double x) const
  {
    double y = (x/(x-a)) * sqrt(pow(l,2) - pow((x - a),2));

    if(x != a)
    {
      return y;
    }
    else
      std::cout << "Undefined" << std::endl;
    return y;
  }


  double Curve::getDistance(double phi) const
  {
    double r = a/cos(phi * M_PI / 180) + l;
    return std::abs(r);
  }

  double Curve::getRa() const
  {
    if(l){
      double r1 = pow((l + a), 2)/l;
      return r1;
    }
    else{
      std::cout << "For the given values of the parameter l, this radius is not defined." << std::endl;
      return -1;
    }
  }

  double Curve::getRc() const
  {
    if(l){
      double r2 = pow((l - a), 2)/l;
      return r2;
    }
    else{
      std::cout << "\nFor the given values of the parameter l, this radius is not defined. " << std::endl;
      return -1;
    }
  }

  double Curve::getRo() const
  {
    if(a){
      double r3 = l*sqrt(pow(l,2) - pow(a,2))/(2*a);
      return r3;
    }
    else{
      std::cout << "\nFor the given values of the parameter a, this radius is not defined. " << std::endl;
      return -1;
    }
  }

  double Curve::getSquare() const
  {
    if(l > a && a){
      double s = a*sqrt(pow(l,2) - pow(a,2)) - 2*a*l * log((l + sqrt(pow(l,2) - pow(a,2)))/a) + pow(l,2) * acos((a/l) * 180.0 / M_PI);
      return s;
    }
    else
      return 0;
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

  void f1()
  {
    double a,l,x;
    Line::getNum("Enter parameter a: ", a);
    Line::getNum("Enter parameter l: ", l);
    Line::Curve point(a,l);
    Line::getNum("Enter x: ", x);
    std::cout << "\ny(" << x << ") = " << point.getY(x) << std::endl;
  }

  void f2()
  {
    double a,l,phi;
    Line::getNum("Enter parameter a: ", a);
    Line::getNum("Enter parameter l: ", l);
    Line::Curve point(a,l);
    Line::getNum("Enter phi: ", phi);
    std::cout << "\nr(" << phi << ") = " << point.getDistance(phi) << std::endl;
  }

  void f3()
  {
    double a,l,ra,rc,ro;
    Line::getNum("Enter parameter a: ", a);
    Line::getNum("Enter parameter l: ", l);
    Line::Curve point(a,l);
    ra = point.getRa();
    rc = point.getRc();
    ro = point.getRo();
    std::cout << "1 point is: " << ra << "\n" << "2 point is: " << rc << "\n" << "3 point is: " << ro << std::endl;
  }

  void f4()
  {
    double a,l;
    Line::getNum("Enter parameter a: ", a);
    Line::getNum("Enter parameter l: ", l);
    Line::Curve point(a,l);
    if(point.getSquare())
      std::cout << "\nS = " << point.getSquare() << std::endl;
    else
      std::cout << "\nAt these values of the parameters the loop is not formed" << std::endl;
  }

  void f5()
  {
    double a,l;
    Line::getNum("Enter parameter a: ", a);
    Line::getNum("Enter parameter l: ", l);
    Line::Curve point(a,l);
    if(l/a > 1)
    {
      double x = point.getInflectPoints1();
      double y = (x/(x-a)) * sqrt(pow(l,2) - pow((x - a),2));
      std::cout << "The point is: " << "("<< x << "," << y << ")" << std::endl;
    }
    else if(l/a == 1)
    {
      double x = point.getInflectPoints1();
      double y = (x/(x-a)) * sqrt(pow(l,2) - pow((x - a),2));
      double y1 = (-x/(-x-a)) * sqrt(pow(l,2) - pow((-x - a),2));
      std::cout << "The point is:\n" << "("<< x << "," << y << ");\n" << "("<< -x << "," << y1 << ");\n" << "("<< 0 << "," << 0 << ");" << std::endl;
    }
    else if(l/a < 1)
    {
      double x = point.getInflectPoints1();
      double x1 = point.getInflectPoints2();
      double y = (x/(x-a)) * sqrt(pow(l,2) - pow((x - a),2));
      double y1 = (x1/(x1-a)) * sqrt(pow(l,2) - pow((x1 - a),2));
      std::cout << "The point is:\n" << "("<< x << "," << y << ");\n" << "("<< x1 << "," << y1 << ");\n" << std::endl;
    }
  }

  void show()
  {
    const char *msg[8] = {"\n",
                          "1) Get y(x)",
                          "2) Get r(phi)",
                          "3) Get the radius of curvature at feature points",
                          "4) Get the loop area",
                          "5) Get the inflection points of the conchoid",
                          "0) Exit",
                          "\n"
                        };
    for(int i = 0; i < 8; i++)
      std::cout << msg[i] << std::endl;
  }

}
