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

    template <class T>

    T getNum(const char *msg, T &a)
    {
      std::cout << msg;
      std::cin >> a;
      while(!std::cin.good())
      {
        std::cin.clear();
        std::cin.ignore(/*std::numeric_limits<std::streamsize>::max()*/ 1000,'\n');
        std::cout << "\nInvalid value\n" << std::endl;
        std::cout << msg;
        std::cin >> a;
      }

      return a;
    }

    void show();
    void f1();
    void f2();
    void f3();
    void f4();
    void f5();
}
