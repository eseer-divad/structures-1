#include "PalindromeI.hpp"

//--------------------------------------------------->
//--------------------------------------------------->
//--------------PALINDROMEI FUNCTIONS---------------->
//--------------------------------------------------->
//--------------------------------------------------->

int test_string(const std::string& s) {
  for(int i=0;i<s.size();i++) {
    s.push(s[i]);
    q.enqueue(s[i]);
  }
  int x = s.size();
  if(s.size() % 2 == 1) {
    x--;
  }
  for(int i=0;i<s.size()/2;i++) {
    
    if(isalpha(s.top()) && isalpha(q.front())) {
      int x = s.pop()
      int y = q.dequeue();
      if(x != y)
        return 0;
    }
    else if(!isalpha(s.top()) {
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
}

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

  //-----------------Constructor----------------->
  pQueue::pQueue() {
    f=nullptr; r=nullptr; qSize=0;
  }

  //-----------------Destructor----------------->
  pQueue::~pQueue() {
    char value;
    while (!isEmpty()) { 
      dequeue(value);
    }
    delete f;
    f = nullptr;
    delete r;
    r = nullptr;
  }
  
  //-------------------------------------------->
  //------------------Enqueue------------------->
  // Precons: a queue object, a char param.
  // Postcons: a new char is added to the queue.
  //-------------------------------------------->
  //-------------------------------------------->
  void pQueue::enqueue(char x) {

    // allocate a new node and store item there
    qNode *newNode = nullptr;
    newNode = new qNode;
    newNode->letter = x;
    newNode->next = nullptr;

    // Adjust as necessary.
    if(isEmpty()) { f=newNode; r=newNode; }
    else { r->next=newNode; r=newNode; }
    qSize++;

  }
   
  //-------------------------------------------->
  //------------------Dequeue------------------->
  // Precons: a queue object.
  // Postcons: a char is removed from the queue
  //-------------------------------------------->
  //-------------------------------------------->
  char pQueue::dequeue() {
    qNode *node = nullptr;
    if (isEmpty()) { throw "The queue is empty!\n"; }
    else {
        // Save front, remove, and delete.
        char x = f->letter;
        node = f; f=f->next; delete node;
        node->next = nullptr;
        qSize--;
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
    qNode *temp = nullptr;
    if(isEmpty()) { throw "The queue is empty!\n"; }
    else { return f->letter; }
  }