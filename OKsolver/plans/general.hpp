// Oliver Kullmann, 10.11.2006 (Swansea)
/* Copyright 2006 - 2007 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Transitional/OKsolver/plans/general.hpp
  \brief Plans for the module containing old OKsolver-etc-code


  \todo Submodule "Experimental 200102" DONE
  <ul>
   <li> DONE AllgKlassen200102/VarSet.hpp goes to
   Satisfiability/ProblemInstances/Variables. </li>
   <li> DONE AllgKlassen200102/Literal.hpp goes to
   Satisfiability/ProblemInstances/Literals. </li>
   <li> DONE AllgKlassen200102/Clause.hpp goes to
   Satisfiability/ProblemInstances/Clauses. </li>
   <li> DONE AllgKlassen200102/ClauseSet.hpp goes to
   Satisfiability/ProblemInstances/ClauseSets. </li>
   <li> DONE AllgKlassen200102/PartAssign.hpp goes to
   Satisfiability/Assignments. </li>
   <li> DONE AllgKlassen200102/DLL_Algorithms.hpp and
   AllgKlassen200102/DLL_Algorithms.cpp go to
   Satisfiability/Algorithms/Backtracking. </li>
   <li> DONE AllgKlassen200102/DLL-Implementations.cpp goes to
   Satisfiability/Solvers/DLL. It needs to be linked with
   DLL_Algorithms.o and Kommandozeile.o.
   </li>
  </ul>


  \todo Submodule "Experimental 200203"
  <ul>
   <li> AllgKlassen200203/Variables.hpp goes to
   Satisfiability/ProblemInstances/Variables. </li>
   <li> AllgKlassen200203/SetsOfVariables.hpp goes to
   Satisfiability/ProblemInstances/Variables. </li>
   <li> AllgKlassen200203/Concepts_Variables.hpp goes to
   Satisfiability/ProblemInstances/Variables. </li>
   <li> AllgKlassen200203/Tests_Variables.hpp goes to
   Satisfiability/ProblemInstances/Variables. </li>
   <li> AllgKlassen200203/Traits_Variables.hpp goes to
   Satisfiability/ProblemInstances/Variables. </li>
   <li> AllgKlassen200203/Domains.hpp goes to
   Satisfiability/ProblemInstances/Literals
   (or perhaps ProblemInstances/Domains ?). </li>
   <li> AllgKlassen200203/Literal.hpp goes to
   Satisfiability/ProblemInstances/Literals.hpp. </li>
   <li> AllgKlassen200203/Values goes to
   Satisfiability/ProblemInstances/Literals.hpp. </li>
   <li> AllgKlassen200203/Clauses.hpp goes to
   Satisfiability/ProblemInstances/Clauses. </li>
   <li> AllgKlassen200203/LitSets.hpp goes to
   Satisfiability/ProblemInstances/Clauses. </li>
   <li> AllgKlassen200203/ClauseSets.hpp goes to
   Satisfiability/ProblemInstances/ClauseSets. </li>
   <li> AllgKlassen200203/PartialAssignments.hpp goes to
   Satisfiability/Assignments. </li>
   <li> AllgKlassen200203/Auxiliary.hpp goes to
   Satisfiability/ProblemInstances or perhaps Satisfiability/Interfaces. </li>
   <li> AllgKlassen200203/AlgebraicStructures.hpp goes to
   Structures/Algebra. </li>
   <li> AllgKlassen200203/Concepts goes to
   Satisfiability/Interfaces. </li>
   <li> AllgKlassen200203/InputCls.hpp goes to
   Satisfiability/Interfaces. </li>
   <li> AllgKlassen200203/OutputCls.hpp goes to
   Satisfiability/Interfaces. </li>
   <li> AllgKlassen200203/Concepts_General.hpp goes to
   Concepts. </li>
   <li> AllgKlassen200203/ConceptDefinitions goes to
   Concepts. </li>
   <li> AllgKlassen200203/Test.cpp is distribued over
   the appropriate modules. </li>
   <li> AllgKlassen200203/Tests_General.hpp goes to TestSystem. </li>
   <li> AllgKlassen200203/Traits_General.hpp goes to the appropriate
   traits-directory. </li>
   <li> AllgKlassen200203/TransformationsBiclique.hpp goes to
   Satisfiability/Transformers/Generators.
   We will also have a module for computing biclique-partitions ---
   perhaps it should go there. </li>
   <li> AllgKlassen200203/UnitPropagation goes to
   Satisfiability/Reductions/UnitClausePropagation. </li>
   <li> AllgKlassen200203/makefile will be replaced. </li>
  </ul>

  
  \todo Submodule "Transformationen" : All content should be transferred
  (that is, what is still relevant). DONE (moved to
  Satisfiability/Transformers/Generators)


  \todo Submodule "Graphen" : It seems there is nothing of real interest in here anymore.
  DONE (transferred to Combinatorics/Graphs/BoostSupport)


  \todo Submodule "Generator" must be transferred to module RandomGenerator. DONE


  \todo Submodule "Hilfsprogramme" should be inspected, what the compilation-tool there
   is doing, so that interesting functions can be incorporated into the build system.
   DONE (transferred to module Satisfiability/Solvers/OKsolver)


  \todo Submodule "Quellen" should be transferred to module OKsolver_1_0. DONE
  (moved to module Satisfiability/Solvers/OKsolver)


  \todo Submodule "Datenbank" has been transferred to module OKdatabase,
  and should sooner or later be removed. DONE

*/
