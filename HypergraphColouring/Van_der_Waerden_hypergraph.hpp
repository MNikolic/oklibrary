// Oliver Kullmann, 15.5.2005 (Swansea)

#ifndef VANDERWAERDENHYPERGRAPH_77bQMQM

#define VANDERWAERDENHYPERGRAPH_77bQMQM

#include <iterator>
#include <cassert>

namespace OKlib {

  namespace Van_der_Waerden_hypergraph {

    template <typename Integer>
    class Iterator_arithmetic_progression : public std::iterator<std::input_iterator_tag, Integer> {
      // ToDo: Add the concept tag (an "IteratorArithmeticProgression").
      // ToDo: Make a const random iterator out of it.
      Integer current_value;
      Integer slope;
    public :
      Iterator_arithmetic_progression(const Integer start_value, const Integer slope) : current_value(start_value), slope(slope) {}
      Integer operator* () const { return current_value; }
      Iterator_arithmetic_progression& operator ++() {
        current_value += slope;
        return *this;
      }
      Iterator_arithmetic_progression operator ++(int) {
        Iterator_arithmetic_progression i(*this);
        operator ++();
        return i;
      }
    };

    template <typename Integer>
    inline bool operator ==(const Iterator_arithmetic_progression<Integer>& lhs, const Iterator_arithmetic_progression<Integer>& rhs) {
      return *lhs == *rhs;
    }
    template <typename Integer>
    inline bool operator !=(const Iterator_arithmetic_progression<Integer>& lhs, const Iterator_arithmetic_progression<Integer>& rhs) {
      return not (lhs == rhs);
    }

    // -----------------------------------------------------------------------------------------------------------------------------


    template <typename Integer>
    class Arithmetic_progression {
      // ToDo: Add the concept tag (a special case of a "const collection with begin, end and size; not default-constructible, but copyable, assignable, equality comparable").
      Integer start_, length, slope_;
      Integer finish;
    public :
      Arithmetic_progression(const Integer start, const Integer length, const Integer slope) : start_(start), length(length), slope_(slope), finish(start_ + length * slope_) {
        assert(length >= 0);
      }
      typedef Integer value_type;
      typedef Integer size_type;
      size_type size() const { return length; }
      typedef Iterator_arithmetic_progression<Integer> iterator;
      typedef iterator const_iterator;
      iterator begin() const { return iterator(start_, slope_); }
      iterator end() const { return iterator(finish, 0); }
      friend bool operator ==(const Arithmetic_progression& lhs, const Arithmetic_progression& rhs) {
        return lhs.start == rhs.start and lhs.length == rhs.length and lhs.slope == rhs.slope;
      }
      value_type start() const { return start_; }
      value_type slope() const { return slope_; }
    };

    // -----------------------------------------------------------------------------------------------------------------------------


  }

}

#endif
