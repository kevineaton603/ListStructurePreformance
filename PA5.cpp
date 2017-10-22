#include <iostream>
#include "DynamicArray.h"
#include"dynamicArr.h"
#include"linkedList.h"
#include<ctime>

int main()
{
	
	DynamicArr<int> list, list2;
	int * intArr;
	int num1;
	intArr = new int[1000];
	srand(unsigned(time(NULL)));
	for (int i = 10; i > 0; i--)
	{
		num1 = rand() % 1000;
		std::cout << num1 << std::endl;
		list.insert(num1);
		
	}
	list.print();
	std::cout << "Int Array\n\n";
	for (int i = 0; i < 10; i++)
	{
		intArr[i] = rand() % 1000;
		std::cout << i << ": " << intArr[i] << std::endl;
	}
	mergeSort(intArr, 0, 9);
	std::cout << "Int Array\n\n";
	for (int i = 0; i < 10; i++)
	{
		//intArr[i] = rand() % 1000;
		std::cout << i << ": " << intArr[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "List: \n\n";
	list.print();
	list2.insert(intArr, 10);
	std::cout << "List2: \n\n";
	list2.print();
	std::cout << std::endl;
	std::cout << std::endl;
	list.insert(list2);
	list.print();
	/*
	LinkedList<long> list;
	DynamicArray<long> dynamic;

	for (int i = 1000; i >= 0; i--)
	{
		list.insert(i);
		dynamic.add(i);
	}
	for (int i = 1000; i < 2000; i++)
	{
		list.insert(i);
		dynamic.add(i);
	}
	std::cout << dynamic[3] << std::endl;
	list.print();
	for (int i = 1950; i < 2000; i++)
	{
		list.remove(i);
	}
	list.print();
	for (long i = 1900; i < 1950; i++)
	{
		list.removeAt(i);
	}
	list.print();
	*/
	delete[] intArr;
	return 0;
}