#include "Test.h"
#include <iostream>
using namespace std;

Test::Test(Queue theQueue)
{
myQueue = theQueue;
is_empty_at_creation();
is_empty_after_enqueue();
is_empty_after_dequeue();
enqueue_adds_to_back();
dequeue_removes_from_front();
dequeue_throws_excep_on_empty();
}


Test::~Test()
{

}

//TESTS FOR ISEMPTY.............................................................
void Test::is_empty_at_creation()
{
  cout<<"Newly created Queue is empty: ";
  if(myQueue.isEmpty()==true)
  {
  cout<<"PASSED \n";
  }else
  {
  cout<<"FAILED \n";
  }
}

void Test::is_empty_after_enqueue()
{
  myQueue.enqueue(5);
  cout<<"Queue after enqueue is not empty: ";
  if(myQueue.isEmpty()==false)
  {
  cout<<"PASSED \n";
  }else
  {
  cout<<"FAILED \n";
  }
  myQueue.dequeue();
}

void Test::is_empty_after_dequeue()
{
  myQueue.enqueue(5);
  myQueue.dequeue();
  cout<<"Queue after dequeue with size 1 is now empty: ";
  if(myQueue.isEmpty()==true)
  {
  cout<<"PASSED \n";
  }else
  {
  cout<<"FAILED \n";
  }
}

//TESTS FOR ENQUEUE.............................................................
void Test::enqueue_adds_to_back()
{
  //FOUND BUG! enqueue adds to front!
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  cout<<"Enqueue adds to back of queue: ";
  if(myQueue.peekFront()==1)
  {
  cout<<"PASSED \n";
  }else
  {
  cout<<"FAILED \n";
  }
  myQueue.dequeue();
  myQueue.dequeue();
  myQueue.dequeue();
}

//TESTS FOR DEQUEUE.............................................................
void Test::dequeue_removes_from_front()
{
  //TESTING DEQUEUE ASSUMING ENQUEUE ADDS TO FRONT BECAUSE OF THE BUG
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  myQueue.enqueue(4);
  myQueue.dequeue();
  cout<<"Enqueue removes from front of the queue: ";
  if(myQueue.peekFront()==3)
  {
  cout<<"PASSED \n";
  }else
  {
  cout<<"FAILED \n";
  }
  myQueue.dequeue();
  myQueue.dequeue();
  myQueue.dequeue();
}

void Test::dequeue_throws_excep_on_empty()
{
  cout<<"Enqueue throws exception when called on empty queue: ";
  myQueue.enqueue(1);
  myQueue.dequeue();
  try{
  myQueue.dequeue();
  cout<<"FAILED \n";
  }catch(runtime_error e)
  {
  cout<<"PASSED \n";
  }
}
