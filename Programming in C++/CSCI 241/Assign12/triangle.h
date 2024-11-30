//*******************************************************************
//
//  triangle.h
//  CSCI 241 Assignment 12
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <string>

using std::string;

// Derived from shape class using public inheritance.
class triangle : public shape
{
	private:
		int height = 0;
		int base = 0;

	public:
		triangle(const string&, int, int);
		virtual void print() const;
		virtual double get_area() const;
		
};

#endif /* TRIANGLE_H */
