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

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/* Pre:		T array, lowerbound and upperbound
*  Post:	sorts using merge method
*  Purpose: sorts using merge method
*  Author: Kevin Eaton
*****************************************************************************/
template <typename T>
void merge(T *list, int lowerBound, int mid, int upperBound)
{
	int size1 = mid - lowerBound + 1;
	int size2 = upperBound - mid;
	T *left = new T[size1];
	T *right = new T[size2];
	int i, j, k;

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
*  Author: Kevin Eaton
*****************************************************************************/
template <typename T>
void mergeSort(T *list, int lowerBound, int upperBound)
{
	int mid;
	if (lowerBound < upperBound)
	{
		mid = (lowerBound + upperBound) / 2;
		mergeSort(list, lowerBound, mid);
		mergeSort(list, mid + 1, upperBound);
		merge(list, lowerBound, mid, upperBound);
	}
}

#endif