/**
*	@file Test.h
*	@author Noah Kenn
*	@date 11/6/2017
*	@brief A Test Class
*/

#ifndef TEST_H
#define TEST_H

#include "LinkedListOfInts.h"
#include <iostream>

class Test
{
public:
  void runTests();
private:
  void testIsEmpty();
  void testSize();
  void testSearchFirst();
  void testAddBack();
  void testAddBackOnceMore();
  void testAddFront();
  void testIsEmptyAfterAdding();
  void testSearchSecond();
  void testRemoveBack();
  void testRemoveFront();
  void testSearchThird();
  void testRemoveOnEmpty();
  LinkedListOfInts lnkList;
  std::vector<int> currentContents;
};

#endif
