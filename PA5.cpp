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
#include "DynamicArray.h"
#include "LinkedList.h"
#include <ctime>

int main()
{
	/*DynamicArray<int> list, list2;
	LinkedList<int> lList, lList2, *lList3;
	int *intArr;
	int num1;
	intArr = new int[10];
	srand(unsigned(time(NULL)));
	for (int i = 10; i > 0; i--)
	{
		num1 = rand() % 1000;
		std::cout << num1 << std::endl;
		lList.insert(num1);

	}
	lList.print();
	std::cout << "Int Array\n\n";
	for (int i = 0; i < 10; i++)
	{
		intArr[i] = rand() % 1000;
		std::cout << i << ": " << intArr[i] << std::endl;
		lList2.insert(intArr[i]);
	}

	std::cout << "List: \n\n";
	lList.print();

	std::cout << "List2: \n\n";
	lList2.print();

	std::cout << std::endl;
	lList3 = LinkedList<int>::merge(lList, lList2);
	lList3->print();
	std::cout << std::endl;
	lList.removeAt(9);
	lList.print();
	delete[] intArr;
	delete lList3;

	list.insert(0, 5);
	list.insert(1, 1);
	list.insert(1, 2); 
	list.print();
	std::cin.get();

	LinkedList<int> *insertionTest = new LinkedList<int>();

	insertionTest->insert(0, 1);
	insertionTest->insert(1, 3);
	insertionTest->insert(1, 5);
	insertionTest->print();
	std::cin.get();

	insertionTest->removeAt(1);
	insertionTest->print();
	std::cin.get();
	insertionTest->removeAt(1);
	insertionTest->print();
	std::cin.get();
	insertionTest->removeAt(0);
	insertionTest->print();
	std::cin.get();

	delete insertionTest;
	
	DynamicArray<int> *dynamicArr = new DynamicArray<int>();

	dynamicArr->insert(0, 5);
	dynamicArr->insert(1, 2);
	dynamicArr->insert(1, 3);
	dynamicArr->print();
	std::cin.get();

	dynamicArr->removeAt(1);
	dynamicArr->print();
	std::cin.get();
	dynamicArr->removeAt(1);
	dynamicArr->print();
	std::cin.get();
	dynamicArr->removeAt(0);
	dynamicArr->print();
	std::cin.get();

	delete dynamicArr;*/

	DynamicArray<int> *first = new DynamicArray<int>();
	DynamicArray<int> *second = new DynamicArray<int>();
	first->insert(0, 1);
	first->insert(1, 3);
	first->insert(2, 5);
	first->print();
	std::cin.get();

	second->insert(0, 2);
	second->insert(1, 4);
	second->insert(2, 6);
	second->print();
	std::cin.get();

	DynamicArray<int> *merged = DynamicArray<int>::merge(first, second);
	merged->print();
	std::cin.get();

	delete first;
	delete second;
	delete merged;

	return 0;
}