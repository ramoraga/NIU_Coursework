//***********************************************
//
//	hanoi.cpp
//	CSCI 241 Assignment 2
//
//	Created by Reinaldo Moraga (z1864815)
//
//***********************************************

#include <iostream>
#include <iomanip>
using namespace std;

void move(int n_disks, int src_peg, int dest_peg, int temp_peg)
{
	if (n_disks == 1)
	{	//move disk 1 from peg 1 to peg 2.
	    cout << n_disks << " " <<  src_peg << "->" << dest_peg << endl;
	    return;
	}
	else
	{	//recursion;
		// Follows step 1-3
	    move(n_disks-1, src_peg, temp_peg, dest_peg);
	    cout << n_disks << " " << src_peg << "->" << dest_peg << endl;
	    move(n_disks-1, temp_peg, dest_peg, src_peg);
	}
}

int main(int argc, char* argv[])
{
	int n;	//number of disks
	int i;

	if (argc > 1)
	{
	    for (i = 0; argv[1][i] != '\0'; i++)
	    {
		if (!isdigit(argv[1][i]))
		{
		    cout << "Bad character in command line argument" << endl;
		    exit(1);
		}
	    }
	    n = atoi(argv[1]);
	}
	else
	{
	    cout << "Error: missing command line argument" << endl;
	    exit(1);
	}

	move(n, 1, 2, 3);
	return 0;
}
