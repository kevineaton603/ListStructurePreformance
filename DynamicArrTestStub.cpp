#include <iostream>
#include "DynamicArray.h"

int main()
{
	DynamicArray<int> dynamic = DynamicArray<int>();

	std::cout << "Add testing: " << std::endl;
	dynamic.add(0);
	dynamic.add(1);
	dynamic.add(2);
	dynamic.add(3);
	dynamic.add(4);
	dynamic.add(5);
	dynamic.add(6);
	dynamic.add(7);
	dynamic.add(8);
	dynamic.add(9);
	dynamic.add(10);
	std::cin.get();

	std::cout << "Remove testing: " << std::endl;
	dynamic.remove(4);
	dynamic.remove(0);
	dynamic.remove(-1);
	std::cin.get();

	std::cout << "Set testing: " << std::endl;
	dynamic.set(0, 100);
	dynamic.set(1, -1);
	dynamic.set(0, -2);
	dynamic.set(-1, 1000);
	std::cin.get();

	return 0;
}