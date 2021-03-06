// Oliver Kullmann, 24.7.2005 (Swansea)
/* Copyright 2005 - 2007, 2009 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Satisfiability/ProblemInstances/Clauses/concepts/general.hpp
  \brief Plans for concepts for clauses


  \todo Connections
  <ul>
   <li> See ComputerAlgebra/Satisfiability/Lisp/plans/Clauses.hpp. </li>
   <li> For an earlier attempt see
   OKsolver/Experimental/AllgKlassen200203/Clauses.hpp. </li>
  </ul>


  \todo General ideas
  <ul>
   <li> Do we need to distinguish between and-clauses and or-clauses? </li>
  </ul>


  \todo DONE (we have now Clauses::RClausesAsVectors and
  Clauses::RClausesAsSets)
  Clauses for unit-clause propagation
  <ul>
   <li> The following seems sensible for clauses used especially for
   unit-clause propagation (as a one-off reduction, especially for a
   given input clause-set, as a simple preprocessing; only falsified literals
   are processed). </li>
   <li> Construction by a sequence of literals. </li>
   <li> Simulating a sequence of literals, we have the typical
   access-components for containers, but only for reading. </li>
   <li> Additionally we have remove(Lit x), after which the size-member is
   still correct, however in order for the iteration through the literals to
   take the removed literal into account, first update(const TotalAssignment&)
   needs to be applied. </li>
   <li> remove(Lit) returns a boolean, which is true iff the size after
   removal is one, and where then by unit(const TotalAssignment&) the
   unit-literal is computed. </li>
   <li> Satisfied literals are ignored. </li>
   <li> update(TotalAssignment&) is only relevant if at least two literals are
   left. Though one needs also to find out here whether the clause has
   been satisfied; so update returns a boolean, which is true iff the clause
   was found satisfied. </li>
  </ul>


  \todo Partial assignments
  <ul>
   <li> A fundamental issue here is the relation to the concept of
   partial assignments (see Concepts/plans/PartialAssignments.hpp). </li>
   <li> It should be possible to easily switch between
   the concepts of partial assignments and clauses; perhaps the only
   difference is in the complexity of the operations: while clauses correspond
   to sets (using space proportionally to their size), partial assignments
   correspond to total maps (using a special value "unassigned"; supporting
   constant time access). </li>
   <li> As set-objects partial assignments and clause-sets
   are identical (for standard literals), namely they are sets of pairs of
   variables and (forbidden) values, interpreted as constituting the
   assignment or as literals. </li>
   <li> Regarding the operations considered above, from the concept-side (the
   operations and their complexity) there is quite some difference between
   clauses and partial assignments (for example regarding watched literals).
   So turning a partial assignment into a clause (and vice versa) must be
   possible (lossless), but might be more costly. </li>
   <li> The CNF(DNF)-representation of some condition is just a representation
   of those assignments we realised as falsifying (satisfying). </li>
  </ul>

*/

