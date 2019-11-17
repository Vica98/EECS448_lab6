/**
*	@file Test.h
*	@author Victoria Maldonado
*	@date 11/13/2019
*/

#ifndef TEST_H
#define TEST_H

#include "Queue.h"
#include <stdexcept>

class Test
{
public:
  Test();
  ~Test();
  void is_empty_at_creation();
  void is_empty_after_enqueue();
  void is_empty_after_dequeue();
  void enqueue_adds_to_back();
  void dequeue_removes_from_front();
  void dequeue_throws_excep_on_empty();
  void peek_front_throws_excep_on_empty();
  void peek_returns_as_expected();
  void peek_front_doesnt_change_queue();
  void enqueue_after_dequeue();
  Queue* myQueue;
private:

};
#endif
