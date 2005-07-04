// Oliver Kullmann, 26.5.2005 (Swansea)

#ifndef LOGICALTESTOBJECTS_847ncVb

#define LOGICALTESTOBJECTS_847ncVb

#include "Logical.hpp"
#include "Logical_Tests.hpp"

namespace OKlib {

  namespace MetaProgramming {

    namespace Metafunction_tests {

      template class Test_True_T<True>;

      template class Test_False_T<False>;

    }
  }

}

#endif
