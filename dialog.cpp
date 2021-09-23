#include "headers/dialog.h"

namespace Dialogue{

  void dialogueMenu()
  {
    while(true)
    {
      int answer;
      show();
      getNum("Select an option: ", answer);
      switch(answer)
      {
        case 0: {
          break;
        }

        case 1: {
          f1();
          continue;
        }

        case 2: {
          f2();
          continue;
        }

        case 3: {
          f3();
          continue;
        }

        case 4: {
          f4();
          continue;
        }

        case 5: {
          f5();
          continue;
        }

        default:{
          std::cout << "There is no such option" << std::endl;
          continue;
        }
      }

      break;
    }
  }

  void f1()
  {
    double a,l,x;
    getNum("Enter parameter a: ", a);
    getNum("Enter parameter l: ", l);
    Line::Curve point(a,l);
    getNum("Enter x: ", x);

    if(Errors::exceptions(point.getY(x)))
      std::cout << "\ny1(" << x << ") = " << point.getY(x) << "\ny2(" << x << ") = " << -point.getY(x) << std::endl;
    else
      std::cout << "\ny(" << x << ") is Undefined" << std::endl;
  }

  void f2()
  {
    double a,l,phi;
    getNum("Enter parameter a: ", a);
    getNum("Enter parameter l: ", l);
    Line::Curve point(a,l);
    getNum("Enter phi: ", phi);

    if(Errors::exceptions(point.getDistance(phi)))
      std::cout << "\nr(" << phi << ") = " << point.getDistance(phi) << std::endl;
    else
      std::cout << "\nr(" << phi << ") is Undefined" << std::endl;
  }

  void f3()
  {
    double a,l;

    getNum("Enter parameter a: ", a);
    getNum("Enter parameter l: ", l);
    Line::Curve point(a,l);

    if(!Errors::exceptions(point.getRa()))
      std::cout << "\n1 point is Undefined" << std::endl;

    if(!Errors::exceptions(point.getRc()))
      std::cout << "\n2 point is Undefined" << std::endl;

    if(!Errors::exceptions(point.getRo()))
      std::cout << "\n3 point is Undefined" << std::endl;

    if(l && a)
      std::cout << "\n1 point is: " << point.getRa() << "\n2 point is: " << point.getRc() << "\n3 point is: " << point.getRo() << std::endl;
  }

  void f4()
  {
    double a,l;
    getNum("Enter parameter a: ", a);
    getNum("Enter parameter l: ", l);
    Line::Curve point(a,l);
    if(Errors::exceptions(point.getSquare()))
      std::cout << "\nS = " << point.getSquare() << std::endl;
    else
      std::cout << "\nS is Undefined" << std::endl;
  }

  void f5()
  {
    double a,l;
    getNum("Enter parameter a: ", a);
    getNum("Enter parameter l: ", l);
    Line::Curve point(a,l);
    if(l/a > 1)
    {
      double x = point.getInflectPoints1();
      double y = (x/(x-a)) * sqrt(pow(l,2) - pow((x - a),2));
      if(y && Errors::exceptions(point.getInflectPoints1()))
        std::cout << "\nThe point is: " << "("<< x << "," << y << ")" << std::endl;
      else
        std::cout << "\nThe point is Undefined" << std::endl;
    }
    else if(l/a == 1)
    {
      double x = point.getInflectPoints1();
      double y = (x/(x-a)) * sqrt(pow(l,2) - pow((x - a),2));
      double y1 = (-x/(-x-a)) * sqrt(pow(l,2) - pow((-x - a),2));
      if(y && y1 && Errors::exceptions(point.getInflectPoints1()))
        std::cout << "The point is:\n" << "("<< x << "," << y << ");\n" << "("<< -x << "," << y1 << ");\n" << "("<< 0 << "," << 0 << ");" << std::endl;
      else
        std::cout << "\nThe point is Undefined" << std::endl;
    }
    else if(l/a < 1)
    {
      double x = point.getInflectPoints1();
      double x1 = point.getInflectPoints2();
      double y = (x/(x-a)) * sqrt(pow(l,2) - pow((x - a),2));
      double y1 = (x1/(x1-a)) * sqrt(pow(l,2) - pow((x1 - a),2));
      if(y && y1 && Errors::exceptions(point.getInflectPoints1()) && Errors::exceptions(point.getInflectPoints2()))
        std::cout << "The point is:\n" << "("<< x << "," << y << ");\n" << "("<< x1 << "," << y1 << ");\n" << std::endl;
      else
        std::cout << "\nThe point is Undefined" << std::endl;
    }
  }

  void show()
  {
    const char *msg[8] = {"\nMenu:",
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
