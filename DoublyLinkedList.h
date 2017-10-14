/*
*	Author:				Andrew Rimpici
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

template<typename T>
class DoublyLinkedList
{
private:
	template<typename R>
	struct Node
	{
		R mData;
		Node<R> *mPrev;
		Node<R> *mNext;

		Node() : Node(R())
		{
			
		}

		Node(R data) :
			mData(data),
			mPrev(nullptr),
			mNext(nullptr)
		{

		}

		~Node()
		{
			mPrev = nullptr;
			mNext = nullptr;
		}
	};

public:
	Node<T> *mHead;
	Node<T> *mTail;
	int mCount;

	DoublyLinkedList();
	~DoublyLinkedList();

	void getCount() const;
	T getData(int index) const;

	void add(T element);
	void remove(T element);
	void removeAt(int index, T element);
	void set(int index, T element);
};

#endif