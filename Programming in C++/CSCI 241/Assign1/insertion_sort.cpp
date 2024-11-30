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

	int i = 1;
	while (i < count)
	{
	    int j = i;
	    while (j > 0 && array[j-1] > array[j])
	    {
	    	int temp = array[j-1];
	    	array[j-1] = array[j];
	    	array[j] = temp;
	    	j = j-1;
	    }
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
