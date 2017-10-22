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
#include"DynamicArray.h"
#include"LinkedList.h"
#include<ctime>

/*int main()
{
	DynamicArr<int> list, list2;
	LinkedList<int> lList, lList2, *lList3;
	int * intArr;
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
	return 0;
}*/