#include "headers/errors.h"

namespace Errors{

    bool exceptions(double x)
    {
      if(std::isnan(x) || std::isinf(x))
          return false;
      return true;
    }
}
