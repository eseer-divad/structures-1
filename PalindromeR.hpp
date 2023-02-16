// palindromeR.hpp -- recursive palindrome tester
// c. 2015 A. Deeter

#ifndef PALINDROMER_HPP
#define PALINDROMER_HPP

#include <string>

class PalindromeR {
  int f, r;

public:
  PalindromeR() {}
  int test_string(const std::string& s);
  bool palindromeRec(char str[], int f, int r)
};

#endif
