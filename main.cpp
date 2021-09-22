#include "class.h"

int main()
{
  while(true)
  {
    int answer;
    Line::show();
    Line::getNum("Select an option: ", answer);
    switch(answer)
    {
      case 0: {
        break;
      }

      case 1: {
        Line::f1();
        continue;
      }

      case 2: {
        Line::f2();
        continue;
      }

      case 3: {
        Line::f3();
        continue;
      }

      case 4: {
        Line::f4();
        continue;
      }

      case 5: {
        Line::f5();
        continue;
      }

      default:{
        std::cout << "There is no such option" << std::endl;
        continue;
      }
    }

    break;
  }
  return 0;
}
