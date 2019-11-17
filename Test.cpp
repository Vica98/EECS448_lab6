#include "Test.h"
#include <iostream>
using namespace std;

Test::Test()
{
is_empty_at_creation();
is_empty_after_enqueue();
is_empty_after_dequeue();
enqueue_adds_to_back();
dequeue_removes_from_front();
dequeue_throws_excep_on_empty();
peek_front_throws_excep_on_empty();
peek_returns_as_expected();
peek_front_doesnt_change_queue();
enqueue_after_dequeue();
myQueue = new Queue();
}


Test::~Test()
{
delete myQueue;
}

//TESTS FOR ISEMPTY.............................................................
void Test::is_empty_at_creation()
{
  Queue myQueue;
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
  Queue myQueue;
  myQueue.enqueue(5);
  cout<<"Queue after enqueue is not empty: ";
  if(myQueue.isEmpty()==false)
  {
  cout<<"PASSED \n";
  }else
  {
  cout<<"FAILED \n";
  }
}

void Test::is_empty_after_dequeue()
{
  Queue myQueue;
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
    Queue myQueue;
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
}

void Test::enqueue_after_dequeue()
{
  Queue myQueue;
  myQueue.enqueue(1);
  myQueue.dequeue();
  myQueue.enqueue(1);
  cout<<"Enqueue adds normally after dequeue: ";
  if(myQueue.peekFront()==1)
  {
  cout<<"PASSED \n";
  }else
  {
  cout<<"FAILED \n";
  }
}
//TESTS FOR DEQUEUE.............................................................
void Test::dequeue_removes_from_front()
{
  //TESTING DEQUEUE ASSUMING ENQUEUE ADDS TO FRONT BECAUSE OF THE BUG
  Queue myQueue;
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
}

void Test::dequeue_throws_excep_on_empty()
{
  Queue myQueue;
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

//TESTS FOR PEEK FRONT.............................................................
void Test::peek_front_throws_excep_on_empty()
{
  Queue myQueue;
  cout<<"Peek front throws exception when called on empty queue: ";
  try{
  myQueue.peekFront();
  cout<<"FAILED \n";
  }catch(runtime_error e)
  {
  cout<<"PASSED \n";
  }
}

void Test::peek_returns_as_expected()
{
  Queue myQueue;
  cout<<"Enqueue 4 and peekfront returns 4: ";
  myQueue.enqueue(4);
  if(myQueue.peekFront()==4)
  {
      cout<<"PASSED \n";
  }else
  {
      cout<<"FAILED \n";
  }
}

void Test::peek_front_doesnt_change_queue()
{
  //Test assuming enqueue doesnt work properly
  Queue myQueue;
  cout<<"Peek front doesnt change queue when called: ";
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  myQueue.enqueue(4);
  if(myQueue.peekFront()==4){
    myQueue.dequeue();
    if(myQueue.peekFront()==3){
      myQueue.dequeue();
        if (myQueue.peekFront()==2) {
          myQueue.dequeue();
            if(myQueue.peekFront()==1){
                cout<<"PASSED \n";
            }else{
                cout<<"FAILED \n";
            }
        }else{
            cout<<"FAILED \n";
        }
    }else{
      cout<<"FAILED \n";
    }
  }else{
  cout<<"FAILED \n";
  }
}
