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

#ifndef DYNAMICARRAYLIST_H_
#define DYNAMICARRAYLIST_H_

#include <iostream>

template<typename T>
class DynamicArrayList
{
private:
	static const int CAPACITY_MULTIPLIER = 10;
	static const int DEFAULT_CAPACITY = 10;
	int mCapacity;
	int mLength;
	T* mArrPtr;

public:
	DynamicArrayList(int capacity = DEFAULT_CAPACITY);
	~DynamicArrayList();

	void add(T element);
	T	 get(int index) const;
	void print() const;
	bool remove(T element);
	bool removeAt(int index);
	void resizeArray(int newCapacity);
	bool set(int index, T element);
<<<<<<< HEAD:DynamicArrayList.h
	T	 operator[](int index) const;

	static DynamicArrayList<T>* DynamicArrayList<T>::merge(DynamicArrayList<T> *first, DynamicArrayList<T> *second)
	{
		if (first == nullptr && second == nullptr)
		{
			return nullptr;
		}
		else if (first != nullptr && second == nullptr)
		{
			return first;
		}
		else if (first == nullptr && second!= nullptr)
		{
			return second;
		}
		else
		{
			DynamicArrayList<T> *mergedList = new DynamicArrayList<T>(first->mLength + second->mLength);
			int firstIndex = 0, secondIndex = 0, mergedIndex = 0;
			int mergedLength = mergedList->mCapacity;

			while (mergedIndex < mergedLength)
			{
				if (firstIndex >= first->mLength)
				{
					for (; secondIndex < second->mLength; ++secondIndex, ++mergedIndex)
					{
						mergedList->add(second->get(secondIndex));
					}
				}
				else if (secondIndex >= second->mLength)
				{
					for (; firstIndex < first->mLength; ++firstIndex, ++mergedIndex)
					{
						mergedList->add(first->get(firstIndex));
					}
				}
				else if (first->get(firstIndex) >= second->get(secondIndex))
				{
					mergedList->add(second->get(secondIndex));
					++secondIndex;
					++mergedIndex;
				}
				else if (second->get(secondIndex) >= first->get(firstIndex))
				{
					mergedList->add(first->get(firstIndex));
					++firstIndex;
					++mergedIndex;
				}
			}

			return mergedList;
		}
	}
=======
	T DynamicArray<T>::operator[](int index);
>>>>>>> 5d0795eda4410aa3876c03149e4122c71b833a21:DynamicArray.h
};

template<typename T>
DynamicArrayList<T>::DynamicArrayList(int capacity) :
	mCapacity(capacity),
	mLength(0),
	mArrPtr(new T[mCapacity])
{
	
}

template<typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
	delete[] mArrPtr;
}

template<typename T>
void DynamicArrayList<T>::add(T element)
{
	if (mLength == mCapacity)
	{
		resizeArray(mCapacity * CAPACITY_MULTIPLIER);
	}

	mArrPtr[mLength] = element;
	++mLength;

	//print();
}

template<typename T>
void DynamicArrayList<T>::print() const
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
T DynamicArrayList<T>::get(int index) const
{
	return mArrPtr[index];
}

template<typename T>
bool DynamicArrayList<T>::remove(T element)
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
bool DynamicArrayList<T>::removeAt(int index)
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
void DynamicArrayList<T>::resizeArray(int newCapacity)
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
bool DynamicArrayList<T>::set(int index, T element)
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
<<<<<<< HEAD:DynamicArrayList.h

template<typename T>
T DynamicArrayList<T>::operator[](int index) const
{
	return get(index);
=======
template <typename T>
T DynamicArray<T>::operator[](int index)
{ 
	return mArrPtr[index]; 
>>>>>>> 5d0795eda4410aa3876c03149e4122c71b833a21:DynamicArray.h
}
#endif