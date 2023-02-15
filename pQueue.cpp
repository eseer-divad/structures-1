  #include "PalindromeI.hpp"
  
  //-----------------Constructor----------------->
  pQueue::pQueue(int x) {
    queueArray = new char[x];
    qSize = x;
    f = -1;
    r = -1;
    numItems = 0;
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
    else throw "The queue is full.\n"
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