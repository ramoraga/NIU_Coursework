//*******************************************************************
//
//  rectangle.h
//  CSCI 241 Assignment 12
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <string>

using std::string;

// Derived from shape class using public inheritance.
class rectangle : public shape
{
	private:
		int height = 0;
		int width = 0;

	public:
		rectangle(const string&, int, int);
		virtual void print() const;
		virtual double get_area() const;
		
};

#endif /* RECTANGLE_H */
