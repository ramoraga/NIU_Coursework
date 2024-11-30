//************************************************
//
//	queens.cpp
//	CSCI 241 Assignement 2
//
//	Created by Reinaldo Moraga (z1864815)
//
//************************************************

#include <iostream>
#include <iomanip>
using namespace std;

bool safe(int board[][8], int row, int col)
{
	int i, j;

	//checks if queen is in the left
	for (i=0; i < col; i++)
	{
	    if (board[row][i])
	    {
		return false;
	    }
	}

	//checks if queen is in upper left diagonal
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
	    if (board[i][j])
	    {
		return false;
	    }
	}

	//checks if queen is in lower left diagonal
	for (i = row, j = col; j >= 0 && i < 8; i++, j--)
	{
	    if (board[i][j])
	    {
		return false;
	    }
	}

	return true;

}

bool place_queen(int board[][8], int col)
{

	//when 8 queens are placed successfully;
	//base case
	if (col == 8)
	{
	    return true;
	}
	else
	{	//starting to place queen in column
	    for (int i = 0; i < 8; i++)
	    {	//check if queen can be placed
		if (safe(board, i, col))
		{	//place queen on board
		    board[i][col] = 1;
		    if (place_queen(board, col+1))	//recursion
		    {
			return true;
		    }	//remove queen if spot unavailable
		    board[i][col] = 0;
		}
	    }
	    return false;
	}
}

int main()
{
	//chess board initialized
	int board[8][8] = {0};

	if (place_queen(board, 0) == false)
	{
	    cout << "No solution" << endl;
	}

	place_queen(board, 0);

	//print chess board
	for (int i = 0; i < 8; i++)
	{
	    for (int j = 0; j < 8; j++)
	    {
		cout << board[i][j] << ' ';
	    }
	    cout << endl;
	}

	return 0;
}
