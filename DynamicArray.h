/*
*	Author:				Andrew Rimpici
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

#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

#include <iostream>

template<typename T>
class DynamicArray
{
private:
	static const int CAPACITY_MULTIPLIER = 10;
	static const int DEFAULT_CAPACITY = 10;
	int mCapacity;
	int mLength;
	T* mArrPtr;

public:
	DynamicArray(int capacity = DEFAULT_CAPACITY);
	~DynamicArray();

	void add(T element);
	void get(int index);
	void print();
	bool remove(T element);
	bool removeAt(int index);
	void resizeArray(int newCapacity);
	bool set(int index, T element);
};

template<typename T>
DynamicArray<T>::DynamicArray(int capacity) : 
	mCapacity(capacity),
	mLength(0),
	mArrPtr(new T[mCapacity])
{

}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] mArrPtr;
}

template<typename T>
void DynamicArray<T>::add(T element)
{
	if (mLength == mCapacity)
	{
		resizeArray(mCapacity * CAPACITY_MULTIPLIER);
	}

	mArrPtr[mLength] = element;
	++mLength;

	print();
}

template<typename T>
void DynamicArray<T>::print()
{
	int i;

	std::cout << "[";
	for (i = 0; i < mLength - 1; ++i)
	{
		std::cout << mArrPtr[i] << " ";
	}
	std::cout << mArrPtr[mLength - 1] << "]" << std::endl;
}

template<typename T>
void DynamicArray<T>::get(int index)
{
	return mArrPtr[index];
}

template<typename T>
bool DynamicArray<T>::remove(T element)
{
	bool removed = false;
	int i;
	for (i = 0; i < mLength; ++i)
	{
		if (mArrPtr[i] == element)
		{
			removeAt(i);
			removed = true;
		}
	}

	return removed;
}

template<typename T>
bool DynamicArray<T>::removeAt(int index)
{
	bool removed = false;
	if (index >= 0 && index < mLength)
	{
		int i;
		for (i = index; i < mLength - 1; ++i)
		{
			mArrPtr[i] = mArrPtr[i + 1];
		}

		--mLength;
		removed = true;

		if (mLength <= (mCapacity / CAPACITY_MULTIPLIER))
		{
			resizeArray(mCapacity / CAPACITY_MULTIPLIER);
		}
	}

	print();
	return removed;
}

template<typename T>
void DynamicArray<T>::resizeArray(int newCapacity)
{
	mCapacity = newCapacity;
	T* newArr = new T[mCapacity];
	int i;

	for (i = 0; i < mLength; ++i)
	{
		newArr[i] = mArrPtr[i];
	}

	delete[] mArrPtr;
	mArrPtr = newArr;

	std::cout << "CAPACITY: " << mCapacity << std::endl;
}

template<typename T>
bool DynamicArray<T>::set(int index, T element)
{
	bool successful = false;
	if (index >= 0 && index < mLength)
	{
		mArrPtr[index] = element;
		successful = true;
	}
	else if (index == mLength)
	{
		add(element);
		successful = true;
	}

	print();
	return successful;
}

#endif