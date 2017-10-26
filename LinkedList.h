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

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

template <typename T>
class LinkedList
{
private:
	template <typename R>
	struct Node
	{
		Node<R> *mNext;
		R mData;
		
		/*
		 * Pre: None.
		 * Post: Creates a new node.
		 * Purpose: To create a new node object.
		 * Author: Kevin Eaton
		 */
		Node<R>()
		{
			mNext = nullptr;
		}

		/*
		* Pre: Data for the node.
		* Post: Creates a new node.
		* Purpose: To create a new node object.
		* Author: Kevin Eaton
		*/
		Node<R>(R data)
		{
			mNext = nullptr;
			mData = data;
		}

		/*
		* Pre: None.
		* Post: Destroys a node object.
		* Purpose: To destroy the node and free the memory.
		* Author: Kevin Eaton
		*/
		~Node<R>()
		{
			mNext = nullptr;
		}
	};

	Node<T> *mHead, *mTail;
	int mLength;

public:

	/*
	* Pre: None.
	* Post: Returns a LinkedList object.
	* Purpose: Creates a LinkedList object.
	* Author: Kevin Eaton
	*/
	LinkedList();

	/*
	* Pre: None.
	* Post: None.
	* Purpose: Destroys a LinkedList object.
	* Author: Kevin Eaton
	*/
	~LinkedList();
	
	/*
	* Pre: The data to append to the linked list.
	* Post: None.
	* Purpose: Adds the data to the beginning of the list.
	* Author: Andrew Rimpici
	*/
	void append(T data);

	/*
	* Pre: The data to prepend to the linked list.
	* Post: None.
	* Purpose: Adds the data to the end of the list.
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
	* Author: Kevin Eaton
	*/
	void clear();

	/*
	* Pre: The index to remove at.
	* Post: None.
	* Purpose: Deletes the node at the specified index
	* Author: Kevin Eaton
	*/
	void removeAt(int index);

	/*
	* Pre: None.
	* Post: Returns true if list is empty and false otherwise.
	* Purpose: Checks if the list is empty.
	* Author: Kevin Eaton
	*/
	bool isEmpty();

	/*
	* Pre: None.
	* Post: Returns the number of nodes in the list.
	* Purpose: To get the length of the list.
	* Author: Andrew Rimpici
	*/
	int getLength();

	/*
	* Pre: None.
	* Post: None.
	* Purpose: Prints out the list to the console.
	* Author: Kevin Eaton
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
	* Author: Kevin Eaton
	*/
	static void merge(LinkedList<T> &list1, LinkedList<T> &list2, LinkedList<T> &destination);
};


/*
* Pre: None.
* Post: None.
* Purpose: Creates a LinkedList object.
* Author: Kevin Eaton
*/
template <typename T>
LinkedList<T>::LinkedList()
{
	mHead = nullptr;
	mTail = nullptr;
	mLength = 0;
}


/*
* Pre: None.
* Post: None.
* Purpose: Destroys a LinkedList object.
* Author: Kevin Eaton
*/
template <typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}


/*
* Pre: The data to append to the linked list.
* Post: None.
* Purpose: Adds the data to the end of the list.
* Author: Andrew Rimpici
*/
template <typename T>
void LinkedList<T>::append(T data)
{
	insert(mLength, data);
}


/*
* Pre: The data to prepend to the linked list.
* Post: None.
* Purpose: Adds the data to the beginning of the list.
* Author: Andrew Rimpici
*/
template <typename T>
void LinkedList<T>::prepend(T data)
{
	insert(0, data);
}


/*
* Pre: The data to insert into the linked list.
* Post: None.
* Purpose: Adds the data to the list in ascending order.
* Author: Andrew Rimpici
*/
template <typename T>
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

	mLength++;
}


/*
* Pre: The index and data to insert into the linked list.
* Post: None.
* Purpose: Adds the data to the list at the specified index.
* Author: Andrew Rimpici
*/
template <typename T>
void LinkedList<T>::insert(int index, T data)
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
			mHead = newNode;
		}
		else if (index == mLength)
		{
			mTail->mNext = newNode;
			mTail = newNode;
		}
		else
		{
			Node<T> *previousNode = mHead;
			Node<T> *currentNode = mHead;
			int i;

			for (i = 0; i < index; ++i)
			{
				if (currentNode->mNext != nullptr)
				{
					previousNode = currentNode;
					currentNode = currentNode->mNext;
				}
				else
				{
					break;
				}
			}

			newNode->mNext = currentNode;
			previousNode->mNext = newNode;
		}

		++mLength;
	}
}


/*
* Pre: None.
* Post: None.
* Purpose: Deletes all of the nodes from the list.
* Author: Kevin Eaton
*/
template <typename T>
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
	mLength = 0;
}


/*
* Pre: The index to remove at.
* Post: None.
* Purpose: Deletes the node at the specified index
* Author: Kevin Eaton
*/
template <typename T>
void LinkedList<T>::removeAt(int index)
{
	Node<T> *tmp, *oneBefore;
	int i = 0;
	bool removed = false;

	tmp = mHead->mNext;
	oneBefore = mHead;

	if (index < 0 || index >= mLength)
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
		mLength--;
	}
}


/*
* Pre: None.
* Post: Returns true if list is empty and false otherwise.
* Purpose: Checks if the list is empty.
* Author: Kevin Eaton
*/
template <typename T>
bool LinkedList<T>::isEmpty()
{
	return mHead == nullptr;
}


/*
* Pre: None.
* Post: Returns the number of nodes in the list.
* Purpose: To get the length of the list.
* Author: Andrew Rimpici
*/
template <typename T>
int LinkedList<T>::getLength()
{
	return mLength;
}


/*
* Pre: None.
* Post: None.
* Purpose: Prints out the list to the console.
* Author: Andrew Rimpici
*/
template <typename T>
void LinkedList<T>::print() const
{
	Node<T> *currentNode = mHead;

	std::cout << "Linked List has " << std::to_string(mLength) << " elements: ";

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

	std::cout << currentNode->mData << std::endl;
}


/*
* Pre: The searchkey and bool to know if the list is sorted in ascending order.
* Post: Returns true if searchkey is in the list and false otherwise.
* Purpose: To check if searchkey is in the list.
* Author: Andrew Rimpici
*/
template <typename T>
bool LinkedList<T>::sequentialSearch(T searchKey, bool isSorted)
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
* Pre: Two lists to merge together. **Both lists must be in ascending order.**
* Post: Returns a new linked list.
* Purpose: Merges the two lists together.
* Author: Kevin Eaton
*/
template <typename T>
void LinkedList<T>::merge(LinkedList<T> &list1, LinkedList<T> &list2, LinkedList<T> &destination)
{
	Node<T> *tmp, *tmp2;

	if (list1.mLength > 0 && list2.mLength > 0)
	{
		tmp = list1.mHead;
		tmp2 = list2.mHead;

		while (tmp != nullptr && tmp2 != nullptr)
		{
			if (tmp->mData <= tmp2->mData)
			{
				destination.append(tmp->mData);
				tmp = tmp->mNext;
			}
			else
			{
				destination.append(tmp2->mData);
				tmp2 = tmp2->mNext;
			}
		}

		while (tmp != nullptr)
		{
			destination.append(tmp->mData);
			tmp = tmp->mNext;
		}

		while (tmp2 != nullptr)
		{
			destination.append(tmp2->mData);
			tmp2 = tmp2->mNext;
		}
	}
}

#endif

