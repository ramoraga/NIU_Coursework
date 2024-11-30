///*******************************************************************
//
//  matrix.h
//  CSCI 241 Assignment 6
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>

class matrix
{	
	// declare friend functions
	friend std::ostream& operator << (std::ostream&, const matrix&);	// friend function that prints matrix object
										// when stream insertion operator << is called

	friend matrix operator*(int, const matrix&);				// friend function that calculates product of between
										// an integer and a matrix object when operator * is called

	private:
		int Matrix[2][2];				// declare 2x2 matrix array

	public:
		matrix();					// default constructor that sets matrix array
								// to [[1,0],[0,1]]

		matrix(int[][2]);				// constructor that takes 2x2 int array and copies
								// array elements into matrix array

		int determinant() const;			// member function that calculates determinant of matrix array

		matrix operator+(const matrix&) const;		// member function that calculates sum of two matrix objects when
								// operator + is called

		matrix operator*(int) const;			// member function that calculates product of a matrix object and
								// an integer when operator * is called

		matrix operator*(const matrix&) const;		// member function that calculates product of two matrix objects when
								// operator * is called

		bool operator==(const matrix&) const;		// member function that checks if two matrix objects are equivalent when
								// operator == is called

		bool operator!=(const matrix&) const;		// member function that checks if two matrix objects are not equal to each
								// other when operator != is called
};

#endif /* MATRIX_H */
