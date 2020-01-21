//
//  MPQ.h
//  25205-SerhanSilahyurekli
//
//  Created by Serhan Silahyürekli on 25.11.2019.
//  Copyright © 2019 Serhan Silahyürekli. All rights reserved.
//

#ifndef MPQ_h
#define MPQ_h
#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

template <class Comparable>
class MPQ
{
public:

	MPQ(int size)
		:array(2 * size), location(2 * size)
	{};
	
	~MPQ() {};
	bool find(int a)
	{
		
			if (location[a] != 0)
				return true;
		
		return false;
	}
	void insert(Comparable  value, int label)
	{

		// Percolate up
		// Note that instead of swapping we move the hole up
		int hole = ++currentSize;
		for (; hole > 1 && value > array[hole / 2]; hole /= 2)
		{
			array[hole] = array[hole / 2];
			location[array[hole].getlabel()] = hole;
		}
		array[hole] = value;
		location[label] = hole;

	}

	Comparable remove( int label)
	{
		if (IsEmpty()) {
			throw "There is no such item";

		}
		else
		{
			//saving the wanted value before removal
			Comparable dummy;
			Comparable tmp = array[location[label]];
			//assigning the last item to the item at
			//position labels[l].
			array[location[label]] = array[currentSize--];
			array[currentSize + 1] = dummy;
			//then, changing the coordinate recorded
			//to labels[l](it was currentSize's coordinate)

			//deleting the coordinate recorded to label[l]
			// because we just delete it
			location[label] = 0;

			percolateDown(label);
			return tmp;
		}
	}

	Comparable GetMax()
	{
		Comparable temp = array[1];
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i].getheight() > temp.getheight())
				temp = array[i];
		}
		return temp;
	}
	bool IsEmpty()
	{
		if (currentSize == 0)
		{
			return true;
		}
		return false;
	}
	vector<Comparable> array;
	vector<int> location;
	int currentSize;
private:
	void percolateDown(int hole)
	{
		int child;
		Comparable tmp = array[hole]; // tmp is the item that will
									  // be percolated down

		for (; hole * 2 <= currentSize; hole = child)
		{
			child = hole * 2;
			if (child != currentSize && array[child + 1] < array[child])
				child++;  // child is the minimum of the children
			if (array[child] > tmp)
			{
				array[hole] = array[child]; // swap hole and min child
				location[array[hole].getlabel()] = hole;
			}
			else
				break;
		}
		array[hole] = tmp;
		location[array[hole].getlabel()] = hole;
	}
	
};

#endif /* MPQ_h */
