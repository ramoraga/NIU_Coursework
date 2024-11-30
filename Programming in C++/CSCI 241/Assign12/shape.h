//*******************************************************************
//
//  shape.h
//  CSCI 241 Assignment 12
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#ifndef SHAPE_H
#define SHAPE_H
#include <string>

using std::string;

// An abstract base class.
class shape
{
	private:
		string color;

	public:
		shape(const string&);

		// Virtual member functions.
		virtual ~shape();
		virtual void print() const;

		// Pure virtual method.
		virtual double get_area() const = 0;
		
};

#endif /* SHAPE_H */
