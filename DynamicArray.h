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