// palindromei.hpp -- iterative palindrome tester
// c. 2015 A. Deeter

#ifndef PALINDROMEI_HPP
#define PALINDROMEI_HPP

#include <string>

class PalindromeI {

public:
  PalindromeI() {}
  int test_string(const std::string& s); 
};

class pQueue {
  char *queueArray;
  int f, r, qSize, numItems;

public:
  pQueue();
  ~pQueue();
  void enqueue(char);
  char dequeue();
  char front() const;
  bool isEmpty() const { return (numItems == 0); }
  int getSize() const { return qSize; }
}

#endif
