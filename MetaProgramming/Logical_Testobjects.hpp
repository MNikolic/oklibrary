// Oliver Kullmann, 26.5.2005 (Swansea)

/*!
  \file MetaProgramming/Logical_Testobjects.hpp

  \todo Likely the special namespace Metafunction_tests should be eliminated.
*/

#ifndef LOGICALTESTOBJECTS_847ncVb
#define LOGICALTESTOBJECTS_847ncVb

#include <Transitional/MetaProgramming/Logical.hpp>
#include <Transitional/MetaProgramming/Logical_Tests.hpp>

namespace OKlib {

  namespace MetaProgramming {

      template class Test_True_T<True>;

      template class Test_False_T<False>;

  }

}

#endif
