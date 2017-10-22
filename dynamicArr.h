#ifndef DYNAMIC_ARR_H
#define DYNAMIC_ARR_H
#include<iostream>
template<typename T>
class DynamicArr
{
private:
	long mSize;
	T * mArray;
	DynamicArr<T> * merge(T * list, long size);
	T* getArray();

public:
	DynamicArr();
	DynamicArr(long size);
	~DynamicArr();

	long getSize();

	void clear();
	DynamicArr<T> * insert(const T & element);
	DynamicArr<T> * merge(DynamicArr<T> & list);
	void print();
	void remove(T element);
	void remove(T *list, long size);
	void remove(DynamicArr<T> * list);
	void removeAt(long index);

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
DynamicArr<T> * DynamicArr<T>::insert(const T& element)
{
	int newElement = element;
	return this->merge(&newElement, 1);
}
template<typename T>
DynamicArr<T> * DynamicArr<T>::merge(DynamicArr<T> & list)
{
	return this->merge(list.getArray(), list.getSize());
}
template<typename T>
DynamicArr<T> * DynamicArr<T>::merge(T * list, long size)
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
		std::cout << "mSize: " << mSize << std::endl;
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
	T * newList = new T[mSize - 1];
	long i, j = 0;
	if (mArray != NULL)
	{
		for (i = 0; i < mSize; i++)
		{
			if (i == index);
			else
			{
				newList[j] = mArray[i];
				j++;
			}
		}
		delete[] mArray;
		mArray = newList;
		mSize--;
	}
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

