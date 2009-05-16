// Oliver Kullmann, 20.9.2008 (Swansea)
/* Copyright 2008, 2009 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file ComputerAlgebra/Satisfiability/Lisp/Generators/plans/VanderWaerdenProblems.hpp
  \brief Plans for Maxima-generators related to van der Waerden problems (and generalisations)


  \todo Connections
  <ul>
   <li> See Applications/RamseyTheory/plans/Van_der_Waerden_hypergraph.hpp
   for general plans at C++ level. </li>
   <li> See
   Experimentation/Investigations/RamseyTheory/VanderWaerdenProblems/plans/general.hpp
   for experiments with vdW-problems. </li>
   <li> See
   Experimentation/Investigations/RamseyTheory/GreenTaoProblems/plans/general.hpp
   for experiments with GT-problems. </li>
   <li> See Satisfiability/Transformers/Generators/ and
   Satisfiability/Transformers/Generators/plans/general.hpp for several
   generators for vdW- and GT-problems. </li>
  </ul>


  \todo Organisation
  <ul>
   <li> Likely we should create a submodule "Lisp/Generators/RamseyTheory".
   </li>
   <li> There then the Green-Tao functions should go into a separate file.
   </li>
   <li> Perhaps we should split the module, as we have it now with
   Investigations/RamseyTheory; a question whether we should use
   "Problems" as part of the module names or not (as in
   ComputerAlgebra/RamseyTheory). </li>
  </ul>


  \todo Standardisation
  <ul>
   <li> As we have it now in output_vanderwaerden, standardisation for
   all non-standardised clause-sets should be done explicitly. </li>
  </ul>


  \todo Statistics
  <ul>
   <li> As discussed in "Accompanying statistics" in
   Satisfiability/Lisp/Generators/plans/general.hpp in general, we need
   statistics for all main messurements (and also for all others, if
   possible). </li>
   <li> First the hypergraph measurements needs to be established; see
   "Statistics" in Hypergraphs/Lisp/plans/Generators.hpp. </li>
  </ul>


  \todo Statistics output for Green-Tao problems in the Dimacs-file
  <ul>
   <li> Care needs to be taken that these measurements are not too
   inefficient --- currently they are. </li>
   <li> If different progression-lengths are involved, then for each
   involved hypergraph we should have data like standard_statistics_fcs. </li>
   <li> This should happen in the hypergraph module. </li>
   <li> The data for the whole clause-set could then be obtained by just
   adding up the numbers. </li>
   <li> The computation of standard_statistics_fcs should be made much
   more efficient. </li>
   <li> As discussed above in todo "Statistics", there should be specialised
   functions (with standardised names) for computing the "standard" statistics.
   </li>
   <li> For Green-Tao data this doesn't help much, since there is no
   faster computation than just "measuring", but we should establish
   (and follow) a general scheme. </li>
  </ul>


  \todo Systematic output and output-functions
  <ul>
   <li> Likely, the outputs for van-der-Waerden and for Green-Tao problems
   should be very similar. </li>
   <li> Regarding the naming of files, for the general (non-boolean, non-
   diagonal) form we should provide another form which translates for
   example [2,2,2,2,3,3,4] in "_7_2:4_3:2_4". </li>
  </ul>


  \todo Alternative handling of parameter-values 2
  <ul>
   <li> A parameter value 2 means that the corresponding part can contain
   at most one element. </li>
   <li> Currently this gets (automatically) translated using the standard
   representation of AMO for the vertices, using binom(n,2) binary clauses
   (since two different vertices make always a progression of length 2). </li>
   <li> An alternative is presented in "At-most-one as a CNF" in
   ComputerAlgebra/Satisfiability/Lisp/FiniteFunctions/plans/Thresholds.hpp,
   and one should try this. </li>
   <li> We should also provide standard generators for these two
   AMO-representations. </li>
  </ul>


  \todo DONE
  More than two parts
  <ul>
   <li> Create non-boolean clause-sets for the van der Waerden problems and
   the Green-Tao problems with more than two parts. </li>
   <li> Compare "Generalised colouring problems" in
   ComputerAlgebra/Satisfiability/Lisp/Generators/plans/general.hpp. </li>
  </ul>


  \todo Symmetry breaking for GT-problems
  <ul>
   <li> For a progression-length k (relevant for all parts i with k_i=k)
   we want to use the vertex occurring most often. </li>
   <li> Then the current implementations, which just chose prime 3, are
   defective, since only for k=3 this is the right choice. </li>
   <li> For k=2 we just have a complete graph, and so all vertices are
   equal. </li>
   <li> For prime k >= 3 it seems that k itself occurs most often.
   This should be due to the exceptional status of k as basis of
   progressions of length k (their slopes doesn't need to be a multiple
   of product_primes(k), as it is otherwise the case). </li>
   <li> For non-prime k >= 3 the first impression is, that the vertex
   with index roughly 0.42*n for k=4 and roughly 0.3*n for k=6 occurs most
   often; this needs to investigated. </li>
  </ul>


  \todo Symmetry breaking for vdW-problems
  <ul>
   <li> The symmetry-breaking should happen as with the Green-tao problems,
   only that the distinguished vertex is a central one. </li>
   <li> This needs to be investigated; it seems that floor(n/2)-1 is
   always a vertex with maximal degree. </li>
  </ul>


  \todo Arithmetic progressions for prime numbers
  <ul>
   <li> The following needs to go into the docus:
    <ol>
     <li> The theorem of Green-Tao: "When partitioning the set of prime numbers
     into m parts, then at least one part contains arithmetic progressions
     of arbitrary lengths". </li>
     <li> Via compactness, this should translate into the property that for m
     and k there is (a least) n such that for every partitioning of the first
     n prime numbers into m parts one of the parts contains an arithmetic
     progressions of length k. </li>
     <li> The corresponding numbers are "Green-Tao numbers", greentao(m,k).
     </li>
     <li> One should have greentao(m,k) >= vanderwaerden(m,k). </li>
    </ol>
   </li>
   <li> DONE
   We should create a function "greentao2_fcs(k,n)".
    <ol>
     <li> Via primes_first(n) we get the first n prime numbers. </li>
     <li> Finding the arithmetic progressions of length k can be done
     recursively. </li>
    </ol>
   </li>
   <li> DONE
   Of course, we also need the underlying hypergraphs. </li>
  </ul>

*/

