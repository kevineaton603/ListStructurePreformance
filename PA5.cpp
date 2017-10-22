#include <iostream>
#include "DynamicArray.h"
#include"dynamicArr.h"
#include"linkedList.h"
#include<ctime>

int main()
{
	
	DynamicArr<int> list, list2;
	LinkedList<int> lList, lList2, * lList3;
	int * intArr;
	int num1;
	intArr = new int[10];
	srand(unsigned(time(NULL)));
	for (int i = 10; i > 0; i--)
	{
		num1 = rand() % 1000;
		std::cout << num1 << std::endl;
		//list.insert(num1);
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
	/*mergeSort(intArr, 0, 9);
	std::cout << "Int Array\n\n";
	for (int i = 0; i < 10; i++)
	{
		//intArr[i] = rand() % 1000;
		std::cout << i << ": " << intArr[i] << std::endl;
	}
	std::cout << std::endl;*/
	std::cout << "List: \n\n";
	lList.print();
	//lList2.insert(intArr, 10);
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
}