/*
*	Author:				Andrew Rimpici, Kevin Eaton
*	Class:				Data Structures and Algorithms CSI-281-01
*	Assignment:			PA5
*	Date Assigned:		10/19/2017
*	Due Date:			10/26/2017
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

/*#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
	DoublyLinkedList<int> *list1 = new DoublyLinkedList<int>();
	DoublyLinkedList<int> *list2 = new DoublyLinkedList<int>();
	DoublyLinkedList<int> *merge = new DoublyLinkedList<int>();

	//Testing append(T data)
	std::cout << "Testing append(T data)" << std::endl;
	list1->prepend(5);
	list1->prepend(4);
	list1->prepend(3);
	list1->prepend(2);
	list1->prepend(1);
	list1->print();

	//Testing prepend(T data)
	std::cout << "Testing prepend(T data)" << std::endl;
	list2->append(1);
	list2->append(2);
	list2->append(3);
	list2->append(4);
	list2->append(5);
	list2->print();

	//Testing insert(T data)
	std::cout << "Testing insert(T data)" << std::endl;
	list1->insert(-1);
	list1->insert(3);
	list1->insert(6);
	list1->print();

	//Testing insert(int index, T data)
	std::cout << "Testing insert(int index, T data)" << std::endl;
	list2->insert(0, -10);
	list2->insert(5, 4);
	list2->insert(-1, 5);
	list2->insert(9, 100);
	list2->print();

	//Testing removeAt(int index)
	std::cout << "Testing removeAt(int index)" << std::endl;
	list1->removeAt(0);
	list1->removeAt(3);
	list1->removeAt(list1->getLength());
	list1->print();

	//Testing clear()
	std::cout << "Testing clear()" << std::endl;
	list1->clear();
	list2->clear();
	list1->print();
	list2->print();

	//Testing isEmpty()
	std::cout << "Testing isEmpty()" << std::endl;
	std::cout << list1->isEmpty() << std::endl;
	list1->prepend(0);
	list1->prepend(1);
	list1->prepend(2);
	list1->prepend(3);
	list1->prepend(4);
	list1->prepend(5);
	std::cout << list1->isEmpty() << std::endl;

	list2->append(0);
	list2->append(1);
	list2->append(2);
	list2->append(3);
	list2->append(4);
	list2->append(5);

	//Testing sequentialSearch(T searchKey, bool isSorted)
	std::cout << "Testing sequentialSearch(T searchKey, bool isSorted)" << std::endl;
	list1->print();
	std::cout << list1->sequentialSearch(3, false) << std::endl;
	std::cout << list1->sequentialSearch(6, false) << std::endl;
	list2->print();
	std::cout << list2->sequentialSearch(3, true) << std::endl;
	std::cout << list2->sequentialSearch(6, true) << std::endl;

	list1->clear();
	list2->clear();

	list1->append(0);
	list1->append(2);
	list1->append(4);
	list1->append(6);
	list1->append(8);
	list1->append(10);

	list2->append(1);
	list2->append(3);
	list2->append(5);
	list2->append(7);
	list2->append(9);
	list2->append(11);

	//Testing merge(DoublyLinkedList<T> &list1, LinkedList<T> &list2)
	std::cout << "Testing merge(DoublyLinkedList<T> &list1, DoublyLinkedList<T> &list2)" << std::endl;
	DoublyLinkedList<int>::merge(*list1, *list2, *merge);
	merge->print();
	std::cin.get();

	delete list1;
	delete list2;
	delete merge;
	return 0;
}*/