#include <iostream>

#include"linkedList.h"
int main()
{
	LinkedList<long> list;
	for (int i = 1000; i >= 0; i--)
	{
		list.insert(i);
	}
	for (int i = 1000; i < 2000; i++)
	{
		list.insert(i);
	}
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
	return 0;
}