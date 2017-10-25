/*
*	Author:				Andrew Rimpici, Kevin Eaton
*	Class:				Data Structures and Algorithms CSI-281-01
*	Assignment:			PA5
*	Date Assigned:		10/16/2017
*	Due Date:			10/19/2017
*
*	Description:
*		A program that tests the insertion and deletion of different data structures.
*
*	Certification of Authenticity:
*		I certify that this is entirely my own work, except where I have given fully-documented
*		references to the work of others. I understand the definition and consequences of plagiarism
*		and acknowledge that the assessor of this assignment may, for the purpose of assessing this
*		assignment:-Reproduce  this  assignment  and  provide  a  copy  to  another  member  of
*		academic staff; and/or-Communicate a copy of this assignment to a plagiarism checking
*		service (which may then retain a copy of this assignment on its database for the purpose
*		of future plagiarism checking)
*/

#include <iostream>
#include <fstream>
#include <ctime>

#include "DynamicArray.h"
#include "DynamicArrayList.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"

//int main()
//{
	/* What are we testing?
	 * We are testing difference between Linked Lists, Doubly Linked Lists, Dynamic Arrays, and Dynamic ArrayLists for
	 * insertion (Three tests: Front, Back, In Order) 
	 * deletion (Three tests: Front, Back, Middle)
	 * merging (One Test: Merging two ordered lists)
	 * searching (Two Tests Sequential Search: Sorted, Unsorted)
	 *
	 * The above test will be run three times and all of the results will be recorded to a file.
	 * Insertion Total of 3 * 4 * 3 = 36 Tests
	 * Deletion Total of 3 * 4 * 3 = 36 Tests
	 * Merging Total of 1 * 4 * 3 = 12 Tests
	 * Searching Total of 2 * 4 * 3 = 24 Tests
	 * Total of 108 tests. 16 Appendix Charts and 4 extra Charts for Average Charts.
	 */

	/*DoublyLinkedList<int> *second = new DoublyLinkedList<int>();
	second->insert(0, 3);
	second->insert(0, 6);
	second->insert(0, 7);
	second->insert(0, 9);
	second->insert(0, 10);
	second->insert(0, 11);

	std::cout << "Found = " << second->sequentialSearch(3, false);
	std::cin.get();

	DynamicArrayList<int> *first = new DynamicArrayList<int>();
	first->insert(5);
	first->insert(0);
	first->insert(-1);
	first->insert(9);

	std::cout << "Found = " << first->sequentialSearch(9, false);
	std::cin.get();

	LinkedList<int> *insertionTest = new LinkedList<int>();
	insertionTest->insert(0, 1);
	insertionTest->insert(1, 3);
	insertionTest->insert(3, 5);
	insertionTest->print();

	std::cout << "Found = " << insertionTest->sequentialSearch(4, true);
	std::cin.get();

	DynamicArray<int> *dynamicArr = new DynamicArray<int>();
	dynamicArr->insert(0, 5);
	dynamicArr->insert(0, 2);
	dynamicArr->insert(1, 3);
	dynamicArr->print();

	std::cout << "Found = " << dynamicArr->sequentialSearch(3, true);
	std::cin.get();

	delete second;
	delete first;
	delete insertionTest;
	delete dynamicArr;

	return 0;
}*/