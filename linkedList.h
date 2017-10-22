#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template<typename T>
class LinkedList
{
private:
	template<typename R>
	struct Node
	{
		Node<R> * mNext;
		R mData;
		Node()
		{
			mNext = NULL;
		}
		Node(R data)
		{
			mNext = NULL;
			mData = data;
		}
		~Node()
		{

		}
	};
	Node<T> * mHead, * mTail;
	long mCount;
public:
	LinkedList();
	~LinkedList();
	void append(const T & data);
	void clear();
	void insert(T data);
	bool isExist(T data);
	bool isEmpty();
	static LinkedList<T> * merge(LinkedList<T> & list1, LinkedList<T> & list2);
	void print();
	void removeAt(long index);
};
template<typename T>
LinkedList<T>::LinkedList()
{
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}
template<typename T>
LinkedList<T>::~LinkedList()
{
	this->clear();
}
template<typename T>
void LinkedList<T>::append(const T & data)
{
	Node<T> * newNode = new Node<T>(data);
	if (mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		mTail->mNext = newNode;
		mTail = newNode;
	}
	mCount++;
}
template<typename T>
void LinkedList<T>::clear()
{
	Node<T> *tmp, *toBeDeleted;
	tmp = mHead;
	while (tmp != NULL)
	{
		toBeDeleted = tmp;
		tmp = tmp->mNext;
		toBeDeleted->mNext = NULL;
		delete toBeDeleted;
	}
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}
template<typename T>
void LinkedList<T>::insert(T data)
{
	Node<T> * newNode = new Node<T>(data);
	Node<T> * tmp, * oneBefore;
	if (newNode == NULL);
	else if (mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else if (data < mHead->mData)
	{
		newNode->mNext = mHead;
		mHead = newNode;
	}
	else if (data > mTail->mData)
	{
		mTail->mNext = newNode;
		mTail = newNode;
	}
	else 
	{
		tmp = mHead;
		oneBefore = mHead;
		while (tmp != NULL && tmp->mData < data)
		{
			oneBefore = tmp;
			tmp = tmp->mNext;
		}
		newNode->mNext = tmp;
		oneBefore->mNext = newNode;
	}
	mCount++;
}
template<typename T>
bool LinkedList<T>::isExist(T data)
{
	Node<T> * tmp;
	if (mHead == NULL)
		return false;
	tmp = mHead;
	while (tmp != NULL)
	{
		if (tmp->mData == data)
			return true;
		tmp = tmp->mNext;
	}
	return false;
}
template<typename T>
bool LinkedList<T>::isEmpty()
{
	return mHead == NULL;
}
template<typename T>
LinkedList<T> * LinkedList<T>::merge(LinkedList<T> & list1, LinkedList<T> & list2)
{
	Node<T> * tmp, *tmp2;
	LinkedList<T> * newList = new LinkedList<T>;

	if (list1.mHead != NULL && list2.mHead != NULL)
	{
		if (list1.mHead != NULL && list2.mHead == NULL)
			newList = &list1;
		else if (list1.mHead == NULL && list2.mHead != NULL)
			newList = &list2;
		else
		{
			tmp = list1.mHead;
			tmp2 = list2.mHead;
			while (tmp != NULL && tmp2 != NULL)
			{
				if (tmp->mData <= tmp2->mData)
				{
					newList->append(tmp->mData);
					tmp = tmp->mNext;
				}
				else
				{
					newList->append(tmp2->mData);
					tmp2 = tmp2->mNext;
				}
			}
			while (tmp != NULL)
			{
				newList->append(tmp->mData);
				tmp = tmp->mNext;
			}
			while (tmp2 != NULL)
			{
				newList->append(tmp2->mData);
				tmp2 = tmp2->mNext;
			}
		}
	}
	return newList;
}
template<typename T>
void LinkedList<T>::print()
{
	Node<T> * tmp;
	long i = 0; 
	if (!this->isEmpty())
	{
		tmp = mHead;
		while (tmp != NULL)
		{
			std::cout << i << ": " <<tmp->mData << std::endl;
			tmp = tmp->mNext;
			i++;
		}
	}
}
template<typename T>
void LinkedList<T>::removeAt(long index)
{
	Node<T> * tmp, * oneBefore;
	long i = 0;
	bool removed = false;
	tmp = mHead->mNext;
	oneBefore = mHead;
	if (index == 0 || index >= mCount);
	else if (mHead != NULL)
	{
		tmp = mHead; 
		oneBefore = mHead; 
		for (i = 0; i < index; i++)
		{ 
			oneBefore = tmp; 
			tmp = tmp->mNext; 
		}
		if (index == 0)
		{
			mHead = tmp->mNext;

		}	
		else
		{
			oneBefore->mNext = tmp->mNext;
		}
		delete tmp;
		mCount--;
	}
}

#endif

