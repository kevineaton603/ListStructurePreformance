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

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <string>

template <typename T>
class DynamicArray
{
private:
	int mSize;
	T *mArray;

	/*
	* Pre: None.
	* Post: Returns the array pointer.
	* Purpose: To get the array from the wrapper object.
	* Author: Kevin Eaton
	*/
	T* getArray();

public:

	/*
	* Pre: None.
	* Post: Returns a DynamicArray object.
	* Purpose: Creates a DynamicArray object.
	* Author: Kevin Eaton
	*/
	DynamicArray();

	/*
	* Pre: None.
	* Post: None.
	* Purpose: Destroys a DynamicArray object.
	* Author: Kevin Eaton
	*/
	~DynamicArray();

	/*
	* Pre: The data to append to the dynamic array.
	* Post: None.
	* Purpose: Adds the data to the beginning of the list.
	* Author: Andrew Rimpici
	*/
	void append(T element);

	/*
	* Pre: The data to prepend to the array.
	* Post: None.
	* Purpose: Adds the data to the end of the list.
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
	* Pre: The index and data to insert into the array.
	* Post: None.
	* Purpose: Adds the data to the list at the specified index.
	* Author: Andrew Rimpici
	*/
	void insert(int index, T element);

	/*
	* Pre: None.
	* Post: None.
	* Purpose: Deletes all of the elements from the list.
	* Author: Kevin Eaton
	*/
	void clear();

	/*
	* Pre: The index to remove at.
	* Post: None.
	* Purpose: Deletes the node at the specified index
	* Author: Andrew Rimpici
	*/
	void removeAt(int index);

	/*
	* Pre: None.
	* Post: Returns true if list is empty and false otherwise.
	* Purpose: Checks if the list is empty.
	* Author: Kevin Eaton
	*/
	bool isEmpty();

	/*
	* Pre: None.
	* Post: Returns the number of elements in the list.
	* Purpose: To get the length of the list.
	* Author: Andrew Rimpici
	*/
	int getSize();

	/*
	* Pre: None.
	* Post: None.
	* Purpose: Prints out the list to the console.
	* Author: Kevin Eaton
	*/
	void print();

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
	static void merge(DynamicArray<T> &first, DynamicArray<T> &second, DynamicArray<T> &destination);


	//I may not need these functions
	void remove(T element);
	void remove(T *list, int size);
	void remove(DynamicArray<T> *list);
	void sort();
	T	 operator[](int index);
};


/*
* Pre: None.
* Post: Returns the array pointer.
* Purpose: To get the array from the wrapper object.
* Author: Kevin Eaton
*/
template <typename T>
T* DynamicArray<T>::getArray()
{
	return mArray;
}


/*
* Pre: None.
* Post: Returns a DynamicArray object.
* Purpose: Creates a DynamicArray object.
* Author: Kevin Eaton
*/
template <typename T>
DynamicArray<T>::DynamicArray()
{
	mSize = 0;
	mArray = nullptr;
}


/*
* Pre: None.
* Post: None.
* Purpose: Destroys a DynamicArray object.
* Author: Kevin Eaton
*/
template <typename T>
DynamicArray<T>::~DynamicArray()
{
	clear();
}


/*
* Pre: The data to append to the dynamic array.
* Post: None.
* Purpose: Adds the data to the end of the list.
* Author: Andrew Rimpici
*/
template <typename T>
void DynamicArray<T>::append(T element)
{
	insert(mSize, element);
}


/*
* Pre: The data to prepend to the DynamicArray.
* Post: None.
* Purpose: Adds the data to the beginning of the list.
* Author: Andrew Rimpici
*/
template <typename T>
void DynamicArray<T>::prepend(T element)
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
void DynamicArray<T>::insert(T element)
{
	int i;
	int shiftIndex = mSize;

	for (i = 0; i < mSize; ++i)
	{
		if (element <= mArray[i])
		{
			shiftIndex = i;
			break;
		}
	}

	insert(shiftIndex, element);
}


/*
* Pre: The index and data to insert into the DynamicArray.
* Post: None.
* Purpose: Adds the data to the list at the specified index.
* Author: Andrew Rimpici
*/
template <typename T>
void DynamicArray<T>::insert(int index, T element)
{
	if (index < 0)
	{
		index = 0;
	}
	else if (index > mSize)
	{
		index = mSize;
	}

	T *newArr = new T[++mSize];
	int i;

	for (i = mSize - 1; i > index; --i)
	{
		newArr[i] = mArray[i - 1];
	}

	newArr[index] = element;

	for (i = index - 1; i >= 0; --i)
	{
		newArr[i] = mArray[i];
	}

	delete[] mArray;
	mArray = newArr;
}


/*
* Pre: None.
* Post: None.
* Purpose: Deletes all of the elements from the list.
* Author: Kevin Eaton
*/
template <typename T>
void DynamicArray<T>::clear()
{
	delete[] mArray;
	mArray = nullptr;
	mSize = 0;
}


/*
* Pre: The index to remove at.
* Post: None.
* Purpose: Deletes the node at the specified index
* Author: Andrew Rimpici
*/
template <typename T>
void DynamicArray<T>::removeAt(int index)
{
	if (index >= 0 && index < mSize)
	{
		int i;
		for (i = index; i < mSize - 1; ++i)
		{
			mArray[i] = mArray[i + 1];
		}

		T *newArr = new T[--mSize];

		for (i = 0; i < mSize; ++i)
		{
			newArr[i] = mArray[i];
		}

		delete[] mArray;
		mArray = newArr;
	}
}


/*
* Pre: None.
* Post: Returns true if list is empty and false otherwise.
* Purpose: Checks if the list is empty.
* Author: Kevin Eaton
*/
template <typename T>
bool DynamicArray<T>::isEmpty()
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
int DynamicArray<T>::getSize()
{
	return mSize;
}


/*
* Pre: None.
* Post: None.
* Purpose: Prints out the list to the console.
* Author: Kevin Eaton
*/
template <typename T>
void DynamicArray<T>::print()
{
	int i;
	std::cout << "Dynamic Array has " << std::to_string(mSize) << " elements: ";

	if (mSize == 0)
	{
		std::cout << std::endl;
		return;
	}

	for (i = 0; i < mSize - 1; ++i)
	{
		std::cout << mArray[i] << " ";
	}

	std::cout << mArray[mSize - 1] << std::endl;
}


/*
* Pre: The searchkey and bool to know if the list is sorted in ascending order.
* Post: Returns true if searchkey is in the list and false otherwise.
* Purpose: To check if searchkey is in the list.
* Author: Andrew Rimpici
*/
template <typename T>
bool DynamicArray<T>::sequentialSearch(T searchKey, bool isSorted)
{
	bool isFound = false;
	int i;
	T currentElement;

	for (i = 0; i < mSize; ++i)
	{
		currentElement = mArray[i];

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
* Author: Kevin Eaton
*/
template <typename T>
void DynamicArray<T>::merge(DynamicArray<T> &first, DynamicArray<T> &second, DynamicArray<T> &destination)
{
	int i, j, k;

	if (first.mArray != nullptr && second.mArray != nullptr)
	{
		delete[] destination.mArray;
		destination.mSize = first.mSize + second.mSize;
		destination.mArray = new T[destination.mSize];
		i = j = k = 0;

		while (i < first.mSize && j < second.mSize)
		{
			if (first.mArray[i] <= second.mArray[j])
			{
				destination.mArray[k] = first.mArray[i];
				i++;
				k++;
			}
			else
			{
				destination.mArray[k] = second.mArray[j];
				j++;
				k++;
			}
		}

		while (i < first.mSize)
		{
			destination.mArray[k] = first.mArray[i];
			i++;
			k++;
		}

		while (j < second.mSize)
		{
			destination.mArray[k] = second.mArray[j];
			j++;
			k++;
		}
	}
}






template <typename T>
void DynamicArray<T>::remove(T element)
{
	remove(&element, 1);
}

template <typename T>
void DynamicArray<T>::remove(T *list, int size)
{
	T *newList;
	int i, j, k, newSize;
	
	if (mArray == nullptr)
	{
		std::cout << "There are no elements in this array\n\n";
	}
	else
	{
		i = j = k = 0;
		newSize = mSize;

		while (i < mSize && j < size && newSize <= 0)
		{
			if (mArray[i] == list[j])
			{
				newSize--;
				i++;
			}
			else if (mArray[i] < list[j])
			{
				i++;
			}
			else
			{
				j++;
			}
		}

		if (newSize == mSize)
		{
			std::cout << "No changes were made to the Array!\n\n";
		}
		else if (mSize <= 0)
		{
			clear();
		}
		else
		{
			newList = new T[newSize];
			i = j = k = 0;

			while (i < this->mSize && j < size)
			{
				if (mArray[i] > list[j])
				{
					j++;
				}
				else if (mArray[i] == list[j])
				{
					i++;
				}
				else if (mArray[i] < list[j])
				{
					newList[k] = mArray[i];
					i++;
					k++;
				}
			}
		}
	}
}

template <typename T>
void DynamicArray<T>::remove(DynamicArray<T> *list)
{
	remove(list->getArray(), list->mSize);
}

template <typename T>
void DynamicArray<T>::sort()
{
	mergeSort(mArray, 0, mSize - 1);
}

template <typename T>
T DynamicArray<T>::operator[](int index)
{
	return mArray[index];
}

#endif