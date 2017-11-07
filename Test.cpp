#include "Test.h"

void Test::runTests()
{
  testIsEmpty();
  testSize();
  testSearchFirst();
  testAddBack();
  testAddFront();
  testIsEmptyAfterAdding();
  testSearchSecond();
  testRemoveBack();
  testRemoveFront();
  testAddBackOnceMore();
  testSearchThird();
  testRemoveOnEmpty();
}

void Test::testIsEmpty()
{
  std::cout << "Test 01: Tests to see if isEmpty on an empty list returns true\n";
  if (lnkList.isEmpty())
  {
    std::cout << "\tInitialized list is empty. isEmpty Test Passed.\n";
  }
  else
  {
    std::cout << "\tWe have a lot of problems. isEmpty Test Failed.\n";
  }
}

void Test::testSize()
{
  std::cout << "Test 02: Tests to see if size returns 0 on an empty list\n";
  if (lnkList.size() == 0)
  {
    std::cout << "\tInitialized list is has size 0. size Test Passed.\n";
  }
  else
  {
    std::cout << "\tWe have a lot of problems. size Test Failed.\n";
  }
}

void Test::testSearchFirst()
{
  std::cout << "Test 03: Tests to see if searching for values in an empty array returns false.\n";
  bool success = true;
  std::cout << "\tContents of list before first search: {";
  currentContents = lnkList.toVector();
  for (std::vector<int>::iterator it = currentContents.begin(); it != currentContents.end(); ++it)
  {
    std::cout << *it;
    if ((it+1) != currentContents.end())
    {
      std::cout << ",";
    }
  }
  std::cout << "}\n";

  if (lnkList.search(0) || lnkList.search(-50)||lnkList.search(50))
  {
    std::cout << "\tContent mismatch in first Search! Search found a value in an empty list\n";
    success = false;
  }
  if (success)
  {
    std::cout << "\tPassed first search. Found nothing in an empty list.\n";
  }
}

void Test::testAddBack()
{
std::cout << "Test 04: Tests to see if the size of the list is properly recorded when addBack is called. Also checks to make sure values are added in the correct order.\n";
  bool success = true;
  for (int i = 0; i < 5; i ++)
  {
    lnkList.addBack(i);
    if(lnkList.size() != (i+1))
    {
      std::cout << "\tSize mismatch in addBack! Expected: " <<(i+1)<< " Got: "<<lnkList.size()<<"\n";
      success = false;
    }
  }
  currentContents = lnkList.toVector();
  std::vector<int> compare = {0,1,2,3,4};
  if (currentContents != compare)
  {
    success = false;
    std::cout << "\tContent mismatch in addBack! Expected: {0,1,2,3,4} Got: {";
    for (std::vector<int>::iterator it = currentContents.begin(); it != currentContents.end(); ++it)
    {
      std::cout << *it;
      if ((it+1) != currentContents.end())
      {
        std::cout << ",";
      }
    }
    std::cout << "}\n";
  }

  if (success)
  {
    std::cout << "\tPassed addBack test.\n";
  }
}

void Test::testAddFront()
{
  std::cout << "Test 05: Tests to see if the size of the list is properly recorded when addFront is called. Also checks to make sure values are added in the correct order.\n";
  bool success = true;
  for (int i = 5; i < 10; i ++)
  {
    lnkList.addFront(i);
    if(lnkList.size() != (i+1))
    {
      std::cout << "\tSize mismatch in addFront! Expected: " <<(i+1)<< " Got: "<<lnkList.size()<<"\n";
      success = false;
    }
  }
  currentContents = lnkList.toVector();
  std::vector<int> compare = {9,8,7,6,5,4,3,2,1,0};
  if (currentContents != compare)
  {
    std::cout << "\tContent mismatch in addFront! Expected: {9,8,7,6,5,4,3,2,1,0} Got: {";
    for (std::vector<int>::iterator it = currentContents.begin(); it != currentContents.end(); ++it)
    {
      std::cout << *it;
      if ((it+1) != currentContents.end())
      {
        std::cout << ",";
      }
    }
    std::cout << "}\n";
  }
  if (success)
  {
    std::cout << "\tPassed addFront test.\n";
  }
}

void Test::testIsEmptyAfterAdding()
{
  std::cout << "Test 06: Tests to see if the list is empty after adding values.\n";
  if(lnkList.isEmpty())
  {
    std::cout << "\tReturn mismatch in isEmpty after adding values! Expected false, got true.\n";
  }
  else
  {
    std::cout << "\tPassed isEmpty after adding values test.\n";
  }
}

void Test::testSearchSecond()
{
  std::cout << "Test 07: Tests to see if search returns true correctly for values in the list, and false for ones that are not\n";
  bool success = true;
  std::cout << "\tContents of list before second search: {";
  currentContents = lnkList.toVector();
  for (std::vector<int>::iterator it = currentContents.begin(); it != currentContents.end(); ++it)
  {
    std::cout << *it;
    if ((it+1) != currentContents.end())
    {
      std::cout << ",";
    }
  }
  std::cout << "}\n";

  for (int i = 0; i < 8; i++)
  {
    if (!lnkList.search(i))
    {
      std::cout << "\tContent mismatch in second Search! Did not find " << i << " that should be in list.\n";
      success = false;
    }
  }
  if (lnkList.search(10) || lnkList.search(-10))
  {
    std::cout << "\tContent mismatch in second Search! Found a value that should not be in list.\n";
    success = false;
  }
  if (success)
  {
    std::cout << "\tPassed second search\n";
  }
}

void Test::testRemoveBack()
{
  std::cout << "Test 08: Tests to see if the size of the list is properly recorded when removeBack is called. Also checks to make sure values are removed from the correct end.\n";
  bool success = true;
  for (int i = 1; i <= 3; i++)
  {
    if(!lnkList.removeBack())
    {
      std::cout << "\tReturn mismatch in removeBack! Expected true, got false.\n";
    }
    if (lnkList.size() != 10-i)
    {
      std::cout << "\tSize mismatch in removeBack! Expected: " <<(10-i)<< " Got: "<<lnkList.size()<<"\n";
      success = false;
    }
  }
  currentContents = lnkList.toVector();
  std::vector<int> compare = {9,8,7,6,5,4,3};
  if (currentContents != compare)
  {
    std::cout << "\tContent mismatch in removeBack! Expected: {9,8,7,6,5,4,3} Got: {";
    for (std::vector<int>::iterator it = currentContents.begin(); it != currentContents.end(); ++it)
    {
      std::cout << *it;
      if ((it+1) != currentContents.end())
      {
        std::cout << ",";
      }
    }
    std::cout << "}\n";
  }
  if (success)
  {
    std::cout <<"\tPassed removeBack test.\n";
  }
}

void Test::testRemoveFront()
{
  std::cout << "Test 09: Tests to see if the size of the list is properly recorded when removeFront is called. Also checks to make sure values are removed from the correct end.\n";
  bool success = true;
  for (int i = 1; i <= 3; i++)
  {
    if(!lnkList.removeFront())
    {
      std::cout << "\tReturn mismatch in removeFront! Expected true, got false.\n";
    }
    //removeBack is broken, so size is still 10
    if (lnkList.size() != 10-i)
    {
      std::cout << "\tSize mismatch in removeFront! Expected: " <<(10-i)<< " Got: "<<lnkList.size()<<"\n";
      success = false;
    }
  }
  currentContents = lnkList.toVector();
  //Remove back is broken, so we expect the last three values to still be there
  std::vector<int> compare = {6,5,4,3,2,1,0};
  if (currentContents != compare)
  {
    std::cout << "\tContent mismatch in removeFront! Expected: {6,5,4,3,2,1,0} Got: {";
    for (std::vector<int>::iterator it = currentContents.begin(); it != currentContents.end(); ++it)
    {
      std::cout << *it;
      if ((it+1) != currentContents.end())
      {
        std::cout << ",";
      }
    }
    std::cout << "}\n";
  }
  if (success)
  {
    std::cout <<"\tPassed removeFront test.\n";
  }
}

void Test::testAddBackOnceMore()
{
  std::cout << "Test 10: Tests to confirm that addBack is consistently broken\n";
  bool success = true;
  lnkList.addBack(42);
  if (lnkList.size() != 11)
  {
    std::cout << "\tSize mismatch in AddBackOnceMore! Expected 11,  got " << lnkList.size()<< '\n';
    success = false;
  }
  currentContents = lnkList.toVector();
  //Both removes are broken. All of the values are still there
  std::vector<int> compare = {42,9,8,7,6,5,4,3,2,1,0};
  if (currentContents != compare)
  {
    success = false;
    std::cout << "\tContent mismatch in AddBackOnceMore! Expected {42,9,8,7,6,5,4,3,2,1,0}. Got {";
    for (std::vector<int>::iterator it = currentContents.begin(); it != currentContents.end(); ++it)
    {
      std::cout << *it;
      if ((it+1) != currentContents.end())
      {
        std::cout << ",";
      }
    }
    std::cout << "}\n";
  }
  if (success)
  {
    std::cout << "\tAt least addBack is consistently broken." << '\n';
  }
}


void Test::testSearchThird()
{
  std::cout << "Test 11: Tests to check if values that should have been removed but weren't can be found. Also checks for values that are still in the list.\n";
  bool success = true;
  std::cout << "\tContents of list before third search: {";
  currentContents = lnkList.toVector();
  for (std::vector<int>::iterator it = currentContents.begin(); it != currentContents.end(); ++it)
  {
    std::cout << *it;
    if ((it+1) != currentContents.end())
    {
      std::cout << ",";
    }
  }
  std::cout << "}\n";
  //Test values that would be removed if remove Front/Back worked
  if (!lnkList.search(9) || !lnkList.search(8) || !lnkList.search(7) || !lnkList.search(2) || !lnkList.search(1) || !lnkList.search(0) )
  {
    std::cout << "\tConsistency mismatch in third search. Did not find a value that was not removed.\n";
  }
  //Test values definitely still in array
  if (!lnkList.search(6) || !lnkList.search(5) || !lnkList.search(4) || !lnkList.search(3) )
  {
    std::cout << "\tConsistency mismatch in third search. Did not find a value that should still be there.\n";
  }
  //Test values never in array
  if (lnkList.search(10) || lnkList.search(-10) )
  {
    std::cout << "\tContent mismatch in third search. Found a value that was never added.\n";
  }
  if (success)
  {
    std::cout << "\tPassed third search\n";
  }
}

void Test::testRemoveOnEmpty()
{
  std::cout << "Test 12: Tests to see if removeBack and removeFront return false on an empty list\n";
  LinkedListOfInts emptyList;
  if (emptyList.removeBack())
  {
    std::cout << "\tReturn mismatch in testRemoveOnEmpty with removeBack. Expected false, got true";
  }
  else if (emptyList.removeFront())
  {
    std::cout << "\tReturn mismatch in testRemoveOnEmpty with removeFront. Expected false, got true";
  }
  else
  {
    std::cout << "\tRemove on emptyList test Passed.\n";
  }
}
