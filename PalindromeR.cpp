//--------------------------------------------------->
//--------------------------------------------------->
//--------------PALINDROMER FUNCTIONS---------------->
//--------------------------------------------------->
//--------------------------------------------------->

#include "PalindromeR.hpp"

int PalindromeR::test_string(const std::string& str) {
  int length = str.length();
  if(!length) { return -1; }
  return palindromeRec(str, 0, length-1);
};

int PalindromeR::palindromeRec(const std::string& str, int f, int r) {

    if(f==r) { return -1; }
    if(str[f] != str[r]) { return 1; }
    if(f < r + 1) { return palindromeRec(str, f+1, r-1); }

    return -1;
};
