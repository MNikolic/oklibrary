// Oliver Kullmann, 21.4.2009 (Swansea)
/* Copyright 2009 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/RamseyTheory/GreenTaoProblems/plans/GreenTao_2-3-k.hpp
  \brief On investigations into Green-Tao numbers greentao_2(3,k)


  \todo Investigate greentao_2(3,k)
  <ul>
   <li> Here we get into combinatorial area ("Ramsey-like"). </li>
   <li> greentao_2(3,0)=0, greentao_2(3,1)=4, greentao(3,2)=7,
   greentao(3,3)=23. </li>
   <li> greentao_2(3,4) = 79 (see below). </li>
   <li> greentao_2(3,5) = 528
    <ol>
     <li> greentao_2(3,5) > 450 (easy for OKsolver-2002) </li>
     <li> greentao_2(3,5) > 527 (trivial for ubcsat-rnovelty+). </li>
     <li> n=528 looks unsatisfiable by ubcsat-rnovelty+. </li>
     <li>  OKsolver-2002 proves unsatisfiability:
     \verbatim
> OKsolver_2002-O3-DNDEBUG -M -D10 GreenTao_2_3_5_528.cnf
s UNSATISFIABLE
c sat_status=0 initial_maximal_clause_length=5 initial_number_of_variables=527 initial_number_of_clauses=12692 initial_number_of_literal_occurrences=38748 running_time(s)=-364.7 number_of_nodes=1139193 number_of_single_nodes=22186 number_of_quasi_single_nodes=0 number_of_2-reductions=11956251 number_of_pure_literals=420178 number_of_autarkies=0 number_of_missed_single_nodes=6 max_tree_depth=43 number_of_table_enlargements=0 reduced_maximal_clause_length=0 reduced_number_of_variables=0 reduced_number_of_clauses=0 reduced_number_of_literal_occurrences=0 number_of_1-autarkies=47664479 number_of_initial_unit-eliminations=0 number_of_new_2-clauses=0 maximal_number_of_added_2-clauses=0 initial_number_of_2-clauses=0 file_name=GreenTao_2_3_5_528.cnf
     \endverbatim
     (about one hour).
     </li>
     <li> minisat solves it even faster:
     \verbatim
> minisat GreenTao_2_3_5_528.cnf
restarts              : 25
conflicts             : 3518551        (2170 /sec)
decisions             : 3840063        (2369 /sec)
propagations          : 146037825      (90078 /sec)
conflict literals     : 48001533       (41.34 % deleted)
Memory used           : 11.35 MB
CPU time              : 1621.24 s
     \endverbatim
     </li>
     <li> march_pl is also faster:
     \verbatim
> march_pl GreenTao_2_3_5_528.cnf
c main():: nodeCount: 328459
c main():: dead ends in main: 548
c main():: lookAheadCount: 134392690
c main():: unitResolveCount: 2031542
c main():: time=1729.920000
c main():: necessary_assignments: 51674
c main():: bin_sat: 0, bin_unsat 0
c main():: doublelook: #: 3653456, succes #: 3159644
c main():: doublelook: overall 2.760 of all possible doublelooks executed
c main():: doublelook: succesrate: 86.484, average DL_trigger: 153.978
s UNSATISFIABLE
     \endverbatim
     </li>
    </ol>
   </li>
   <li> See
   Experimentation/Investigations/RamseyTheory/GreenTaoProblems/plans/GreenTao_2-3-6.hpp
   for greentao_2(3,6). </li>
   <li> Also this sequence (starting with 4,7,23,79,528) is apparently not
   in that "online encyclopedia". </li>
  </ul>


  \todo greentao_2(3,4) = 79
  <ul>
   <li> Easy for OKsolver:
   \verbatim
> OKsolver_2002-O3-DNDEBUG GreenTao_2_3_4_78.cnf
s SATISFIABLE
c sat_status=1 initial_maximal_clause_length=4 initial_number_of_variables=77 initial_number_of_clauses=450 initial_number_of_literal_occurrences=1439 running_time(s)=0.0 number_of_nodes=25 number_of_single_nodes=0 number_of_quasi_single_nodes=1 number_of_2-reductions=56 number_of_pure_literals=7 number_of_autarkies=3 number_of_missed_single_nodes=0 max_tree_depth=10 number_of_table_enlargements=0 reduced_maximal_clause_length=0 reduced_number_of_variables=0 reduced_number_of_clauses=0 reduced_number_of_literal_occurrences=0 number_of_1-autarkies=25 number_of_initial_unit-eliminations=0 number_of_new_2-clauses=0maximal_number_of_added_2-clauses=0 initial_number_of_2-clauses=0 file_name=GreenTao_2_3_4_78.cnf
   \endverbatim
   and
   \verbatim
> OKsolver_2002-O3-DNDEBUG GreenTao_2_3_4_79.cnf
s UNSATISFIABLE
c sat_status=0 initial_maximal_clause_length=4 initial_number_of_variables=78 initial_number_of_clauses=460 initial_number_of_literal_occurrences=1472 running_time(s)=0.0 number_of_nodes=41 number_of_single_nodes=0 number_of_quasi_single_nodes=0 number_of_2-reductions=133 number_of_pure_literals=3 number_of_autarkies=0 number_of_missed_single_nodes=0 max_tree_depth=6 number_of_table_enlargements=0 reduced_maximal_clause_length=0 reduced_number_of_variables=0 reduced_number_of_clauses=0 reduced_number_of_literal_occurrences=0 number_of_1-autarkies=37 number_of_initial_unit-eliminations=0 number_of_new_2-clauses=0maximal_number_of_added_2-clauses=0 initial_number_of_2-clauses=0 file_name=GreenTao_2_3_4_79.cnf
   \endverbatim
   </li>
  </ul>


  \todo Predicting greentao_2(3,k)
  <ul>
   <li> Analysing the sequence 4,7,23,79,528,2072 (in R):
   \verbatim
d = c(4,7,23,79,528,2072)
plot(log(log(d)))
   \endverbatim
   it looks linear in the log-log, but the sixth value is definitely below
   that (one might see some oscillation). </li>
   <li> Perhaps k -> exp(k^c) for some constant c, since
   \verbatim
plot(log(c(1,2,3,4,5,6)[-1]),log(log(d)[-1]))
   \endverbatim
   looks linear:
   \verbatim
x = log(c(1,2,3,4,5,6)[-1])
y = log(log(d)[-1])
plot(x,y)
L = lm(y ~ x)
summary(L)
 Coefficients:
            Estimate Std. Error t value Pr(>|t|)
(Intercept) -0.22623    0.05648  -4.005   0.0279 *
x            1.25893    0.04117  30.578 7.68e-05 ***
lines(x,predict(L))
C = coefficients(L)
-0.2262296   1.2589339
   \endverbatim
   </li>
   <li> So y = -0.22623 + 1.25893 * x, that is,
   f(k) = exp(exp(C[1]) * k^C[2]) = exp(0.797535 * k^1.2589339):
   \verbatim
f = function(k){exp(exp(C[1]) * k^C[2])}
f(c(2,3,4,5,6,7,8))
 6.743988 24.044422 96.328312 423.826146 2018.493830 10301.119863 55910.95
   \endverbatim
   </li>
   <li> We see that the value for f(7) underestimates the correct
   value --- perhaps that oscillation. </li>
  </ul>

*/