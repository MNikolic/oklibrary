# Tony H. Bao, 13.04.2005

General_options := -g
Optimisation_options := -O3 -DNDEBUG

test_program := TestDPv

programs := DPv

source_libraries = $(boost_include_option_okl)

boost_filesystem := -lboost_filesystem-gcc
boost_date_time := -lboost_date_time-gcc

link_libraries := $(boost_link_option_okl) $(boost_date_time) $(boost_filesystem)

