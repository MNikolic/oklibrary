// Oliver Kullmann, 17.4.2009 (Swansea)
/* Copyright 2009 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/RamseyTheory/SchurProblems/plans/general.hpp
  \brief On computing schur(5)


  \todo OKsolver_2002
  <ul>
   <li> With a cluster and a few months it looks feasible without any
   special action:
   \verbatim
> OKsolver_2002-O3-DNDEBUG -M -D20 Schur_5_160.cnf

Name of file and number of monitoring nodes:
 Schur_5_160.cnf, 1048576
  1:   387,   15.4, 16179512.2
  2: 13720,  387.6, 203208398.3
  3:  1568,  441.4, 154290526.5
  4: 17781,  969.0, 254011324.1
  5:  4987, 1102.6, 231232974.1
  6:  6499, 1310.7, 229063611.7
  7: 18361, 1819.8, 272591989.1
  8: 40898, 2820.2, 369652987.8
  9: 10636, 3088.2, 359799455.0
 10: 24184, 3686.7, 386575875.8
 11: 13620, 4012.0, 382437393.0
 12: 35767, 4868.0, 425370957.9
 13: 10667, 5114.3, 412514363.2
 14:  7705, 5335.4, 399605480.3
 15: 18446, 5912.8, 413326668.3

s UNKNOWN
c sat_status=2 initial_maximal_clause_length=5 initial_number_of_variables=800 initial_number_of_clauses=33760 initial_number_of_literal_occurrences=99600 running_time(s)=6116.4 number_of_nodes=231351 number_of_single_nodes=14 number_of_quasi_single_nodes=0 number_of_2-reductions=3696760 number_of_pure_literals=0 number_of_autarkies=0 number_of_missed_single_nodes=282 max_tree_depth=58 number_of_table_enlargements=0 reduced_maximal_clause_length=0 reduced_number_of_variables=0 reduced_number_of_clauses=0 reduced_number_of_literal_occurrences=0 number_of_1-autarkies=65040054 number_of_initial_unit-eliminations=0 number_of_new_2-clauses=0 maximal_number_of_added_2-clauses=0 initial_number_of_2-clauses=2000 file_name=Schur_5_160.cnf
   \endverbatim
   </li>
   <li> And with initial symmetry breaking (using
   output_schur_sb_stdname(5,160)) a factor of nearly 5 should be achievable:
   \verbatim

   \endverbatim
   </li>
  </ul>

*/
