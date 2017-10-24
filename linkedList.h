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
		Node<R> *mNext;
		R mData;
		
		Node()
		{
			mNext = nullptr;
		}

		Node(R data)
		{
			mNext = nullptr;
			mData = data;
		}

		~Node()
		{
			mNext = nullptr;
		}
	};

	Node<T> *mHead, *mTail;
	int mCount;

public:
	LinkedList();
	~LinkedList();
	
	void append(const T &data);
	void clear();
	void insert(T data);
	bool isExist(T data);
	bool isEmpty();
	void print();
	void removeAt(int index);
	
	static LinkedList<T>* merge(LinkedList<T> &list1, LinkedList<T> &list2);
};

template<typename T>
LinkedList<T>::LinkedList()
{
	mHead = nullptr;
	mTail = nullptr;
	mCount = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template<typename T>
void LinkedList<T>::append(const T &data)
{
	Node<T> *newNode = new Node<T>(data);
	if (mHead == nullptr)
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

	while (tmp != nullptr)
	{
		toBeDeleted = tmp;
		tmp = tmp->mNext;
		toBeDeleted->mNext = nullptr;
		delete toBeDeleted;
	}

	mHead = nullptr;
	mTail = nullptr;
	mCount = 0;
}

template<typename T>
void LinkedList<T>::insert(T data)
{
	Node<T> *newNode = new Node<T>(data);
	Node<T> *tmp, *oneBefore;

	if (newNode == nullptr)
	{
		return;
	}
	else if (mHead == nullptr)
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
		while (tmp != nullptr && tmp->mData < data)
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
	Node<T> *tmp;
	if (mHead == nullptr)
	{
		return false;
	}
	
	tmp = mHead;
	while (tmp != nullptr)
	{
		if (tmp->mData == data)
		{
			return true;
		}

		tmp = tmp->mNext;
	}

	return false;
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
	return mHead == nullptr;
}

template<typename T>
LinkedList<T>* LinkedList<T>::merge(LinkedList<T> &list1, LinkedList<T> &list2)
{
	Node<T> *tmp, *tmp2;
	LinkedList<T> *newList = new LinkedList<T>();

	if (list1.mHead != nullptr && list2.mHead != nullptr)
	{
		if (list1.mHead != nullptr && list2.mHead == nullptr)
		{
			newList = &list1;
		}
		else if (list1.mHead == nullptr && list2.mHead != nullptr)
		{
			newList = &list2;
		}
		else
		{
			tmp = list1.mHead;
			tmp2 = list2.mHead;
			while (tmp != nullptr && tmp2 != nullptr)
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

			while (tmp != nullptr)
			{
				newList->append(tmp->mData);
				tmp = tmp->mNext;
			}
			
			while (tmp2 != nullptr)
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
	Node<T> *tmp;
	int i = 0; 
	
	if (!this->isEmpty())
	{
		tmp = mHead;
		
		while (tmp != nullptr)
		{
			std::cout << i << ": " <<tmp->mData << std::endl;
			tmp = tmp->mNext;
			i++;
		}
	}
}

template<typename T>
void LinkedList<T>::removeAt(int index)
{
	Node<T> *tmp, *oneBefore;
	int i = 0;
	bool removed = false;

	tmp = mHead->mNext;
	oneBefore = mHead;
	
	if (index == 0 || index >= mCount)
	{
		return;
	}
	else if (mHead != nullptr)
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

