// Oliver Kullmann, 30.10.2005 (Swansea)

/*!
  \file SATCompetition/ComputeLexicographicalEvaluation.cpp
  \brief Outputs the lexicographically sorted evaluation of a random-competition.
  \todo The output should contain a legend, and the date and time of the evaluation
  (and also the version-information of this program).
  \todo The common output facilities for ComputeScores and ComputeLexicographicalEvaluation
  should go into a separate sub-module (and then used in these two programs).
  \todo Using the new module ProgramOptions (together with Messages).
*/
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>

#include <Transitional/SATCompetition/ParsingSingleResult.hpp>
#include <Transitional/SATCompetition/LexicographicalEvaluation.hpp>

template <bool with_extension>
struct LexicographicalEvaluationRandom_from_file {
  typedef OKlib::SATCompetition::LexicographicalEvaluationRandom_from_file<OKlib::SATCompetition::ParserThreeElements> type;
};
template <>
struct LexicographicalEvaluationRandom_from_file<false> {
  typedef OKlib::SATCompetition::LexicographicalEvaluationRandom_from_file<> type;
};

// #############################

template <bool with_extension>
struct Evaluation {

  const std::string& filename;
  const char* const specifier;

  typedef typename ::LexicographicalEvaluationRandom_from_file<with_extension>::type evaluation_from_file_type;
  evaluation_from_file_type eval;

  Evaluation(const std::string& filename, const char* const specifier) : filename(filename), specifier(specifier), eval(filename) {

    std::cout << "\nFile name = " << filename;
    if (specifier)
      std::cout << "\nsyntax specifier = " << specifier;
    std::cout << "\n\n";

    std::cout << "\nALL results: ---------------------------------------------------------------------------------------------------------------------\n\n";
    std::cout << "Unfolded lexicographical order:\n\n";
    eval.evaluation_unfolded_all.print(std::cout);
    std::cout << "\n";
    std::cout << "Induced lexicographical order:\n\n";
    eval.evaluation_induced_all.print(std::cout);
    std::cout << "\n";

    std::cout << "\nSAT results: ---------------------------------------------------------------------------------------------------------------------\n\n";
    std::cout << "Unfolded lexicographical order:\n\n";
    eval.evaluation_unfolded_sat.print(std::cout);
    std::cout << "\n";
    std::cout << "Induced lexicographical order:\n\n";
    eval.evaluation_induced_sat.print(std::cout);
    std::cout << "\n";
    
    std::cout << "\nUNSAT results: ---------------------------------------------------------------------------------------------------------------------\n\n";
    std::cout << "Unfolded lexicographical order:\n\n";
    eval.evaluation_unfolded_unsat.print(std::cout);
    std::cout << "\n";
    std::cout << "Induced lexicographical order:\n\n";
    eval.evaluation_induced_unsat.print(std::cout);
    std::cout << "\n";

  }
};


// #############################

int main(const int argc, char* const argv[]) {

  if (argc <= 1 or argc >= 4) {
    std::cerr << "One or two arguments required (the name of the file, and optionally a syntax specifier).\n";
    return EXIT_FAILURE;
  }
  const std::string& file_name(argv[1]);
  const bool specifier = (argc == 3);
  const char* const specifier_text = (specifier) ? argv[2] : (const char*)(0);

  if (specifier) {
    Evaluation<true>(file_name, specifier_text);
  }
  else {
    Evaluation<false>(file_name, specifier_text);
  }
}
