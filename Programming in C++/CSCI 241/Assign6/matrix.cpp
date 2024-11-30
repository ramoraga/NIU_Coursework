//*******************************************************************
//
//  matrix.cpp
//  CSCI 241 Assignment 6
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#include "matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

matrix::matrix()
{
	// using a for loop, the matrix is set to
	// [[1, 0 ], [0, 1]]
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			if (row == 0 && col == 0) {
				Matrix[row][col] = 1;
			} else {
				if (row == 1 && col == 1) {
					Matrix[row][col] = 1;
				} else {
					Matrix[row][col] = 0;
				}
			}
		}
	}
}

std::ostream& operator<<(std::ostream& lhs, const matrix& rhs)
{
	// prints [[num, num], [num, num]]
	lhs << "[[" << rhs.Matrix[0][0] <<  ", " << rhs.Matrix[0][1] << "], [" << rhs.Matrix[1][0] << ", " << rhs.Matrix[1][1] << "]]";

	return lhs;
}

matrix::matrix(int array[][2])
{
	// for loop that sets matrix array to equal passed array
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			Matrix[row][col] = array[row][col];
		}
	}
}

int matrix::determinant() const
{
	// declare variables that will hold calculated values
	int deter;
	int op1;
	int op2;
	
	// calculate first step for determinant equation
	op1 = (Matrix[0][0]) * (Matrix[1][1]);
	op2 = (Matrix[0][1]) * (Matrix[1][0]);

	// calculate second step and result is determinant
	deter = op1 - op2;

	return deter;
}

matrix matrix::operator+(const matrix& rhs) const
{	
	// create result object
	matrix lhs = *this;
	matrix result;

	// for loop that takes the sum of left and right operand elements
	// into result object
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			result.Matrix[row][col] = lhs.Matrix[row][col] + rhs.Matrix[row][col];
		}
	}

	return result;
}

matrix matrix::operator*(int rhs) const
{
	matrix lhs = *this;
	matrix result;
	
	// for loop that takes product of matrix object elements and int into
	// result object
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			result.Matrix[row][col] = lhs.Matrix[row][col] * rhs;
		}
	}

	return result;
}

matrix operator*(int lhs, const matrix& rhs)
{
	matrix result;

	// for loop that takes product of an int and matrix object elements
	// into result object
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			result.Matrix[row][col] = lhs * rhs.Matrix[row][col];
		}
	}
	
	return result;
}

matrix matrix::operator*(const matrix& rhs) const
{
	matrix lhs = *this;
	matrix result;

	// for loop that takes product between two matrix object elements
	// into result object
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			if (row == 0) {
				// when in row 0, corresponding product is calculated and copied
				// into result object
				result.Matrix[row][col] = (lhs.Matrix[row][0] * rhs.Matrix[row][col]) + (lhs.Matrix[row][1] * rhs.Matrix[row+1][col]);
			} else {
				// when in row 1, corresponding product is calculated and copied
				// int result object
				result.Matrix[row][col] = (lhs.Matrix[row][0] * rhs.Matrix[0][col]) + (lhs.Matrix[row][1] * rhs.Matrix[row][col]);	
			}
		}
	}

	return result;
}
					
bool matrix::operator==(const matrix& rhs) const
{
	matrix lhs = *this;
	bool valid = true;

	// for loop that compares elements of two matrix objects
	// to see if they're equivalent
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			if (lhs.Matrix[row][col] != rhs.Matrix[row][col]) {
				// if elements are not equivalent, then return false
				valid = false;
				return valid;
			}
		}
	}

	return valid;
}

bool matrix::operator!=(const matrix& rhs) const
{
	matrix lhs = *this;
	bool valid = true;

	// for loop that compares elements of two matrix objects
	// to see if they're not equivalent
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			if (lhs.Matrix[row][col] == rhs.Matrix[row][col]) {
				// if elements are equivalent, then return false
				valid = false;
				return valid;
			}
		}
	}

	return valid;
}
