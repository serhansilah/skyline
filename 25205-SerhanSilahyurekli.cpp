#include <iostream>
#include <stdio.h>
#include "MPQ.h"
#include "Object.h"
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int partition(vector<Object> & arr, int low, int high)
{
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j].getstartx()< arr[high].getstartx())
		{
			i++; // increment index of smaller element
			Object temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else if (arr[j].getstartx() == arr[high].getstartx())
		{
			if (arr[j].getheight()> arr[high].getheight())
			{
				i++; // increment index of smaller element
				Object temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	Object temp = arr[high];
	arr[high] = arr[i + 1];
	arr[i + 1] = temp;
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(vector<Object> & arr, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void process(MPQ<Object> & tmp, vector<Object> & arr, int size)
{
	bool now = false;
	bool special = true;
	
	Object a = tmp.GetMax();
	for (int i = 0; i < 2 * size; i++)
	{
		if (special)
		{//for 0 and the first insert
			Object b = arr[i];
			if (b.getstartx() != 0)
			{
				cout << "0" << " " << "0" << endl;
				tmp.insert(arr[i], arr[i].getlabel());
				Object c = tmp.GetMax();
				cout << b.getstartx() << " " << c.getheight() << endl;
				special = false;
			}
			
			else
			{

				tmp.insert(arr[i], arr[i].getlabel());
				Object y = tmp.GetMax();
				cout << 0 << " " << y.getheight() << endl;
				special = false;

			}
		}
		else
		{//if we see same albel we will remove it
			Object t = arr[i];
			if (tmp.find(t.getlabel()))
			{
				Object oldmax = tmp.GetMax();
				tmp.remove(t.getlabel());
				Object newmax = tmp.GetMax();
				if (2*size >= i )
				{
					
					if (oldmax != newmax && t.getstartx() != arr[i+1].getstartx())
					{
						cout << t.getstartx() << " " << newmax.getheight() << endl;
					}
				}
			}
			else
			{//inserting new label
				Object oldmax = tmp.GetMax();	
				tmp.insert(t, t.getlabel());
				Object newmax = tmp.GetMax();
				if (2*size >= i )
				{
	
					if (oldmax != newmax &&  t.getheight() != arr[i -1].getheight())
					{
						cout << t.getstartx() << " " << t.getheight() << endl;
					}
				}
			}
		}
	}
	cout << arr[arr.size() - 1].getstartx() << " " << "0" << endl;

}
int main()
{
	bool first = false;
	ifstream file;
	string filename = "input.txt";
	file.open(filename.c_str());//open the file
	string line;
	int start, tall, last, size;
	int count = 0;
	vector<Object> hold;
	if (file.fail())
	{
		cout << "File did not open.";
		return 0;
	}
	while (getline(file, line))
	{
		istringstream file(line);
		if (!first)
		{
			file >> size;
			first = true;
		}
		else
		{
			count++;
			file >> start >> tall >> last;
			Object left(start, tall, count);
			hold.push_back(left);
			Object right(last, tall, count);
			hold.push_back(right);
		}
	}
	file.close();

	MPQ<Object> heap(size);
	quickSort(hold, 0, size*2-1);
	process(heap, hold, size);
	return 0;
}
