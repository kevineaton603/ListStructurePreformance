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

#include <iostream>
#include <fstream>
#include <sstream>

#include "DynamicArray.h"
#include "DynamicArrayList.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"

#include "timerSystem.h"

const int SIZE1 = 1000;
const int SIZE2 = 10000;
const int SIZE3 = 100000;
const std::string FILE_NAME = "results_1000_10000_100000.txt";

void printToFile(std::string resultsHeader, double runtime)
{
	const int PRECISION = 4;

	std::ofstream outputFile;
	std::ostringstream outputStream;
	outputStream.setf(std::ios::scientific);
	outputStream.precision(PRECISION);

	if (!outputFile.is_open())
	{
		outputFile.open(FILE_NAME, std::fstream::app);
		outputStream << resultsHeader << " " << runtime << "\n";

		outputFile << outputStream.str();
		std::cout << outputStream.str() << "\n" << std::endl;

		outputFile.close();
	}
}

template <typename T>
double insertFront(LinkedList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->prepend(i);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double insertMiddle(LinkedList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->insert(list->getLength() / 2, i);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double insertEnd(LinkedList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->append(i);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double deleteFront(LinkedList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->removeAt(0);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double deleteMiddle(LinkedList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->removeAt(list->getLength() / 2);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double deleteEnd(LinkedList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->removeAt(list->getLength() - 1);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double merge(LinkedList<T> *linkedList1, LinkedList<T> *linkedList2, LinkedList<T> *mergedLinkedList, int size)
{
	TimerSystem timer;
	double runtime;

	timer.startClock();
	LinkedList<T>::merge(*linkedList1, *linkedList2, *mergedLinkedList);
	runtime = timer.getTime();

	linkedList1->clear();
	linkedList2->clear();
	mergedLinkedList->clear();

	return runtime;
}

template <typename T>
double search(LinkedList<T> *linkedList1, T searchKey)
{
	TimerSystem timer;
	double runtime;

	timer.startClock();
	linkedList1->sequentialSearch(searchKey, true);
	runtime = timer.getTime();

	return runtime;
}


template <typename T>
double insertFront(DoublyLinkedList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->prepend(i);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double insertMiddle(DoublyLinkedList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->insert(list->getLength() / 2, i);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double insertEnd(DoublyLinkedList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->append(i);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double deleteFront(DoublyLinkedList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->removeAt(0);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double deleteMiddle(DoublyLinkedList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->removeAt(list->getLength() / 2);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double deleteEnd(DoublyLinkedList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->removeAt(list->getLength() - 1);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double merge(DoublyLinkedList<T> *linkedList1, DoublyLinkedList<T> *linkedList2, DoublyLinkedList<T> *mergedLinkedList, int size)
{
	TimerSystem timer;
	double runtime;

	timer.startClock();
	DoublyLinkedList<T>::merge(*linkedList1, *linkedList2, *mergedLinkedList);
	runtime = timer.getTime();

	linkedList1->clear();
	linkedList2->clear();
	mergedLinkedList->clear();

	return runtime;
}

template <typename T>
double search(DoublyLinkedList<T> *linkedList1, T searchKey)
{
	TimerSystem timer;
	double runtime;

	timer.startClock();
	linkedList1->sequentialSearch(searchKey, true);
	runtime = timer.getTime();

	return runtime;
}


template <typename T>
double insertFront(DynamicArray<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->prepend(i);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double insertMiddle(DynamicArray<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->insert(list->getSize() / 2, i);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double insertEnd(DynamicArray<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->append(i);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double deleteFront(DynamicArray<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->removeAt(0);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double deleteMiddle(DynamicArray<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->removeAt(list->getSize() / 2);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double deleteEnd(DynamicArray<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->removeAt(list->getSize() - 1);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double merge(DynamicArray<T> *list1, DynamicArray<T> *list2, DynamicArray<T> *mergedList, int size)
{
	TimerSystem timer;
	double runtime;

	timer.startClock();
	DynamicArray<T>::merge(*list1, *list2, *mergedList);
	runtime = timer.getTime();

	list1->clear();
	list2->clear();
	mergedList->clear();

	return runtime;
}

template <typename T>
double search(DynamicArray<T> *list, T searchKey)
{
	TimerSystem timer;
	double runtime;

	timer.startClock();
	list->sequentialSearch(searchKey, true);
	runtime = timer.getTime();

	return runtime;
}



template <typename T>
double insertFront(DynamicArrayList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->prepend(i);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double insertMiddle(DynamicArrayList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();

	list->clear();
	for (i = 0; i < size; ++i)
	{
		list->insert((list->getSize()) / 2, i);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double insertEnd(DynamicArrayList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->append(i);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double deleteFront(DynamicArrayList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();

	for (i = 0; i < size; ++i)
	{
		list->removeAt(0);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double deleteMiddle(DynamicArrayList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->removeAt((list->getSize()) / 2);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double deleteEnd(DynamicArrayList<T> *list, int size)
{
	TimerSystem timer;
	double runtime;
	int i;

	timer.startClock();
	for (i = 0; i < size; ++i)
	{
		list->removeAt(0);
	}
	runtime = timer.getTime();

	return runtime;
}

template <typename T>
double merge(DynamicArrayList<T> *list1, DynamicArrayList<T> *list2, DynamicArrayList<T> *mergedList, int size)
{
	TimerSystem timer;
	double runtime;

	timer.startClock();
	DynamicArrayList<T>::merge(*list1, *list2, *mergedList);
	runtime = timer.getTime();

	list1->clear();
	list2->clear();
	mergedList->clear();

	return runtime;
}

template <typename T>
double search(DynamicArrayList<T> *list, T searchKey)
{
	TimerSystem timer;
	double runtime;

	timer.startClock();
	list->sequentialSearch(searchKey, true);
	runtime = timer.getTime();

	return runtime;
}


int main()
{
	/* What are we testing?
	 * We are testing difference between Linked Lists, Doubly Linked Lists, Dynamic Arrays, and Dynamic ArrayLists for
	 * insertion (Three tests: Front, Middle, End) 
	 * deletion (Three tests: Front, Middle, End)
	 * merging (One Test: Merging two ordered lists)
	 * searching (One Test Sequential Search: Sorted)
	 *
	 * The above test will be run three times and all of the results will be recorded to a file.
	 * Insertion Total of 3 * 4 * 3 = 36 Tests
	 * Deletion Total of 3 * 4 * 3 = 36 Tests
	 * Merging Total of 1 * 4 * 3 = 12 Tests
	 * Searching Total of 2 * 4 * 3 = 24 Tests
	 */

	for (int i = 0; i < 3; ++i)
	{
		printToFile("LINKED LIST TESTING\n\n", i);

		LinkedList<int> *linkedList = new LinkedList<int>();

		//////////////////////////////////////////////////////////////////
		//Linked List : Size 1 : Insertion/Deletion : Front
		//////////////////////////////////////////////////////////////////
		printToFile("LinkedList : Size 1 : Insertion : Front : ",
			insertFront(linkedList, SIZE1));

		printToFile("LinkedList : Size 1 : Deletion : Front : ",
			deleteFront(linkedList, SIZE1));

		//////////////////////////////////////////////////////////////////
		//Linked List : Size 1 : Insertion/Deletion : Middle
		//////////////////////////////////////////////////////////////////
		printToFile("LinkedList : Size 1 : Insertion : Middle : ",
			insertMiddle(linkedList, SIZE1));

		printToFile("LinkedList : Size 1 : Deletion : Middle : ",
			deleteMiddle(linkedList, SIZE1));

		//////////////////////////////////////////////////////////////////
		//Linked List : Size 1 : Insertion/Deletion : End
		//////////////////////////////////////////////////////////////////
		printToFile("LinkedList : Size 1 : Insertion : End : ",
			insertEnd(linkedList, SIZE1));

		printToFile("LinkedList : Size 1 : Deletion : End : ",
			deleteEnd(linkedList, SIZE1));

		//////////////////////////////////////////////////////////////////
		//Linked List : Size 2 : Insertion/Deletion : Front
		//////////////////////////////////////////////////////////////////
		printToFile("LinkedList : Size 2 : Insertion : Front : ",
			insertFront(linkedList, SIZE2));

		printToFile("LinkedList : Size 2 : Deletion : Front : ",
			deleteFront(linkedList, SIZE2));

		//////////////////////////////////////////////////////////////////
		//Linked List : Size 2 : Insertion/Deletion : Middle
		//////////////////////////////////////////////////////////////////
		printToFile("LinkedList : Size 2 : Insertion : Middle : ",
			insertMiddle(linkedList, SIZE2));

		printToFile("LinkedList : Size 2 : Deletion : Middle : ",
			deleteMiddle(linkedList, SIZE2));

		//////////////////////////////////////////////////////////////////
		//Linked List : Size 2 : Insertion/Deletion : End
		//////////////////////////////////////////////////////////////////
		printToFile("LinkedList : Size 2 : Insertion : End : ",
			insertEnd(linkedList, SIZE2));

		printToFile("LinkedList : Size 2 : Deletion : End : ",
			deleteEnd(linkedList, SIZE2));


		//////////////////////////////////////////////////////////////////
		//Linked List : Size 3 : Insertion/Deletion : Front
		//////////////////////////////////////////////////////////////////
		printToFile("LinkedList : Size 3 : Insertion : Front : ",
			insertFront(linkedList, SIZE3));

		printToFile("LinkedList : Size 3 : Deletion : Front : ",
			deleteFront(linkedList, SIZE3));

		//////////////////////////////////////////////////////////////////
		//Linked List : Size 3 : Insertion/Deletion : Middle
		//////////////////////////////////////////////////////////////////
		printToFile("LinkedList : Size 3 : Insertion : Middle : ",
			insertMiddle(linkedList, SIZE3));

		printToFile("LinkedList : Size 3 : Deletion : Middle : ",
			deleteMiddle(linkedList, SIZE3));

		//////////////////////////////////////////////////////////////////
		//Linked List : Size 3 : Insertion/Deletion : End
		//////////////////////////////////////////////////////////////////
		printToFile("LinkedList : Size 3 : Insertion : End : ",
			insertEnd(linkedList, SIZE3));

		printToFile("LinkedList : Size 3 : Deletion : End : ",
			deleteEnd(linkedList, SIZE3));

		delete linkedList;

		LinkedList<int> *linkedList1 = new LinkedList<int>();
		LinkedList<int> *linkedList2 = new LinkedList<int>();
		LinkedList<int> *mergedLinkedList = new LinkedList<int>();

		//////////////////////////////////////////////////////////////////
		//Linked List : Size 1 : Search/Merge 
		//////////////////////////////////////////////////////////////////
		insertEnd(linkedList1, SIZE1);
		insertEnd(linkedList2, SIZE1);

		printToFile("LinkedList : Size 1 : Search : ",
			search(linkedList1, SIZE1 / 2));

		printToFile("LinkedList : Size 1 : Merge : ",
			merge(linkedList1, linkedList2, mergedLinkedList, SIZE1));

		//////////////////////////////////////////////////////////////////
		//Linked List : Size 2 : Search/Merge
		//////////////////////////////////////////////////////////////////
		insertEnd(linkedList1, SIZE2);
		insertEnd(linkedList2, SIZE2);

		printToFile("LinkedList : Size 2 : Search : ",
			search(linkedList1, SIZE2 / 2));

		printToFile("LinkedList : Size 2 : Merge : ",
			merge(linkedList1, linkedList2, mergedLinkedList, SIZE2));

		//////////////////////////////////////////////////////////////////
		//Linked List : Size 3 : Search/Merge
		//////////////////////////////////////////////////////////////////
		insertEnd(linkedList1, SIZE3);
		insertEnd(linkedList2, SIZE3);

		printToFile("LinkedList : Size 3 : Search : ",
			search(linkedList1, SIZE3 / 2));

		printToFile("LinkedList : Size 3 : Merge : ",
			merge(linkedList1, linkedList2, mergedLinkedList, SIZE3));

		delete linkedList1;
		delete linkedList2;
		delete mergedLinkedList;

		////////////////////////////////////////////////////////////////////////////

		printToFile("DOUBLY LINKED LIST TESTING\n\n", i);

		DoublyLinkedList<int> *doublyLinkedList = new DoublyLinkedList<int>();

		//////////////////////////////////////////////////////////////////
		//DoublyLinkedList : Size 1 : Insertion/Deletion : Front
		//////////////////////////////////////////////////////////////////
		printToFile("DoublyLinkedList : Size 1 : Insertion : Front : ",
			insertFront(doublyLinkedList, SIZE1));

		printToFile("DoublyLinkedList : Size 1 : Deletion : Front : ",
			deleteFront(doublyLinkedList, SIZE1));

		//////////////////////////////////////////////////////////////////
		//DoublyLinkedList : Size 1 : Insertion/Deletion : Middle
		//////////////////////////////////////////////////////////////////
		printToFile("DoublyLinkedList : Size 1 : Insertion : Middle : ",
			insertMiddle(doublyLinkedList, SIZE1));

		printToFile("DoublyLinkedList : Size 1 : Deletion : Middle : ",
			deleteMiddle(doublyLinkedList, SIZE1));

		//////////////////////////////////////////////////////////////////
		//DoublyLinkedList : Size 1 : Insertion/Deletion : End
		//////////////////////////////////////////////////////////////////
		printToFile("DoublyLinkedList : Size 1 : Insertion : End : ",
			insertEnd(doublyLinkedList, SIZE1));

		printToFile("DoublyLinkedList : Size 1 : Deletion : End : ",
			deleteEnd(doublyLinkedList, SIZE1));

		//////////////////////////////////////////////////////////////////
		//DoublyLinkedList : Size 2 : Insertion/Deletion : Front
		//////////////////////////////////////////////////////////////////
		printToFile("DoublyLinkedList : Size 2 : Insertion : Front : ",
			insertFront(doublyLinkedList, SIZE2));

		printToFile("DoublyLinkedList : Size 2 : Deletion : Front : ",
			deleteFront(doublyLinkedList, SIZE2));

		//////////////////////////////////////////////////////////////////
		//DoublyLinkedList : Size 2 : Insertion/Deletion : Middle
		//////////////////////////////////////////////////////////////////
		printToFile("DoublyLinkedList : Size 2 : Insertion : Middle : ",
			insertMiddle(doublyLinkedList, SIZE2));

		printToFile("DoublyLinkedList : Size 2 : Deletion : Middle : ",
			deleteMiddle(doublyLinkedList, SIZE2));

		//////////////////////////////////////////////////////////////////
		//DoublyLinkedList : Size 2 : Insertion/Deletion : End
		//////////////////////////////////////////////////////////////////
		printToFile("DoublyLinkedList : Size 2 : Insertion : End : ",
			insertEnd(doublyLinkedList, SIZE2));

		printToFile("DoublyLinkedList : Size 2 : Deletion : End : ",
			deleteEnd(doublyLinkedList, SIZE2));


		//////////////////////////////////////////////////////////////////
		//DoublyLinkedList : Size 3 : Insertion/Deletion : Front
		//////////////////////////////////////////////////////////////////
		printToFile("DoublyLinkedList : Size 3 : Insertion : Front : ",
			insertFront(doublyLinkedList, SIZE3));

		printToFile("DoublyLinkedList : Size 3 : Deletion : Front : ",
			deleteFront(doublyLinkedList, SIZE3));

		//////////////////////////////////////////////////////////////////
		//DoublyLinkedList : Size 3 : Insertion/Deletion : Middle
		//////////////////////////////////////////////////////////////////
		printToFile("DoublyLinkedList : Size 3 : Insertion : Middle : ",
			insertMiddle(doublyLinkedList, SIZE3));

		printToFile("DoublyLinkedList : Size 3 : Deletion : Middle : ",
			deleteMiddle(doublyLinkedList, SIZE3));

		//////////////////////////////////////////////////////////////////
		//DoublyLinkedList : Size 3 : Insertion/Deletion : End
		//////////////////////////////////////////////////////////////////
		printToFile("DoublyLinkedList : Size 3 : Insertion : End : ",
			insertEnd(doublyLinkedList, SIZE3));

		printToFile("DoublyLinkedList : Size 3 : Deletion : End : ",
			deleteEnd(doublyLinkedList, SIZE3));

		delete doublyLinkedList;

		DoublyLinkedList<int> *doublyLinkedList1 = new DoublyLinkedList<int>();
		DoublyLinkedList<int> *doublyLinkedList2 = new DoublyLinkedList<int>();
		DoublyLinkedList<int> *doublyMergedLinkedList = new DoublyLinkedList<int>();

		//////////////////////////////////////////////////////////////////
		//DoublyLinkedList : Size 1 : Search/Merge 
		//////////////////////////////////////////////////////////////////
		insertEnd(doublyLinkedList1, SIZE1);
		insertEnd(doublyLinkedList2, SIZE1);

		printToFile("DoublyLinkedList : Size 1 : Search : ",
			search(doublyLinkedList1, SIZE1 / 2));

		printToFile("DoublyLinkedList : Size 1 : Merge : ",
			merge(doublyLinkedList1, doublyLinkedList2, doublyMergedLinkedList, SIZE1));

		//////////////////////////////////////////////////////////////////
		//DoublyLinkedList : Size 2 : Search/Merge
		//////////////////////////////////////////////////////////////////
		insertEnd(doublyLinkedList1, SIZE2);
		insertEnd(doublyLinkedList2, SIZE2);

		printToFile("DoublyLinkedList : Size 2 : Search : ",
			search(doublyLinkedList1, SIZE2 / 2));

		printToFile("DoublyLinkedList : Size 2 : Merge : ",
			merge(doublyLinkedList1, doublyLinkedList2, doublyMergedLinkedList, SIZE2));

		//////////////////////////////////////////////////////////////////
		//DoublyLinkedList : Size 3 : Search/Merge
		//////////////////////////////////////////////////////////////////
		insertEnd(doublyLinkedList1, SIZE3);
		insertEnd(doublyLinkedList2, SIZE3);

		printToFile("DoublyLinkedList : Size 3 : Search : ",
			search(doublyLinkedList1, SIZE3 / 2));

		printToFile("DoublyLinkedList : Size 3 : Merge : ",
			merge(doublyLinkedList1, doublyLinkedList2, doublyMergedLinkedList, SIZE3));

		delete doublyLinkedList1;
		delete doublyLinkedList2;
		delete doublyMergedLinkedList;

		////////////////////////////////////////////////////////////////////////////

		printToFile("DYNAMIC ARRAY TESTING\n\n", i);

		DynamicArray<int> *dynamicArray = new DynamicArray<int>();

		//////////////////////////////////////////////////////////////////
		//DynamicArray : Size 1 : Insertion/Deletion : Front
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArray : Size 1 : Insertion : Front : ",
			insertFront(dynamicArray, SIZE1));

		printToFile("DynamicArray : Size 1 : Deletion : Front : ",
			deleteFront(dynamicArray, SIZE1));

		//////////////////////////////////////////////////////////////////
		//DynamicArray : Size 1 : Insertion/Deletion : Middle
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArray : Size 1 : Insertion : Middle : ",
			insertMiddle(dynamicArray, SIZE1));

		printToFile("DynamicArray : Size 1 : Deletion : Middle : ",
			deleteMiddle(dynamicArray, SIZE1));

		//////////////////////////////////////////////////////////////////
		//DynamicArray : Size 1 : Insertion/Deletion : End
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArray : Size 1 : Insertion : End : ",
			insertEnd(dynamicArray, SIZE1));

		printToFile("DynamicArray : Size 1 : Deletion : End : ",
			deleteEnd(dynamicArray, SIZE1));

		//////////////////////////////////////////////////////////////////
		//DynamicArray : Size 2 : Insertion/Deletion : Front
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArray : Size 2 : Insertion : Front : ",
			insertFront(dynamicArray, SIZE2));

		printToFile("DynamicArray : Size 2 : Deletion : Front : ",
			deleteFront(dynamicArray, SIZE2));

		//////////////////////////////////////////////////////////////////
		//DynamicArray : Size 2 : Insertion/Deletion : Middle
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArray : Size 2 : Insertion : Middle : ",
			insertMiddle(dynamicArray, SIZE2));

		printToFile("DynamicArray : Size 2 : Deletion : Middle : ",
			deleteMiddle(dynamicArray, SIZE2));

		//////////////////////////////////////////////////////////////////
		//DynamicArray : Size 2 : Insertion/Deletion : End
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArray : Size 2 : Insertion : End : ",
			insertEnd(dynamicArray, SIZE2));

		printToFile("DynamicArray : Size 2 : Deletion : End : ",
			deleteEnd(dynamicArray, SIZE2));


		//////////////////////////////////////////////////////////////////
		//DynamicArray : Size 3 : Insertion/Deletion : Front
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArray : Size 3 : Insertion : Front : ",
			insertFront(dynamicArray, SIZE3));

		printToFile("DynamicArray : Size 3 : Deletion : Front : ",
			deleteFront(dynamicArray, SIZE3));

		//////////////////////////////////////////////////////////////////
		//DynamicArray : Size 3 : Insertion/Deletion : Middle
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArray : Size 3 : Insertion : Middle : ",
			insertMiddle(dynamicArray, SIZE3));

		printToFile("DynamicArray : Size 3 : Deletion : Middle : ",
			deleteMiddle(dynamicArray, SIZE3));

		//////////////////////////////////////////////////////////////////
		//DynamicArray : Size 3 : Insertion/Deletion : End
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArray : Size 3 : Insertion : End : ",
			insertEnd(dynamicArray, SIZE3));

		printToFile("DynamicArray : Size 3 : Deletion : End : ",
			deleteEnd(dynamicArray, SIZE3));

		delete dynamicArray;

		DynamicArray<int> *dynamicArray1 = new DynamicArray<int>();
		DynamicArray<int> *dynamicArray2 = new DynamicArray<int>();
		DynamicArray<int> *dynamicArrayMerged = new DynamicArray<int>();

		//////////////////////////////////////////////////////////////////
		//DynamicArray : Size 1 : Search/Merge 
		//////////////////////////////////////////////////////////////////
		insertEnd(dynamicArray1, SIZE1);
		insertEnd(dynamicArray2, SIZE1);

		printToFile("DynamicArray : Size 1 : Search : ",
			search(dynamicArray1, SIZE1 / 2));

		printToFile("DynamicArray : Size 1 : Merge : ",
			merge(dynamicArray1, dynamicArray2, dynamicArrayMerged, SIZE1));

		//////////////////////////////////////////////////////////////////
		//DynamicArray : Size 2 : Search/Merge
		//////////////////////////////////////////////////////////////////
		insertEnd(dynamicArray1, SIZE2);
		insertEnd(dynamicArray2, SIZE2);

		printToFile("DynamicArray : Size 2 : Search : ",
			search(dynamicArray1, SIZE2 / 2));

		printToFile("DynamicArray : Size 2 : Merge : ",
			merge(dynamicArray1, dynamicArray2, dynamicArrayMerged, SIZE2));

		//////////////////////////////////////////////////////////////////
		//DynamicArray : Size 3 : Search/Merge
		//////////////////////////////////////////////////////////////////
		insertEnd(dynamicArray1, SIZE3);
		insertEnd(dynamicArray2, SIZE3);

		printToFile("DynamicArray : Size 3 : Search : ",
			search(dynamicArray1, SIZE3 / 2));

		printToFile("DynamicArray : Size 3 : Merge : ",
			merge(dynamicArray1, dynamicArray2, dynamicArrayMerged, SIZE3));

		delete dynamicArray1;
		delete dynamicArray2;
		delete dynamicArrayMerged;

		////////////////////////////////////////////////////////////////////////////

		printToFile("DYNAMIC ARRAYLIST TESTING\n\n", i);

		DynamicArrayList<int> *dynamicArrayList = new DynamicArrayList<int>();

		//////////////////////////////////////////////////////////////////
		//DynamicArrayList : Size 1 : Insertion/Deletion : Front
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArrayList : Size 1 : Insertion : Front : ",
			insertFront(dynamicArrayList, SIZE1));

		printToFile("DynamicArrayList : Size 1 : Deletion : Front : ",
			deleteFront(dynamicArrayList, SIZE1));

		//////////////////////////////////////////////////////////////////
		//DynamicArrayList : Size 1 : Insertion/Deletion : Middle
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArrayList : Size 1 : Insertion : Middle : ",
			insertMiddle(dynamicArrayList, SIZE1));

		printToFile("DynamicArrayList : Size 1 : Deletion : Middle : ",
			deleteMiddle(dynamicArrayList, SIZE1));

		//////////////////////////////////////////////////////////////////
		//DynamicArrayList : Size 1 : Insertion/Deletion : End
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArrayList : Size 1 : Insertion : End : ",
			insertEnd(dynamicArrayList, SIZE1));

		printToFile("DynamicArrayList : Size 1 : Deletion : End : ",
			deleteEnd(dynamicArrayList, SIZE1));

		//////////////////////////////////////////////////////////////////
		//DynamicArrayList : Size 2 : Insertion/Deletion : Front
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArrayList : Size 2 : Insertion : Front : ",
			insertFront(dynamicArrayList, SIZE2));

		printToFile("DynamicArrayList : Size 2 : Deletion : Front : ",
			deleteFront(dynamicArrayList, SIZE2));

		//////////////////////////////////////////////////////////////////
		//DynamicArrayList : Size 2 : Insertion/Deletion : Middle
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArrayList : Size 2 : Insertion : Middle : ",
			insertMiddle(dynamicArrayList, SIZE2));

		printToFile("DynamicArrayList : Size 2 : Deletion : Middle : ",
			deleteMiddle(dynamicArrayList, SIZE2));

		//////////////////////////////////////////////////////////////////
		//DynamicArrayList : Size 2 : Insertion/Deletion : End
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArrayList : Size 2 : Insertion : End : ",
			insertEnd(dynamicArrayList, SIZE2));

		printToFile("DynamicArrayList : Size 2 : Deletion : End : ",
			deleteEnd(dynamicArrayList, SIZE2));

		//////////////////////////////////////////////////////////////////
		//DynamicArrayList : Size 3 : Insertion/Deletion : Front
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArrayList : Size 3 : Insertion : Front : ",
			insertFront(dynamicArrayList, SIZE3));

		printToFile("DynamicArrayList : Size 3 : Deletion : Front : ",
			deleteFront(dynamicArrayList, SIZE3));

		//////////////////////////////////////////////////////////////////
		//DynamicArrayList : Size 3 : Insertion/Deletion : Middle
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArrayList : Size 3 : Insertion : Middle : ",
			insertMiddle(dynamicArrayList, SIZE3));

		printToFile("DynamicArrayList : Size 3 : Deletion : Middle : ",
			deleteMiddle(dynamicArrayList, SIZE3));

		//////////////////////////////////////////////////////////////////
		//DynamicArrayList : Size 3 : Insertion/Deletion : End
		//////////////////////////////////////////////////////////////////
		printToFile("DynamicArrayList : Size 3 : Insertion : End : ",
			insertEnd(dynamicArrayList, SIZE3));

		printToFile("DynamicArrayList : Size 3 : Deletion : End : ",
			deleteEnd(dynamicArrayList, SIZE3));

		delete dynamicArrayList;

		DynamicArrayList<int> *dynamicArrayList1 = new DynamicArrayList<int>();
		DynamicArrayList<int> *dynamicArrayList2 = new DynamicArrayList<int>();
		DynamicArrayList<int> *dynamicArrayListMerged = new DynamicArrayList<int>();

		//////////////////////////////////////////////////////////////////
		//DynamicArrayList : Size 1 : Search/Merge 
		//////////////////////////////////////////////////////////////////
		insertEnd(dynamicArrayList1, SIZE1);
		insertEnd(dynamicArrayList2, SIZE1);

		printToFile("DynamicArrayList : Size 1 : Search : ",
			search(dynamicArrayList1, SIZE1 / 2));

		printToFile("DynamicArrayList : Size 1 : Merge : ",
			merge(dynamicArrayList1, dynamicArrayList2, dynamicArrayListMerged, SIZE1));

		//////////////////////////////////////////////////////////////////
		//DynamicArrayList : Size 2 : Search/Merge
		//////////////////////////////////////////////////////////////////
		insertEnd(dynamicArrayList1, SIZE2);
		insertEnd(dynamicArrayList2, SIZE2);

		printToFile("DynamicArrayList : Size 2 : Search : ",
			search(dynamicArrayList1, SIZE2 / 2));

		printToFile("DynamicArrayList : Size 2 : Merge : ",
			merge(dynamicArrayList1, dynamicArrayList2, dynamicArrayListMerged, SIZE2));

		//////////////////////////////////////////////////////////////////
		//DynamicArrayList : Size 3 : Search/Merge
		//////////////////////////////////////////////////////////////////
		insertEnd(dynamicArrayList1, SIZE3);
		insertEnd(dynamicArrayList2, SIZE3);

		printToFile("DynamicArrayList : Size 3 : Search : ",
			search(dynamicArrayList1, SIZE3 / 2));

		printToFile("DynamicArrayList : Size 3 : Merge : ",
			merge(dynamicArrayList1, dynamicArrayList2, dynamicArrayListMerged, SIZE3));

		delete dynamicArrayList1;
		delete dynamicArrayList2;
		delete dynamicArrayListMerged;
	}
	std::cin.get();
	return 0;
}