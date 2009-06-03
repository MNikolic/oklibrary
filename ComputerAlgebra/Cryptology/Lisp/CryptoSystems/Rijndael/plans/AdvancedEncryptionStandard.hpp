// Oliver Kullmann, 20.7.2008 (Swansea)
/* Copyright 2008, 2009 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file ComputerAlgebra/Cryptology/Lisp/CryptoSystems/Rijndael/plans/AdvancedEncryptionStandard.hpp
  \brief Plans on the AES implementation


  \todo Naming Conventions DONE
  <ul>
   <li> To avoid clashes with other modules and to make clear which functions
   are specific to AES and which aren't, functions in this module should 
   perhaps have the prefix "aes_". </li>
   <li> "aes_" is reasonable as yet only AES is implemented, not general 
   Rijndael. </li>
   <li> DONE Far better, would be to name functions/variables which are specific
   to the current 128 bit AES implementation using "aes_", and name those which 
   are general to rijndael with "rijn_". This should make clear what needs to be
   extended or generalised to implement full Rijndael rather than simply AES. 
   </li>
   <li> DONE Should this perhaps instead be "rijndael_" or "rijn_" or similar? </li>
   <li> DONE We don't use "camels", so names like GF2t8PolyToInt needs to be
   replaced. </li>
  </ul>


  \todo %Auxiliary functions DONE
  <ul>
   <li> See TermSystems/Lisp/Conversions.mac. </li>
   <li> DONE What about the section "Helper Functions" ?
    <ol>
     <li> DONE We shouldn't have a section with "useless stuff":
     Auxiliary functions either directly accompany their main user, or are
     not just "helper functions". </li>
     <li> DONE intToPoly and polyToInt should (besides the bad naming (see below))
     be replaced by the gf-functions poly2num and num2poly. </li>
    </ol>
   </li>
   <li> DONE What is the meaning of
   \verbatim
load("functs")$ Bug Here atm  For logxor
   \endverbatim
   If there is a Maxima bug, then it needs to submitted to Maxima,
   and we provide a correction. (MG : "logxor" didn't return the correct values
   for some inputs, but this no longer seems to be the case in the most recent
   version, and may have been a broken installation on my part. The lisp
   version "?logxor" has now been replaced with the maxima "logxor".) </li>
  </ul>
  

  \bug AES is computed incorrectly DONE
  <ul>
   <li> Tests "okltest_aes_int" etc. fail, likely due to incorrect ordering
   of the list of input bytes into blocks. </li>
   <li> This needs urgent correction. </li>
   <li> Also all intermediate functions ("Shift Row" etc.) need to correspond
   to their definition in the Rijndael book. </li>
   <li> All tests needs updates, as well as the docu-file. </li>
  </ul>

*/

