/*
*	Author:				Andrew Rimpici, Kevin Eaton
*	Class:				Data Structures and Algorithms CSI-281-01
*	Assignment:			PA5
*	Date Assigned:		10/19/2017
*	Due Date:			10/26/2017
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

		/*
		* Pre: None.
		* Post: Creates a new node.
		* Purpose: To create a new node object.
		* Author: Andrew Rimpici
		*/
		Node<R>() : mData(R()), mNext(nullptr), mPrev(nullptr)
		{

		}

		/*
		* Pre: The data for the node.
		* Post: Creates a new node.
		* Purpose: To create a new node object.
		* Author: Andrew Rimpici
		*/
		Node<R>(R data) : mData(data), mNext(nullptr), mPrev(nullptr)
		{

		}

		/*
		* Pre: None.
		* Post: Destroys a node object.
		* Purpose: To destroy the node and free the memory.
		* Author: Andrew
		*/
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

	/*
	* Pre: None.
	* Post: Returns a DoublyLinkedList object.
	* Purpose: Creates a DoublyLinkedList object.
	* Author: Andrew Rimpici
	*/
	DoublyLinkedList<T>();

	/*
	* Pre: None.
	* Post: None.
	* Purpose: Destroys a DoublyLinkedList object.
	* Author: Andrew Rimpici
	*/
	~DoublyLinkedList<T>();

	/*
	* Pre: The data to append to the linked list.
	* Post: None.
	* Purpose: Adds the data to the end of the list.
	* Author: Andrew Rimpici
	*/
	void append(T data);

	/*
	* Pre: The data to prepend to the linked list.
	* Post: None.
	* Purpose: Adds the data to the beginning of the list.
	* Author: Andrew Rimpici
	*/
	void prepend(T data);

	/*
	* Pre: The data to insert into the linked list.
	* Post: None.
	* Purpose: Adds the data to the list in ascending order.
	* Author: Andrew Rimpici
	*/
	void insert(T data);

	/*
	* Pre: The index and data to insert into the linked list.
	* Post: None.
	* Purpose: Adds the data to the list at the specified index.
	* Author: Andrew Rimpici
	*/
	void insert(int index, T data);

	/*
	* Pre: None.
	* Post: None.
	* Purpose: Deletes all of the nodes from the list.
	* Author: Andrew Rimpici
	*/
	void clear();

	/*
	* Pre: The index to remove at.
	* Post: None.
	* Purpose: Deletes the node at the specified index
	* Author: Andrew Rimpici
	*/
	T	 removeAt(int index);

	/*
	* Pre: None.
	* Post: Returns true if list is empty and false otherwise.
	* Purpose: Checks if the list is empty.
	* Author: Andrew Rimpici
	*/
	bool isEmpty();

	/*
	* Pre: None.
	* Post: Returns the number of nodes in the list.
	* Purpose: To get the length of the list.
	* Author: Andrew Rimpici
	*/
	int getLength() const;

	/*
	* Pre: None.
	* Post: None.
	* Purpose: Prints out the list to the console.
	* Author: Andrew Rimpici
	*/
	void print() const;

	/*
	* Pre: The searchkey and bool to know if the list is sorted in ascending order.
	* Post: Returns true if searchkey is in the list and false otherwise.
	* Purpose: To check if searchkey is in the list.
	* Author: Andrew Rimpici
	*/
	bool sequentialSearch(T searchKey, bool isSorted);

	/*
	* Pre: Two lists to merge together.
	* Post: None.
	* Purpose: Merges the two lists together.
	* Author: Andrew Rimpici
	*/
	static void merge(DoublyLinkedList<T> &first, DoublyLinkedList<T> &second, DoublyLinkedList<T> &destination);


	//Not sure if i need these come back to this.
	/*
	* Pre: None.
	* Post: A new DoublyLinkedList.
	* Purpose: To copy a linked list into a new one.
	* Author: Andrew Rimpici
	*/
	DoublyLinkedList<T>* copy();
	T getData(int index) const;
	void setData(int index, T data);
	int  removeAll(T data);
};


/*
* Pre: None.
* Post: Returns a DoublyLinkedList object.
* Purpose: Creates a DoublyLinkedList object.
* Author: Andrew Rimpici
*/
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : mHead(nullptr), mTail(nullptr)
{

}


/*
* Pre: None.
* Post: None.
* Purpose: Destroys a DoublyLinkedList object.
* Author: Andrew Rimpici
*/
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	clear();
}


/*
* Pre: The data to append to the linked list.
* Post: None.
* Purpose: Adds the data to the end of the list.
* Author: Andrew Rimpici
*/
template<typename T>
void DoublyLinkedList<T>::append(T data)
{
	insert(mLength, data);
}


/*
* Pre: The data to prepend to the linked list.
* Post: None.
* Purpose: Adds the data to the beginning of the list.
* Author: Andrew Rimpici
*/
template<typename T>
void DoublyLinkedList<T>::prepend(T data)
{
	insert(0, data);
}


/*
* Pre: The data to insert into the linked list.
* Post: None.
* Purpose: Adds the data to the list in ascending order.
* Author: Andrew Rimpici
*/
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


/*
* Pre: The index and data to insert into the linked list.
* Post: None.
* Purpose: Adds the data to the list at the specified index.
* Author: Andrew Rimpici
*/
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


/*
* Pre: None.
* Post: None.
* Purpose: Deletes all of the nodes from the list.
* Author: Andrew Rimpici
*/
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


/*
* Pre: The index to remove at.
* Post: None.
* Purpose: Deletes the node at the specified index
* Author: Andrew Rimpici
*/
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


/*
* Pre: None.
* Post: Returns true if list is empty and false otherwise.
* Purpose: Checks if the list is empty.
* Author: Andrew Rimpici
*/
template<typename T>
bool DoublyLinkedList<T>::isEmpty()
{
	return mHead == nullptr;
}


/*
* Pre: None.
* Post: Returns the number of nodes in the list.
* Purpose: To get the length of the list.
* Author: Andrew Rimpici
*/
template<typename T>
int DoublyLinkedList<T>::getLength() const
{
	return mLength;
}


/*
* Pre: None.
* Post: None.
* Purpose: Prints out the list to the console.
* Author: Andrew Rimpici
*/
template<typename T>
void DoublyLinkedList<T>::print() const
{
	Node<T> *currentNode = mHead;

	std::cout << "Doubly Linked List has " << std::to_string(mLength) << " elements: ";

	if (currentNode == nullptr)
	{
		std::cout << std::endl;
		return;
	}

	while (currentNode->mNext != nullptr)
	{
		std::cout << currentNode->mData << " ";
		currentNode = currentNode->mNext;
	}

	std::cout << currentNode->mData << " " << std::endl;
}


/*
* Pre: The searchkey and bool to know if the list is sorted in ascending order.
* Post: Returns true if searchkey is in the list and false otherwise.
* Purpose: To check if searchkey is in the list.
* Author: Andrew Rimpici
*/
template<typename T>
bool DoublyLinkedList<T>::sequentialSearch(T searchKey, bool isSorted)
{
	Node<T> *currentNode = mHead;
	T currentElement;
	bool isFound = false;

	while (currentNode != nullptr)
	{
		currentElement = currentNode->mData;

		if (currentElement == searchKey)
		{
			isFound = true;
			break;
		}
		else if (isSorted && searchKey < currentElement)
		{
			break;
		}
		else
		{
			currentNode = currentNode->mNext;
		}
	}

	return isFound;
}


/*
* Pre: Two lists to merge together.
* Post: Returns a new linked list.
* Purpose: Merges the two lists together.
* Author: Andrew Rimpici
*/
template<typename T>
void DoublyLinkedList<T>::merge(DoublyLinkedList<T> &first, DoublyLinkedList<T> &second, DoublyLinkedList<T> &destination)
{
	if (first.mLength > 0 && second.mLength > 0)
	{
		Node<T> *list1CurrentNode = first.mHead;
		Node<T> *list2CurrentNode = second.mHead;
		int targetLength = first.mLength + second.mLength;

		while (destination.mLength < targetLength)
		{
			if (list1CurrentNode == nullptr)
			{
				//add rest of list2 to merge list
				while (list2CurrentNode != nullptr)
				{
					destination.append(list2CurrentNode->mData);
					list2CurrentNode = list2CurrentNode->mNext;
				}
			}
			else if (list2CurrentNode == nullptr)
			{
				//add rest of list1 to merge list
				while (list1CurrentNode != nullptr)
				{
					destination.append(list1CurrentNode->mData);
					list1CurrentNode = list1CurrentNode->mNext;
				}
			}
			else if (list1CurrentNode->mData >= list2CurrentNode->mData)
			{
				//add list2data to merge list
				destination.append(list2CurrentNode->mData);
				list2CurrentNode = list2CurrentNode->mNext;
			}
			else if (list2CurrentNode->mData >= list1CurrentNode->mData)
			{
				//add list1data to merge list
				destination.append(list1CurrentNode->mData);
				list1CurrentNode = list1CurrentNode->mNext;
			}
		}
	}
}


/*
* Pre: None.
* Post: A new DoublyLinkedList.
* Purpose: To copy a linked list into a new one.
* Author: Andrew Rimpici
*/
template<typename T>
DoublyLinkedList<T>* DoublyLinkedList<T>::copy()
{
	DoublyLinkedList<T> *another = new DoublyLinkedList<T>();
	Node<T> *currentNode = mHead;

	for (int i = 0; i < mLength; ++i)
	{
		another->insert(currentNode->mData);
		currentNode = currentNode->mNext;
	}

	return another;
}

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

template<typename T>
int DoublyLinkedList<T>::removeAll(T data)
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

#endif