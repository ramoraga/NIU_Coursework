#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int num;
        int array[1000];
        int count = 0;

        while (cin >> num)
        {
             array[count] = num;
             count++;
        }


	bool swapped;
	do
	{
            swapped = false;
	    int i = 1;
	    while (i < count)
	    {
		if (array[i-1] > array[i])
		{
		     int temp = array[i-1];
		     array[i-1] = array[i];
		     array[i] = temp;
		     swapped = true;
		}
		i = i+1;
	    }
	}
	while (swapped == true);


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
