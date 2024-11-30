//************************************************
//
//	merge_sort.cpp
//	CSCI 241 Assignment 3
//
//	Created by Reinaldo Moraga (z1864815)
//
//************************************************

#include <iostream>
#include <iomanip>
using namespace std;

void merge(int array[], int start, int mid, int end)
{	//create temp array
	int temp[end-start+1];
	int i = start;
	int j = mid+1;
	int k = 0;

	//traverse both arrays and add both elements in temp
	while (i <= mid && j <= end)
	{
	    if (array[i] <= array[j])
	    {
		temp[k] = array[i];
		k++;
		i++;
	    }
	    else
	    {
		temp[k] = array[j];
		k++;
		j++;
	    }
	}
	//add elements in the first interval
	while (i <= mid)
	{
	    temp[k] = array[i];
	    k++;
	    i++;
	}
	//add elements in second interval
	while (j <= end)
	{
	    temp[k] = array[j];
	    k++;
	    j++;
	}
	//copy temp elements back to original
	for (i = start; i <= end; i++)
	{
	    array[i] = temp[i-start];
	}
}

void merge_sort(int array[], int start, int end)
{
	if (start < end)
	{   //midpoint of array
	    int mid = (start+end)/2;
	    //sort first and second halves
	    merge_sort(array, start, mid);
	    merge_sort(array, mid+1, end);

	    merge(array, start, mid, end);
	}
}

int main()
{	//create array
	int num;
        int array[1000];
        int count = 0;

	//read text file and put numbers in array
        while (cin >> num)
        {
             array[count] = num;
             count++;
        }

	//compute start and end
	//call merge_sort function
	int start = 0;
	int end = count-1;
	merge_sort(array, start, end);

	//print array
	int lc = 0;
        for (int i = 0; i < count; i++)
	{
	    if (lc != 8)
	    {
            	cout << setw(8) << array[i];
		lc++;
	    }
	    else
	    {
		cout << endl << setw(8) << array[i];
		lc = 1;
	    }
	}

	cout << endl;
	return 0;
}
