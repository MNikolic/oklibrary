// Oliver Kullmann, 25.5.2005 (Swansea)

/*!
  \file LibraryBasics.hpp
  \brief The very basic concepts for the library. Every unit where concepts are defined
  and/or checked should include this file. Provides macros OKLIB_MODELS_CONCEPT_REQUIRES
  and OKLIB_MODELS_CONCEPT_TAG for checking whether a class models a concept and
  has the required concept tag.

  Includes boost/concept_check, boost/static_assert, boost/type_traits, and
  ConceptsBase, ConceptsMetafunctions, Basics.
*/
  

#ifndef LIBRARYBASICS_oLkG5675

#define LIBRARYBASICS_oLkG5675

#include <boost/concept_check.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits.hpp>
// This file is guaranteed to include the last three files, so that OKLIB_HAS_CONCEPT_TAG and OKLIB_MODELS_CONCEPT always works.

#include "ConceptsBase.hpp"
#include "ConceptsMetafunctions.hpp"
#include "Basics.hpp"
// This file is guaranteed to include the last three files.

namespace OKlib {

  namespace Concepts {

    /*!
      \class WithConceptTag
      \brief Basic internal concept, requiring the concept tag.
    */

    template <typename T>
    struct WithConceptTag {
      BOOST_STATIC_ASSERT(HasConceptTag<T>::value);
      void constraints() {}
    };
    struct WithConceptTag_tag : virtual ConceptsBase_tag {};

    class WithConceptTag_Archetype {
      WithConceptTag_Archetype();
      WithConceptTag_Archetype(const WithConceptTag_Archetype&);
      WithConceptTag_Archetype& operator=(const WithConceptTag_Archetype&);
      ~WithConceptTag_Archetype();
      struct concept_tag_ : virtual ConceptsBase_tag {};
    public :
      typedef concept_tag_ concept_tag;
    };

    /*!
      \class BasicRequirements
      \brief Root of the concept hierarchy for the library, requiring a concept tag and const correctness.
    */

    template <typename T>
    struct BasicRequirements {
      void constraints() {
        ::boost::function_requires<WithConceptTag<T> >();
        ::boost::function_requires<ConstCorrect<T> >();
      }
    };
    struct BasicRequirements_tag : virtual WithConceptTag_tag, virtual ConstCorrect_tag {};

    class BasicRequirements_Archetype : public WithConceptTag_Archetype {};

    // -------------------------------------------------------------------------------------------------------------------------------

    /*!
      \def OKLIB_MODELS_CONCEPT_REQUIRES
      \brief Use OKLIB_MODELS_CONCEPT_REQUIRES(C, concept) in order to require that
      class C models "concept".

      Used together with OKLIB_MODELS_CONCEPT_TAG.
    */
    
#define OKLIB_MODELS_CONCEPT_REQUIRES(C, concept) ::boost::function_requires<concept<C> >();

    /*!
      \def OKLIB_MODELS_CONCEPT_TAG
      \brief Use OKLIB_MODELS_CONCEPT_TAG(C, concept) in order to require that
      class C has concept tag "concept_tag".

      Used together with OKLIB_MODELS_CONCEPT_REQUIRES
    */

#define OKLIB_MODELS_CONCEPT_TAG(C, concept) BOOST_STATIC_ASSERT((::OKlib::Concepts::IsTagModel< C, concept ## _tag >::value));

  }

}

#endif
