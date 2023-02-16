#include "PalindromeI.hpp"

//--------------------------------------------------->
//--------------------------------------------------->
//--------------PALINDROMEI FUNCTIONS---------------->
//--------------------------------------------------->
//--------------------------------------------------->

 int PalindromeI::test_string(const char* str) {
  for(int i=0;i<sizeof(str);i++) {
    s.push(str[i]);
    q.enqueue(str[i]);
  }
  int x = sizeof(str);
  if(sizeof(str) % 2 == 1) {
    x--;
  }
  for(int i=0;i<sizeof(str)/2;i++) {

    if(isalpha(s.top()) && isalpha(q.front())) {
      int x = s.pop();
      int y = q.dequeue();
      if(x != y)
        return 0;
    }
    else if(!isalpha(s.top())) {
      i--;
      s.pop();
    }
    else if(!isalpha(q.front())) {
      i--;
      q.dequeue();
    }
    else { throw "error in palindrome check"; }
  }
  return -1;
};


int PalindromeI::test_string(const std::__cxx11::string str) {
  for(int i=0;i<str.size();i++) {
    s.push(str[i]);
    q.enqueue(str[i]);
  }
  int x = str.size();
  if(str.size() % 2 == 1) {
    x--;
  }
  for(int i=0;i<str.size()/2;i++) {

    if(isalpha(s.top()) && isalpha(q.front())) {
      int x = s.pop();
      int y = q.dequeue();
      if(x != y)
        return 0;
    }
    else if(!isalpha(s.top())) {
      i--;
      s.pop();
    }
    else if(!isalpha(q.front())) {
      i--;
      q.dequeue();
    }
    else { throw "error in palindrome check"; }
  }
  return -1;
};

//--------------------------------------------------->
//--------------------------------------------------->
//-------------PSTACK CLASS FUNCTIONS---------------->
//--------------------------------------------------->
//--------------------------------------------------->

/* pStack Class Destructor
Pre-Cons: An object of pStack.
Post-Cons: The object is devastated. */
pStack::~pStack() {
  pStackNode *node, *next;
  node = topPtr;
  while (node != nullptr) { //traverse & delete
    next = node->next;
    delete node;
    node = next;
    stackSize--;
  }
};

/* pStack Class Push Function
Pre-Cons: An object of pStack, and a char to push onto it. (LIFO)
Post-Cons: +1 stacksize, new char pushed onto the top of the stack */
void pStack::push(char x) {
  pStackNode *node = nullptr;
  node = new pStackNode;
  node->letter = x; // store item here

  // Emptiness decides how we assign a new node.
  if(isEmpty()) { topPtr = node; node->next = nullptr; }
  else { node->next = topPtr; topPtr = node; }
};

/* pStack Class Pop Function
Pre-Cons: An object of pStack. (LIFO)
Post-Cons: -1 stacksize,
           & a char returned/removed off the top of the stack, */
char pStack::pop() {
  pStackNode *temp = nullptr;
  if(isEmpty()) { throw "The stack is empty!\n"; }
  else {
    char x = topPtr->letter;
    temp = topPtr->next;
    delete topPtr;
    topPtr = temp;
    stackSize--;
    return x;
  }
};

/* pStack Class Top Function
Pre-Cons: An object of pStack.
Post-Cons: Returns the value topPtr points to, unless empty. */
char pStack::top() const {
  pStackNode *temp = nullptr;
  if(isEmpty()) { throw "The stack is empty!\n"; }
  else { return topPtr->letter; }
};

  //--------------------------------------------------->
  //--------------------------------------------------->
  //-------------PQUEUE CLASS FUNCTIONS---------------->
  //--------------------------------------------------->
  //--------------------------------------------------->

  pQueue::pQueue() {
      //fixed size = 30
    queueArray = new char[30];
  }

  //-----------------Destructor----------------->
  pQueue::~pQueue() {
    if(numItems > 0)
      delete [] queueArray;
  }

  //-------------------------------------------->
  //------------------Enqueue------------------->
  // Precons: a queue object, a char param.
  // Postcons: a new char is added to the queue.
  //-------------------------------------------->
  //-------------------------------------------->
  void pQueue::enqueue(char x) {

    if(numItems < qSize) {
      queueArray[r] = x;
      r = (r+1)%qSize;
      numItems++;
    }
    else throw "The queue is full.\n";
  }

  //-------------------------------------------->
  //------------------Dequeue------------------->
  // Precons: a queue object.
  // Postcons: a char is removed from the queue
  //-------------------------------------------->
  //-------------------------------------------->
  char pQueue::dequeue() {
    if (isEmpty()) { throw "The queue is empty!\n"; }
    else {
        // Save front, remove, and delete.
        char x = queueArray[f];
        f=(f+1)%qSize;
        numItems--;
        return x;
    }
  }

  //-------------------------------------------->
  //-------------------Front-------------------->
  // Precons: a queue object, a want.
  // Postcons: returns the front value unless empty.
  //-------------------------------------------->
  //-------------------------------------------->
  char pQueue::front() const {
    if(isEmpty()) { throw "The queue is empty!\n"; }
    else { return queueArray[f]; }
  }
