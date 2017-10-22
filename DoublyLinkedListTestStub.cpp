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

#include "DoublyLinkedList.h"

int main()
{
	DoublyLinkedList<int> *first = new DoublyLinkedList<int>();
	first->insert(5);
	first->insert(6);
	first->insert(8);
	first->insert(9);

	DoublyLinkedList<int> *second = new DoublyLinkedList<int>();
	second->insert(3);
	second->insert(6);
	second->insert(7);
	second->insert(9);
	second->insert(10);
	second->insert(11);

	first->printListAscending();
	second->printListAscending();

	DoublyLinkedList<int> *merged = DoublyLinkedList<int>::merge(first, second);
	merged->printListAscending();
	std::cin.get();

	delete first;
	delete second;
	delete merged;

	return 0;
}