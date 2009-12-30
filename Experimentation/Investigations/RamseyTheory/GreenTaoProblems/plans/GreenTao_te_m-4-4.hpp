// Oliver Kullmann, 29.12.2009 (Swansea)
/* Copyright 2009 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/RamseyTheory/GreenTaoProblems/plans/GreenTao_te_m-4-4.hpp
  \brief Investigations regarding the "transversal extension" numbers greentao_{m+2}([2,...,2,4,4])

  Generated by output_greentao_stdname(append(create_list(2,i,1,m),[4,4]),n)
  and output_greentao_sb_stdname(append(create_list(2,i,1,m),[4,4]),n) at
  Maxima-level, and by "GTSat 2 ... 2 4 4 n" at C++ level.


  \todo greentao_3(2,4,4) >= 553
  <ul>
   <li> The conjecture is greentao_3(2,4,4) = 553. </li>
   <li> Let's start with n = 530; should be satisfiable, and not too hard.
   </li>
   <li> Best local search algorithm from Ubcsat-suite:
   \verbatim
> E = eval_ubcsat("GreenTao_3-2-4-4_530.cnf")
   \endverbatim
   evaluated by plot(E$alg,E$best): Again novelty+ seems best (the only
   solver who found a solution):
   \verbatim
>  table(E$best[E$alg=="noveltyp"])
 0  1  2  3  4  5  6  8
 3 16 32 19 14  8  7  1
   \endverbatim
   </li>
   <li> n=550: cutoff=10^5 with novelty+ not enough, cutoff=2*10^5 still not
   enough, cutoff=4*10^5 found one solution (seed=1478958963,osteps=358472):
   \verbatim
 1  2  3  4  5  6  7  8  9 10 11 12 13 15
 1  3  5 13 10 13 14 11  7  8  4  6  4  1
100
 1  2  3  4  5  6  7  8  9 10 11 12
 5 14  9 13 13 12 17  9  3  3  1  1
100
 0  1  2  3  4  5  6  7  8  9 10
 1 12 29 18 19 11  4  3  1  1  1
100
   \endverbatim
   </li>
   <li> n=551, novelty+, cutoff=10^6: 8 solutions found
   \verbatim
 0  1  2  3  4
 8 40 35 15  2
100
   \endverbatim
   (seed=3514873770, osteps=223114). </li>
   <li> n=552, novelty+, cutoff=10^6: 5 solutions found
   \verbatim
 0  1  2  3  4  5  6  7
 5 38 34 15  3  3  1  1
100
   \endverbatim
   (seed=783660701, osteps=463980). </li>
   <li> n=553, novelty+:
    <ol>
     <li> cutoff=10^6:
     \verbatim
 1  2  3  4  5  6
33 38 16  6  6  1
100
     \endverbatim
     </li>
     <li> cutoff=2*10^6:
     \verbatim
 1  2  3
63 30  7
100
     \endverbatim
     </li>
     <li> cutoff=4*10^6:
     \verbatim
 1  2  3
95  4  1
100
   1    2    3
1879  109   12
2000
     \endverbatim
     </li>
    </ol>
   </li>
   <li> n=555, novelty+
    <ol>
     <li> cutoff=10^6:
     \verbatim
 1  2  3  4  5  6  7
13 30 35 10  6  4  2
100
     \endverbatim
     </li>
     <li> cutoff=2*10^6
     \verbatim
 1  2  3  4  5
42 47  4  6  1
100
     \endverbatim
     </li>
    </ol>
   </li>
   <li> n=560, novelty+:
    <ol>
     <li> cutoff=10^6:
     \verbatim
 1  2  3  4  5  6  7  8
 8 26 21 17 13 11  3  1
100
     \endverbatim
     </li>
     <li> cutoff=2*10^6
     \verbatim
 1  2  3  4  5
30 32 20 15  3
100
     \endverbatim
     </li>
    </ol>
   </li>
   <li> n=570: For cutoff in 10^6, 2*10^6, 4*10^6, 8*10^6, cutoff=16*10^6
   (novelty+) we get the following min-distributions:
   \verbatim
 1  2  3  4  5  6  7  8  9 10
 1  6 15 13 18 14 10 14  6  3
100
 1  2  3  4  5  6  7  8
 1 16 21 21 17  6 11  7
100
 1  2  3  4  5  6  7
 2 32 32 21  8  3  2
100
 1  2  3  4  5
 5 63 16 11  5
100
 1  2  3
27 58 15
100
   \endverbatim
   adaptnovelty+ with cutoff in 4*10^6, 16*10^6 reaches
   \verbatim
 1  2  3  4
 2 22 73  3
100
 1  2  3
20 55 25
100
   \endverbatim
   (so within this cutoff-range novelty+ is better than adaptnovelty+).
   Let's consider this as unsatisfiable. </li>
   <li> OKsolver_2002 for n=553:
    <ol>
     <li> Without preprocessing and without symmetry breaking:
     \verbatim
> OKsolver_2002-O3-DNDEBUG -M -D16 -F GreenTao_3-2-4-4_553.cnf
     \endverbatim
     Looks possible.
     </li>
     <li> With preprocessing and without symmetry breaking:
     \verbatim
> OKsolver_2002-m2pp -M -D16 -F GreenTao_3-2-4-4_553.cnf
     \endverbatm
     Didn't complete a monitoring node after 3 m and 150000 nodes (now no
     autarkies were found, different from the run without preprocessing,
     where there are many). </li>
     </li>
    </ol>
   </li>
  </ul>


  \todo greentao_4(2,2,4,4) > 575
  <ul>
   <li> Let's start with n = 570; should be satisfiable, and not too hard.
   </li>
   <li> And let's use novelty+ as the main Ubcsat-solver. </li>
   <li> n=560:
    <ol>
     <li> cutoff=10^5: Only min=1 reached once in 100 runs. </li>
     <li> cutoff=10^6: Finds one satisfying assignment in 100 runs
     (seed=1415197577, osteps=723855). </li>
    </ol>
   </li>
   <li> n=565: cutoff=2*10^6 found a solution (seed=1961628490,
   osteps=1873226). </li>
   <li> n=570:
    <ol>
     <li> cutoff=10^5: Only min=2 reached in 100 runs. </li>
     <li> cutoff=10^6:
     \verbatim
 1  2  3  4
 7 62 28  3
100
     \endverbatim
     </li>
     <li> cutoff=2*10^6: One solution found:
     \verbatim
 0  1  2  3
 1 14 72 13
100
> E[E$min==0,]
   sat min  osteps  msteps       seed
65   1   0 1403508 1403508 2325307179
     \endverbatim
     </li>
    </ol>
   </li>
   <li> n=575, cutoff=4*10^6 found one solution in 100 runs:
   \verbatim
> E = read_ubcsat("GreenTao_4-2-2-4-4_575.cnf_OUT")
 0  1  2  3
 1 24 70  5
100
> E[E$min==0,]
   sat min  osteps  msteps     seed
83   1   0 3483852 3483852 16671608
   \endverbatim
   </li>
   <li> n=580, cutoff=8*10^6 </li>
  </ul>

*/
