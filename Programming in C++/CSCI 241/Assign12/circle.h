//*******************************************************************
//
//  circle.h
//  CSCI 241 Assignment 12
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <string>

using std::string;

// Derived from shape class using public inheritance.
class circle : public shape
{
	private:
		int radius = 0;

	public:
		circle(const string&, int);
		virtual void print() const;
		virtual double get_area() const;
		
};

#endif /* CIRCLE_H */
