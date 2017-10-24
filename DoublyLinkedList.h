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

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

#include <iostream>
#include <string>

template <typename T>
class DoublyLinkedList
{
private:
	template <typename R>
	struct Node
	{
		R mData;
		Node<T> *mNext;
		Node<T> *mPrev;

		/* Pre:		None.
		*  Post:	Creates a new node object.
		*  Purpose: To create a new node that holds data in the linked list.
		**************************************************************************************************/
		Node<R>() : mData(R()), mNext(nullptr), mPrev(nullptr)
		{

		}

		/* Pre:		A piece of data for the node to hold.
		*  Post:	Creates a new node object.
		*  Purpose: To create a new node that holds data in the linked list.
		**************************************************************************************************/
		Node<R>(R data) : mData(data), mNext(nullptr), mPrev(nullptr)
		{

		}

		/* Pre:		None.
		*  Post:	None.
		*  Purpose: Deletes the node and sets its pointers to null.
		**************************************************************************************************/
		~Node<R>()
		{
			mNext = nullptr;
			mPrev = nullptr;
		}
	};

	Node<T> *mHead;
	Node<T> *mTail;
	int mLength;

public:
	DoublyLinkedList<T>();
	~DoublyLinkedList<T>();

	int getLength() const;
	T getData(int index) const;
	void setData(int index, T data);

	void clear();
	void insert(T data);
	void insert(int index, T data);
	bool isEmpty();
	bool isExist(T searchKey);
	void printListAscending();
	void printListDescending();
	void prepend(T data);
	int remove(T data);
	T removeAt(int index);

	static DoublyLinkedList<T>* merge(DoublyLinkedList<T> *first, DoublyLinkedList<T> *second);
};

/* Pre:		None.
*  Post:	Creates a new linked list object.
*  Purpose: To create a new linked list object.
**************************************************************************************************/
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : mHead(nullptr), mTail(nullptr)
{

}

/* Pre:		None.
*  Post:	None.
*  Purpose: To clear and delete the linked list.
**************************************************************************************************/
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	clear();
}

/* Pre:		None.
*  Post:	Returns the length of the list.
*  Purpose: To get how big the list is.
**************************************************************************************************/
template<typename T>
int DoublyLinkedList<T>::getLength() const
{
	return mLength;
}

/* Pre:		The index to get the data from.
*  Post:	Returns the data at the index in the list.
*  Purpose: To get the data at the specific index.
**************************************************************************************************/
template<typename T>
T DoublyLinkedList<T>::getData(int index) const
{
	int i;
	Node<T> *currentNode;

	if (index < 0 || index >= mLength)
	{
		return T();
	}
	else
	{
		currentNode = mHead;
		for (i = 0; i < index; ++i)
		{
			currentNode = currentNode->mNext;
		}

		return currentNode->mData;
	}
}

/* Pre:		The index and the data to set the index with.
*  Post:	Sets the current index to the data.
*  Purpose: To set a node's data at a specific index.
**************************************************************************************************/
template<typename T>
void DoublyLinkedList<T>::setData(int index, T data)
{
	int i;
	Node<T> *currentNode;

	if (index < 0 || index >= mLength)
	{
		return;
	}
	else
	{
		currentNode = mHead;
		for (i = 0; i < index; ++i)
		{
			currentNode = currentNode->mNext;
		}

		currentNode->mData = data;
	}
}

/* Pre:		None.
*  Post:	None.
*  Purpose: To clear and delete the list of all its nodes.
**************************************************************************************************/
template<typename T>
void DoublyLinkedList<T>::clear()
{
	//List is already empty.
	if (mHead == nullptr)
	{
		return;
	}

	//While the element after head is not null.
	while (mHead->mNext != nullptr)
	{
		mHead = mHead->mNext;
		delete mHead->mPrev;
		mHead->mPrev = nullptr;
		--mLength;
	}

	//If there is only one element left in the list.
	if (mHead == mTail)
	{
		delete mHead;
		--mLength;
	}

	mHead = nullptr;
	mTail = nullptr;
}

/* Pre:		Data to insert into the list.
*  Post:	None.
*  Purpose: To insert new data into the list.
**************************************************************************************************/
template<typename T>
void DoublyLinkedList<T>::insert(T data)
{
	Node<T> *newNode = new Node<T>(data);

	if (newNode == nullptr)
	{
		return;
	}
	else if (mHead == nullptr)
	{
		mHead = newNode;
		mTail = newNode;
		++mLength;
	}
	else
	{
		if (mHead->mData >= newNode->mData)
		{
			newNode->mNext = mHead;
			mHead->mPrev = newNode;
			mHead = newNode;
			++mLength;
		}
		else if (mTail->mData <= newNode->mData)
		{
			mTail->mNext = newNode;
			newNode->mPrev = mTail;
			mTail = newNode;
			++mLength;
		}
		else
		{
			Node<T> *nextNode = mHead->mNext;

			while (nextNode != nullptr)
			{
				if (nextNode->mData >= newNode->mData)
				{
					newNode->mNext = nextNode;
					newNode->mPrev = nextNode->mPrev;
					nextNode->mPrev = newNode;
					newNode->mPrev->mNext = newNode;
					++mLength;
					return;
				}

				nextNode = nextNode->mNext;
			}
		}
	}
}

template<typename T>
void DoublyLinkedList<T>::insert(int index, T data)
{
	if (index < 0)
	{
		index = 0;
	}
	else if (index > mLength)
	{
		index = mLength;
	}

	Node<T> *newNode = new Node<T>(data);

	if (newNode == nullptr)
	{
		return;
	}
	else
	{
		if (mHead == nullptr)
		{
			mHead = newNode;
			mTail = newNode;
		}
		else if (index == 0)
		{
			newNode->mNext = mHead;
			mHead->mPrev = newNode;
			mHead = newNode;
		}
		else if (index == mLength)
		{
			mTail->mNext = newNode;
			newNode->mPrev = mTail;
			mTail = newNode;
		}
		else
		{
			Node<T> *currentNode = mHead;
			int i;

			for (i = 0; i < index; ++i)
			{
				if (currentNode->mNext != nullptr)
				{
					currentNode = currentNode->mNext;
				}
				else
				{
					break;
				}
			}

			newNode->mNext = currentNode;
			newNode->mPrev = currentNode->mPrev;
			currentNode->mPrev = newNode;
			newNode->mPrev->mNext = newNode;
		}

		++mLength;
	}
}

/* Pre:		None.
*  Post:	Returns if the list is empty.
*  Purpose: To determine if the list is holding any nodes.
**************************************************************************************************/
template<typename T>
bool DoublyLinkedList<T>::isEmpty()
{
	return mHead == nullptr;
}

/* Pre:		Data to see if it is in the list.
*  Post:	A bool if the data was found in the list.
*  Purpose: To see if the data is in the list.
**************************************************************************************************/
template<typename T>
bool DoublyLinkedList<T>::isExist(T searchKey)
{
	bool found = false;
	Node<T> *currentNode = mHead;

	while (currentNode != nullptr)
	{
		if (currentNode->mData == searchKey)
		{
			found = true;
			break;
		}
		else if (currentNode->mData < searchKey)
		{
			break;
		}
		else
		{
			currentNode = currentNode->mNext;
		}
	}

	return found;
}

/* Pre:		None.
*  Post:	None.
*  Purpose: Prints the list from least to greatest.
**************************************************************************************************/
template<typename T>
void DoublyLinkedList<T>::printListAscending()
{
	Node<T> *currentNode = mHead;

	std::cout << "List has " << std::to_string(mLength) << " elements:";

	while (currentNode != nullptr)
	{
		std::cout << " " << currentNode->mData;
		currentNode = currentNode->mNext;
	}

	std::cout << std::endl;
}

/* Pre:		None.
*  Post:	None.
*  Purpose: Prints the list from greatest to least.
**************************************************************************************************/
template<typename T>
void DoublyLinkedList<T>::printListDescending()
{
	Node<T> *currentNode = mTail;

	std::cout << "List has " << std::to_string(mLength) << " elements:";

	while (currentNode != nullptr)
	{
		std::cout << " " << currentNode->mData;
		currentNode = currentNode->mPrev;
	}

	std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::prepend(T data)
{
	Node<T> *newNode = new Node<T>(data);
	
	if (newNode == nullptr)
	{
		return;
	}
	else if (mHead == nullptr)
	{
		mHead = newNode;
		mTail = newNode;
		++mLength;
	}
	else
	{
		mTail->mNext = newNode;
		newNode->mPrev = mTail;
		mTail = newNode;
		++mLength;
	}
}

/* Pre:		The data value to remove from the list.
*  Post:	The amount of nodes removed from the list.
*  Purpose: Removes **ALL OCCURENCES** of the data.
**************************************************************************************************/
template<typename T>
int DoublyLinkedList<T>::remove(T data)
{
	int amountRemoved = 0;

	if (mHead != nullptr)
	{
		Node<T> *prevNode;
		Node<T> *currentNode = mHead;
		Node<T> *nextNode;

		while (currentNode != nullptr)
		{
			prevNode = currentNode->mPrev;
			nextNode = currentNode->mNext;

			if (currentNode->mData == data)
			{
				if (prevNode != nullptr)
				{
					prevNode->mNext = nextNode;
				}
				else
				{
					mHead = currentNode->mNext;
				}

				if (nextNode != nullptr)
				{
					nextNode->mPrev = prevNode;
				}
				else
				{
					mTail = currentNode->mPrev;
				}

				currentNode->mPrev = nullptr;
				currentNode->mNext = nullptr;
				delete currentNode;
				++amountRemoved;
				--mLength;
			}

			currentNode = nextNode;
		}
	}

	return amountRemoved;
}

/* Pre:		The index in the list to remove the node.
*  Post:	The data that was in the removed node.
*  Purpose: To remove a node in the list at a specific index.
**************************************************************************************************/
template<typename T>
T DoublyLinkedList<T>::removeAt(int index)
{
	int i;
	Node<T> *prevNode;
	Node<T> *currentNode;
	Node<T> *nextNode;
	T data = T();

	if (index < 0 || index >= mLength)
	{
		return data;
	}
	else
	{
		currentNode = mHead;
		for (i = 0; i < index; ++i)
		{
			currentNode = currentNode->mNext;
		}

		data = currentNode->mData;

		prevNode = currentNode->mPrev;
		nextNode = currentNode->mNext;

		if (prevNode != nullptr)
		{
			prevNode->mNext = nextNode;
		}
		else
		{
			mHead = currentNode->mNext;
		}

		if (nextNode != nullptr)
		{
			nextNode->mPrev = prevNode;
		}
		else
		{
			mTail = currentNode->mPrev;
		}

		delete currentNode;
		--mLength;

		return data;
	}
}

template<typename T>
DoublyLinkedList<T>* DoublyLinkedList<T>::merge(DoublyLinkedList<T> *first, DoublyLinkedList<T> *second)
{
	if (first == nullptr && second == nullptr)
	{
		return nullptr;
	}
	else if (first != nullptr && second == nullptr)
	{
		return first;
	}
	else if (first == nullptr && second != nullptr)
	{
		return second;
	}
	else if (second->mLength <= 0)
	{
		return first;
	}
	else if (first->mLength <= 0)
	{
		return second;
	}
	else
	{
		DoublyLinkedList<T> *mergedList = new DoublyLinkedList<T>();
		Node<T> *list1CurrentNode = first->mHead;
		Node<T> *list2CurrentNode = second->mHead;
		int targetLength = first->mLength + second->mLength;

		while (mergedList->mLength < targetLength)
		{
			if (list1CurrentNode == nullptr)
			{
				//add rest of list2 to merge list
				while (list2CurrentNode != nullptr)
				{
					mergedList->prepend(list2CurrentNode->mData);
					list2CurrentNode = list2CurrentNode->mNext;
				}
			}
			else if (list2CurrentNode == nullptr)
			{
				//add rest of list1 to merge list
				while (list1CurrentNode != nullptr)
				{
					mergedList->prepend(list1CurrentNode->mData);
					list1CurrentNode = list1CurrentNode->mNext;
				}
			}
			else if (list1CurrentNode->mData >= list2CurrentNode->mData)
			{
				//add list2data to merge list
				mergedList->prepend(list2CurrentNode->mData);
				list2CurrentNode = list2CurrentNode->mNext;
			}
			else if (list2CurrentNode->mData >= list1CurrentNode->mData)
			{
				//add list1data to merge list
				mergedList->prepend(list1CurrentNode->mData);
				list1CurrentNode = list1CurrentNode->mNext;
			}
		}

		return mergedList;
	}
}

#endif