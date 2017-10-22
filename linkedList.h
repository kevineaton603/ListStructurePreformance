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
	Node<T> * mHead;
	long mCount;
public:
	LinkedList();
	~LinkedList();
	void clear();
	void insert(T data);
	bool isExist(T data);
	bool isEmpty();
	void print();
	void remove(T data);
	void removeAt(long index);
};
template<typename T>
LinkedList<T>::LinkedList()
{
	mHead = NULL;
	mCount = 0;
}
template<typename T>
LinkedList<T>::~LinkedList()
{
	this->clear();
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
	}
	else if (data < mHead->mData)
	{
		newNode->mNext = mHead;
		mHead = newNode;
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
void LinkedList<T>::print()
{
	Node<T> * tmp;
	if (!this->isEmpty())
	{
		tmp = mHead;
		while (tmp != NULL)
		{
			std::cout << tmp->mData << std::endl;
			tmp = tmp->mNext;
		}
	}
}
template<typename T>
void LinkedList<T>::remove(T data)
{
	Node<T> * tmp, * oneBefore;
	bool removed = false;
	if (mHead->mData == data)
	{
		delete mHead;
		removed = true;
	}
	else
	{
		tmp = mHead->mNext;
		oneBefore = mHead;
		while (tmp != NULL)
		{
			if (data == tmp->mData)
			{
				oneBefore->mNext = tmp->mNext;
				delete tmp;
				removed = true;
				mCount--;
			}
			else
			{
				oneBefore = tmp;
				tmp = tmp->mNext;
			}
		}
	}
	if (!removed)
		mCount--;
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

