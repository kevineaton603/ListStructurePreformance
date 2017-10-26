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

#ifndef DYNAMICARRAYLIST_H_
#define DYNAMICARRAYLIST_H_

#include <iostream>
#include <string>

template <typename T>
class DynamicArrayList
{
private:
	static const int CAPACITY_MULTIPLIER = 10;
	static const int DEFAULT_CAPACITY = 10;
	int mCapacity;
	int mSize;
	T *mArrPtr;

	/*
	* Pre: The capacity for the arraylist.
	* Post: None.
	* Purpose: To create the underlying array with the capacity given.
	* Author: Andrew Rimpici
	*/
	void resizeArray(int newCapacity);

public:

	/*
	* Pre: The starting capacity of the arraylist.
	* Post: Returns a DynamicArrayList object.
	* Purpose: Creates a DynamicArrayList object.
	* Author: Andrew Rimpici
	*/
	DynamicArrayList(int capacity = DEFAULT_CAPACITY);
	
	/*
	* Pre: None.
	* Post: None.
	* Purpose: Destroys a DynamicArrayList object.
	* Author: Andrew Rimpici
	*/
	~DynamicArrayList();

	/*
	* Pre: The data to append to the dynamic arraylist.
	* Post: None.
	* Purpose: Adds the data to the end of the list.
	* Author: Andrew Rimpici
	*/
	void append(T element);

	/*
	* Pre: The data to prepend to the arraylist.
	* Post: None.
	* Purpose: Adds the data to the beginning of the list.
	* Author: Andrew Rimpici
	*/
	void prepend(T element);

	/*
	* Pre: The data to insert into the dynamic array.
	* Post: None.
	* Purpose: Adds the data to the list in ascending order.
	* Author: Andrew Rimpici
	*/
	void insert(T element);

	/*
	* Pre: The index and data to insert into the arraylist.
	* Post: None.
	* Purpose: Adds the data to the list at the specified index.
	* Author: Andrew Rimpici
	*/
	void insert(int index, T element);

	/*
	* Pre: None.
	* Post: None.
	* Purpose: Deletes all of the elements from the list.
	* Author: Andrew Rimpici
	*/
	void clear();

	/*
	* Pre: The index to remove at.
	* Post: None.
	* Purpose: Deletes the node at the specified index
	* Author: Andrew Rimpici
	*/
	bool removeAt(int index);

	/*
	* Pre: None.
	* Post: Returns true if list is empty and false otherwise.
	* Purpose: Checks if the list is empty.
	* Author: Andrew Rimpici
	*/
	bool isEmpty();

	/*
	* Pre: None.
	* Post: Returns the number of elements in the list.
	* Purpose: To get the length of the list.
	* Author: Andrew Rimpici
	*/
	int  getSize() const;


	/*
	* Pre: None.
	* Post: Returns the elements at the index spot.
	* Purpose: To get the element.
	* Author: Andrew Rimpici
	*/
	T get(int index) const;

	/*
	* Pre: None.
	* Post: None.
	* Purpose: Prints out the list to the console.
	* Author: Andrew Rimpici
	*/
	void print() const;

	/*
	* Pre: The searchkey and bool to know if the list is sorted in ascending order.
	* Post: Returns true if searchkey is in the list and false otherwise.
	* Purpose: To check if searchkey is in the list.
	* Author: Andrew Rimpici
	*/
	bool sequentialSearch(T searchKey, bool isSorted);

	/*
	* Pre: Two lists to merge together.
	* Post: None.
	* Purpose: Merges the two lists together.
	* Author: Kevin Eaton
	*/
	static void merge(DynamicArrayList<T> &first, DynamicArrayList<T> &second, DynamicArrayList<T> &destination);
};


/*
* Pre: The capacity for the arraylist.
* Post: None.
* Purpose: To create the underlying array with the capacity given.
* Author: Andrew Rimpici
*/
template <typename T>
void DynamicArrayList<T>::resizeArray(int newCapacity)
{
	mCapacity = newCapacity;
	T *newArr = new T[mCapacity];

	int i;
	for (i = 0; i < mSize; ++i)
	{
		newArr[i] = mArrPtr[i];
	}

	delete[] mArrPtr;
	mArrPtr = newArr;
}


/*
* Pre: The starting capacity of the arraylist.
* Post: Returns a DynamicArrayList object.
* Purpose: Creates a DynamicArrayList object.
* Author: Andrew Rimpici
*/
template <typename T>
DynamicArrayList<T>::DynamicArrayList(int capacity) :
	mCapacity(capacity),
	mSize(0),
	mArrPtr(new T[mCapacity])
{
	
}


/*
* Pre: None.
* Post: None.
* Purpose: Destroys a DynamicArrayList object.
* Author: Andrew Rimpici
*/
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
	clear();
}


/*
* Pre: The data to append to the dynamic arraylist.
* Post: None.
* Purpose: Adds the data to the end of the list.
* Author: Andrew Rimpici
*/
template <typename T>
void DynamicArrayList<T>::append(T element)
{
	insert(mSize, element);
}


/*
* Pre: The data to prepend to the arraylist.
* Post: None.
* Purpose: Adds the data to the beginning of the list.
* Author: Andrew Rimpici
*/
template <typename T>
void DynamicArrayList<T>::prepend(T element)
{
	insert(0, element);
}


/*
* Pre: The data to insert into the dynamic array.
* Post: None.
* Purpose: Adds the data to the list in ascending order.
* Author: Andrew Rimpici
*/
template <typename T>
void DynamicArrayList<T>::insert(T element)
{
	int i;
	int shiftIndex = mSize;

	for (i = 0; i < mSize; ++i)
	{
		if (element <= mArrPtr[i])
		{
			shiftIndex = i;
			break;
		}
	}

	insert(shiftIndex, element);
}


/*
* Pre: The index and data to insert into the arraylist.
* Post: None.
* Purpose: Adds the data to the list at the specified index.
* Author: Andrew Rimpici
*/
template <typename T>
void DynamicArrayList<T>::insert(int index, T element)
{
	if (index < 0)
	{
		index = 0;
	}
	else if (index > mSize)
	{
		index = mSize;
	}

	if (mArrPtr == nullptr || mSize == mCapacity)
	{
		resizeArray(mCapacity * CAPACITY_MULTIPLIER);
	}

	++mSize;

	int i;
	for (i = mSize - 1; i > index; --i)
	{
		mArrPtr[i] = mArrPtr[i - 1];
	}

	mArrPtr[index] = element;
}


/*
* Pre: None.
* Post: None.
* Purpose: Deletes all of the elements from the list.
* Author: Andrew Rimpici
*/
template <typename T>
void DynamicArrayList<T>::clear()
{
	delete[] mArrPtr;
	mArrPtr = nullptr;
	mSize = 0;
	mCapacity = DEFAULT_CAPACITY;
}


/*
* Pre: The index to remove at.
* Post: None.
* Purpose: Deletes the node at the specified index
* Author: Andrew Rimpici
*/
template <typename T>
bool DynamicArrayList<T>::removeAt(int index)
{
	bool removed = false;
	if (index >= 0 && index < mSize)
	{
		int i;
		for (i = index; i < mSize - 1; ++i)
		{
			mArrPtr[i] = mArrPtr[i + 1];
		}

		--mSize;
		removed = true;

		int newCapacity = (mCapacity / CAPACITY_MULTIPLIER);
		if (DEFAULT_CAPACITY <= newCapacity && mSize <= newCapacity)
		{
			resizeArray(newCapacity);
		}
	}

	return removed;
}


/*
* Pre: None.
* Post: Returns true if list is empty and false otherwise.
* Purpose: Checks if the list is empty.
* Author: Andrew Rimpici
*/
template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
	return mSize == 0;
}


/*
* Pre: None.
* Post: Returns the number of elements in the list.
* Purpose: To get the length of the list.
* Author: Andrew Rimpici
*/
template <typename T>
int DynamicArrayList<T>::getSize() const
{
	return mSize;
}


/*
* Pre: None.
* Post: Returns the elements at the index spot.
* Purpose: To get the element.
* Author: Andrew Rimpici
*/
template <typename T>
T DynamicArrayList<T>::get(int index) const
{
	return mArrPtr[index];
}


/*
* Pre: None.
* Post: None.
* Purpose: Prints out the list to the console.
* Author: Andrew Rimpici
*/
template <typename T>
void DynamicArrayList<T>::print() const
{
	int i;
	std::cout << "Dynamic ArrayList has " << std::to_string(mSize) << " elements: ";

	if (mSize == 0)
	{
		std::cout << std::endl;
		return;
	}

	for (i = 0; i < mSize - 1; ++i)
	{
		std::cout << mArrPtr[i] << " ";
	}

	std::cout << mArrPtr[mSize - 1] << std::endl;
}


/*
* Pre: The searchkey and bool to know if the list is sorted in ascending order.
* Post: Returns true if searchkey is in the list and false otherwise.
* Purpose: To check if searchkey is in the list.
* Author: Andrew Rimpici
*/
template <typename T>
bool DynamicArrayList<T>::sequentialSearch(T searchKey, bool isSorted)
{
	bool isFound = false;
	int i;
	T currentElement;

	for (i = 0; i < mSize; ++i)
	{
		currentElement = mArrPtr[i];

		if (currentElement == searchKey)
		{
			isFound = true;
			break;
		}
		else if (isSorted && searchKey < currentElement)
		{
			break;
		}
	}

	return isFound;
}


/*
* Pre: Two lists to merge together.
* Post: None.
* Purpose: Merges the two lists together.
* Author: Andrew Rimpici
*/
template <typename T>
void DynamicArrayList<T>::merge(DynamicArrayList<T> &first, DynamicArrayList<T> &second, DynamicArrayList<T> &destination)
{
	if (first.mArrPtr != nullptr && second.mArrPtr != nullptr)
	{
		int firstIndex = 0, secondIndex = 0, mergedIndex = 0;
		int mergedLength = first.mSize + second.mSize;
		destination.clear();
		destination.mArrPtr = new T[mergedLength];
		destination.mSize = 0;
		destination.mCapacity = mergedLength;

		while (mergedIndex < mergedLength)
		{
			if (firstIndex >= first.mSize)
			{
				for (; secondIndex < second.mSize; ++secondIndex, ++mergedIndex)
				{
					destination.append(second.get(secondIndex));
				}
			}
			else if (secondIndex >= second.mSize)
			{
				for (; firstIndex < first.mSize; ++firstIndex, ++mergedIndex)
				{
					destination.append(first.get(firstIndex));
				}
			}
			else if (first.get(firstIndex) >= second.get(secondIndex))
			{
				destination.append(second.get(secondIndex));
				++secondIndex;
				++mergedIndex;
			}
			else if (second.get(secondIndex) >= first.get(firstIndex))
			{
				destination.append(first.get(firstIndex));
				++firstIndex;
				++mergedIndex;
			}
		}
	}
}

#endif