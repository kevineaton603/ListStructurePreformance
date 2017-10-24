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

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include "Functions.h"

template<typename T>
class DynamicArray
{
private:
	int mSize;
	T *mArray;

	void merge(T *list, int size);
	T *getArray();

public:
	DynamicArray();
	DynamicArray(int size);
	~DynamicArray();

	int getSize();

	void clear();
	void insert(const T &element);
	void insert(int index, T element);
	void insert(DynamicArray<T> &list);
	void print();
	void remove(T element);
	void remove(T *list, int size);
	void remove(DynamicArray<T> *list);
	void removeAt(int index);
	void removeFromTo(int lower, int upper);
	void sort();

	T	 operator[](int index);
};

template<typename T>
DynamicArray<T>::DynamicArray()
{
	mSize = 0;
	mArray = nullptr;
}

template<typename T>
DynamicArray<T>::DynamicArray(int size)
{
	mSize = 0;
	mArray = nullptr;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
	clear();
}

template<typename T>
T* DynamicArray<T>::getArray()
{
	return mArray;
}

template<typename T>
int DynamicArray<T>::getSize()
{
	return mSize;
}

template<typename T>
void DynamicArray<T>::clear()
{
	delete[] mArray;
	mArray = nullptr;
	mSize = 0;
}

template<typename T>
void DynamicArray<T>::insert(const T &element)
{
	int newElement = element;
	merge(&newElement, 1);
}

template<typename T>
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

template<typename T>
void DynamicArray<T>::insert(DynamicArray<T> &list)
{
	merge(list.getArray(), list.getSize());
}

template<typename T>
void DynamicArray<T>::merge(T *list, int size)
{
	T *newList;
	int i, j, k;

	if (mArray == nullptr)
	{
		mSize = size;
		mArray = new T[mSize];

		for (i = 0; i < mSize; i++)
		{
			mArray[i] = list[i];
		}
	}
	else
	{
		newList = new T[mSize + size];
		i = j = k = 0;

		while (i < mSize && j < size)
		{
			if (mArray[i] <= list[j])
			{
				newList[k] = mArray[i];
				i++;
				k++;
			}
			else
			{
				newList[k] = list[j];
				j++;
				k++;
			}
		}

		while (i < mSize)
		{
			newList[k] = mArray[i];
			i++;
			k++;
		}

		while (j < size)
		{
			newList[k] = list[j];
			j++;
			k++;
		}

		delete[] mArray;
		mArray = newList;
		mSize += size;
	}
}

template<typename T>
void DynamicArray<T>::print()
{
	if (mArray == nullptr)
	{
		std::cout << "Array is empty" << std::endl;
	}
	else
	{
		for (long i = 0; i < mSize; i++)
		{
			std::cout << mArray[i] << ", ";
			if (i % 10 == 9)
			{
				std::cout << std::endl;
			}
		}
	}
}

template<typename T>
void DynamicArray<T>::remove(T element)
{
	remove(&element, 1);
}

template<typename T>
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

template<typename T>
void DynamicArray<T>::remove(DynamicArray<T> *list)
{
	remove(list->getArray(), list->mSize);
}

template<typename T>
void DynamicArray<T>::removeAt(int index)
{
	//Rip needs to be finished
}

template<typename T>
void DynamicArray<T>::removeFromTo(int lower, int upper)
{
	//Rip needs to be finished
}

template<typename T>
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