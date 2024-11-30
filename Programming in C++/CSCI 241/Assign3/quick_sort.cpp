//************************************************
//
//	quick_sort.cpp
//	CSCI 241 Assignment 3
//
//	Created by Reinaldo Moraga (z1864815)
//
//************************************************

#include <iostream>
#include <iomanip>
using namespace std;

//Paritioning the array
int partition(int array[], int start, int end)
{	//midpoint of array
        int mid = (start+end)/2;

	//swap first and middle elements
        int temp;
        temp = array[start];
        array[start] = array[mid];
        array[mid] = temp;

	//compute pivot_index, pivot_value, and scan
        int pivot_index = start;
        int pivot_value = array[start];

        int scan = start+1;

        while (scan <= end)
        {   //if current element is smaller than pivot
            if (array[scan] < pivot_value)
            {
		//pivot moves up array
                pivot_index = pivot_index+1;
		//swap pivot and scan elements
                temp = array[pivot_index];
                array[pivot_index] = array[scan];
                array[scan] = temp;
            }
	    //scan goes up the array
            scan = scan+1;
        }
	//swap first element and pivot index
        temp = array[start];
        array[start] = array[pivot_index];
        array[pivot_index] = temp;

        return pivot_index;
}

void quick_sort(int array[], int start, int end)
{

        int pivot_point;
        if (start < end)
        {
	    //partitioning index
            pivot_point = partition(array, start, end);
	    //sort elements before and after partition
            quick_sort(array, start, pivot_point-1);
            quick_sort(array, pivot_point+1, end);
        }
}

int main()
{	//create array
	int num;
        int array[1000];
        int count = 0;

	//read text file and put numbers into array
        while (cin >> num)
        {
             array[count] = num;
             count++;
        }

	//compute start and end
	//call quick_sort function
	int start = 0;
	int end = count-1;
	quick_sort(array, start, end);

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
