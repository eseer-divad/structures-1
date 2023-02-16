// palindromei.hpp -- iterative palindrome tester
// c. 2015 A. Deeter

#ifndef PALINDROMEI_HPP
#define PALINDROMEI_HPP

#include <string>

class pQueue {
  char *queueArray;
  int f, r, qSize, numItems;

public:
  pQueue();
  pQueue(int x);
  ~pQueue();
  void enqueue(char);
  char dequeue();
  char front() const;
  bool isEmpty() const { return (numItems == 0); }
  int getSize() const { return qSize; }
};

class pStack {
  struct pStackNode {
    char letter;
    pStackNode* next;
  };
  int stackSize;
  pStackNode *topPtr;

public:
  pStack();
  ~pStack();
  void push(char);
  char pop();
  char top() const;
  bool isEmpty() const { return (stackSize == 0); }
  int getSize() const { return stackSize; }
};

class PalindromeI {
  pQueue q;
  pStack s;

public:
  PalindromeI() {}
  int test_string(const std::string& str);
};





#endif
