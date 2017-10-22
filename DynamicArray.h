#ifndef DYNAMIC_ARR_H
#define DYNAMIC_ARR_H
#include<iostream>
template<typename T>
class DynamicArr
{
private:
	long mSize;
	T * mArray;
	void merge(T * list, long size);
	T* getArray();

public:
	DynamicArr();
	DynamicArr(long size);
	~DynamicArr();

	long getSize();

	void clear();
	void insert(const T & element);
	void insert(T * list, long size);
	void insert(DynamicArr<T> & list);
	void print();
	void remove(T element);
	void remove(T *list, long size);
	void remove(DynamicArr<T> * list);
	void removeAt(long index);
	void removeFromTo(long lower, long upper);

	T DynamicArr<T>::operator[](int index);
	
};
template<typename T>
DynamicArr<T>::DynamicArr()
{
	mSize = 0;
	mArray = NULL;
}
template<typename T>
DynamicArr<T>::DynamicArr(long size)
{
	mSize = 0;
	mArray = NULL;
}
template<typename T>
DynamicArr<T>::~DynamicArr()
{
	clear();
}

template<typename T>
T* DynamicArr<T>::getArray()
{
	return this->mArray;
}
template<typename T>
long DynamicArr<T>::getSize()
{
	return mSize;
}
template<typename T>
void DynamicArr<T>::clear()
{
	delete[] mArray;
	mArray = NULL;
	mSize = 0;
}
template<typename T>
void DynamicArr<T>::insert(const T& element)
{
	int newElement = element;
	this->merge(&newElement, 1);
	/*
	T * list;
	long i;
	bool added = false;
	if (mArray == NULL)
	{
		mSize++;
		mArray = new T[mSize];
		mArray[0] = element;
	}
	else
	{
		list = new T[mSize + 1];
		i = 0;
		while (!added && i < mSize)
		{
			if (element <= mArray[i])
			{
				list[i] = element;
				i++;
				added = true;
			}
			else
			{
				list[i] = this->mArray[i];
				i++;
			}
			
		}
		if (!added)
		{
			list[mSize] = element;
		}
		else
		{
			while (i < mSize + 1)
			{
				list[i] = this->mArray[i - 1];
				i++;
			}
		}
		delete[] mArray;
		mSize++;
		mArray = new T[mSize];
		for (i = 0; i < mSize; i++)
		{
			mArray[i] = list[i];
		}
		
	}
	*/
}
template<typename T>
void DynamicArr<T>::insert(DynamicArr<T> & list)
{
	this->merge(list.getArray(), list.getSize());
}
template<typename T>
void DynamicArr<T>::insert(T * list, long size)
{
	this->merge(list, size);
}
template<typename T>
void DynamicArr<T>::merge(T * list, long size)
{
	T * newList;
	int i, j, k;
	if (mArray == NULL)
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
void DynamicArr<T>::print()
{
	if (mArray == NULL)
		std::cout << "Array is empty" << std::endl;
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
void DynamicArr<T>::remove(T element)
{
	remove(&element, 1);
}
template<typename T>
void DynamicArr<T>::remove(T * list, long size)
{
	T * newList;
	long i, j, k, newSize;
	if (this->mArray == NULL)
	{
		std::cout << "There are no elements in this array\n\n";
	}
	else
	{
		i = j = k = 0;
		newSize = mSize;

		while (i < this->mSize && j < size && newSize <= 0)
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
void DynamicArr<T>::remove(DynamicArr<T> * list)
{
	remove(list->getArray(), list->mSize);
}
template<typename T>
void DynamicArr<T>::removeAt(long index)
{

}
template<typename T>
void DynamicArr<T>::removeFromTo(long lower, long upper)
{

}
template <typename T>
T DynamicArr<T>::operator[](int index)
{
	return mArray[index];
}

/* Pre:		T array, lowerbound and upperbound
*  Post:	sorts using merge method
*  Purpose: sorts using merge method
*  NOTE: for upperbound send in size - 1
*****************************************************************************/
template <typename T>
static void merge(T * list, long lowerBound, long mid, long upperBound)
{
	long size1 = mid - lowerBound + 1;
	long size2 = upperBound - mid;
	T * left = new T[size1];
	T * right = new T[size2];
	long i, j, k;

	for (i = 0; i < size1; i++)
	{
		left[i] = list[lowerBound + i];
	}
	for (j = 0; j < size2; j++)
	{
		right[j] = list[mid + 1 + j];
	}
	i = j = 0;
	k = lowerBound;
	while (i < size1 && j < size2)
	{
		if (left[i] <= right[j])
		{
			list[k] = left[i];
			i++;
		}
		else
		{
			list[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < size1)
	{
		list[k] = left[i];
		i++;
		k++;
	}
	while (j < size2)
	{
		list[k] = right[j];
		j++;
		k++;
	}
	delete[] left;
	delete[] right;
}
/* Pre:		T array, lowerbound and upperbound
*  Post:	sorts using merge method
*  Purpose: sorts using merge method
*  NOTE: for upperbound send in size - 1
*****************************************************************************/
template <typename T>
static void mergeSort(T * list, long lowerBound, long upperBound)
{
	long mid;
	if (lowerBound < upperBound)
	{
		mid = (lowerBound + upperBound) / 2;
		mergeSort(list, lowerBound, mid);
		mergeSort(list, mid + 1, upperBound);
		merge(list, lowerBound, mid, upperBound);
	}
}
#endif // !DYNAMIC_ARR_H

