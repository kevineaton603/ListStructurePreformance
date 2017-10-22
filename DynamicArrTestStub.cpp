///*
//*	Author:				Andrew Rimpici, Kevin Eaton
//*	Class:				Data Structures and Algorithms CSI-281-01
//*	Assignment:			PA5
//*	Date Assigned:		10/16/2017
//*	Due Date:			10/19/2017
//*
//*	Description:
//*		A program that tests the insertion and deletion of different data structures.
//*
//*	Certification of Authenticity:
//*		I certify that this is entirely my own work, except where I have given fully-documented
//*		references to the work of others. I understand the definition and consequences of plagiarism
//*		and acknowledge that the assessor of this assignment may, for the purpose of assessing this
//*		assignment:-Reproduce  this  assignment  and  provide  a  copy  to  another  member  of
//*		academic staff; and/or-Communicate a copy of this assignment to a plagiarism checking
//*		service (which may then retain a copy of this assignment on its database for the purpose
//*		of future plagiarism checking)
//*/
//
//#include "DynamicArrayList.h"
//
//int main()
//{
//	DynamicArrayList<int> dynamic = DynamicArrayList<int>();
//
//	std::cout << "Add testing: " << std::endl;
//	dynamic.add(0);
//	dynamic.add(1);
//	dynamic.add(2);
//	dynamic.add(3);
//	dynamic.add(4);
//	dynamic.add(5);
//	dynamic.add(6);
//	dynamic.add(7);
//	dynamic.add(8);
//	dynamic.add(9);
//	dynamic.add(10);
//	std::cin.get();
//
//	std::cout << "Remove testing: " << std::endl;
//	dynamic.remove(4);
//	dynamic.remove(0);
//	dynamic.remove(-1);
//	std::cin.get();
//
//	std::cout << "Set testing: " << std::endl;
//	dynamic.set(0, 100);
//	dynamic.set(1, -1);
//	dynamic.set(0, -2);
//	dynamic.set(8, 15);
//	dynamic.set(9, 20);
//	dynamic.set(-1, 1000);
//	std::cin.get();
//
//
//	DynamicArrayList<int> *first = new DynamicArrayList<int>();
//	first->add(5);
//	first->add(6);
//	first->add(8);
//	first->add(9);
//	std::cin.get();
//
//	DynamicArrayList<int> *second = new DynamicArrayList<int>();
//	second->add(3);
//	second->add(5);
//	second->add(6);
//	second->add(6);
//	second->add(7);
//	second->add(8);
//	second->add(9);
//	second->add(9);
//	second->add(10);
//	second->add(11);
//	std::cin.get();
//
//	DynamicArrayList<int> *merged = DynamicArrayList<int>::merge(first, second);
//	std::cin.get();
//
//	delete first;
//	delete second;
//	delete merged;
//
//	return 0;
//}