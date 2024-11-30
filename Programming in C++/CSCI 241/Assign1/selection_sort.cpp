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

	int i = 0;
	while (i < count-1)
	{
            int min_index = i;
	    int j = i+1;
	    while (j < count)
	    {
		if (array[j] < array[min_index])
		{
		     min_index = j;
		}
		j = j+1;
	    }
	    int temp = array[i];
	    array[i] = array[min_index];
	    array[min_index] = temp;
	    i = i+1;
	}

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
