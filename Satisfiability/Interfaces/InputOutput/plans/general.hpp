// Matthew Henderson, 25.1.2006 (Swansea)
/* Copyright 2006 - 2007 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Interfaces/InputOutput/plans/general.hpp
  \brief Plans for the module on SAT-related input/output.


  \todo InputOutput/ExtendedToStrictDimacs.cpp
  <ul>
   <li> Really handle extended Dimacs format, using a policy for
   OKlib::InputOutput::StandardDIMACSInput.
   <ul>
    <li> We should have an option for adding to the comment-section
    the map index -> original name. </li>
    <li> This map should be produced by the CLSAdaptor, and a standard
    format is needed, so that it can be extracted by some tool. </li>
    <li> Should we have a command-line option to turn on extended Dimacs
    format? Seems useless: turn it always on (this can handle also standard
    Dimacs input). DONE </li>
   </ul>
   </li>
   <li> The parameter-values should be the correct ones, not the original
   ones. </li>
   <li> We should add a comment-line (optionally) for the original
   file-name, for the original parameter values, and if some cleaning
   happened (tautological clauses or repeated literals), then these
   numbers are also stated. </li>
   <li> Complete doxygen-documentation. </li>
   <li> Write docus:
    <ol>
     <li> The output is cleaned of tautological clauses and repeated
     literals, and the output of clauses is sorted according to natural
     order for integers. </li>
    </ol>
   </li>
   <li> Use Messages. </li>
   <li> Use ProgramOptions. </li>
  </ul>


  \todo Rewrite code for the new namespaces.


  \todo Update:
  Get an overview on the current state of the module, create new
  plans-files for the sub-modules, move the todo's to there, update
  the doxygen-documentation.
  <ul>
   <li> InputOutput/ClauseSetAdaptors.hpp : </li>
   <li> InputOutput/Exceptions.hpp : </li>
   <li> InputOutput/ExtendedDimacsStatistics.cpp : </li>
   <li> InputOutput/ExtendedToStrictDimacs.cpp : DONE </li>
   <li> InputOutput/Dimacs.hpp : DONE </li>
  </ul>


  \todo See Transitional/Satisfiability/ProofSystems/DPv/Input_output.hpp


  \todo Move to the new test system.


  \todo Complete the tests.


  \todo Write docus.


  \todo Write demos.


  \todo Complete the functionality.


  \todo Move InputOutput/ExtendedToStrictDimacs.cpp to sub-directory
   apps, once buildsystem is ready.


  \todo Input and output of partial assignments.

*/

/*!
  \namespace OKlib::Satisfiability::Interfaces::InputOutput
  \brief Components for SAT-related input/output

  Alias "InO".
*/

namespace OKlib {
  namespace Satisfiability {
    namespace Interfaces {
      namespace InputOutput {
      }
      namespace InO = InputOutput;
    }
  }
}

