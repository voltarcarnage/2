#include "class.h"
#include "errors.h"

#pragma once

namespace Dialogue{

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
    void dialogueMenu();
    void f1();
    void f2();
    void f3();
    void f4();
    void f5();
}
