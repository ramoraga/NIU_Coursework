//*******************************************************************
//
//  triangle.cpp
//  CSCI 241 Assignment 12
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#include "triangle.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::string;
using std::cout;
using std::endl;

/**
 * This is the constructo for the triangle class.
 *
 * @param color A const string& that is passed to the shape constructor.
 * @param height An int that represents the height of a triangle.
 * @param base An int that represents the base of a triangle.
 *
 * @note returns nothing. 
 ********************************************************************************/
triangle::triangle(const string& color, int height, int base) : shape(color)
{
	this->height = height;
	this->base = base;
}

/**
 * This is the print member function for the triangle class.
 *
 * Prints color, shape, height, base, and area.
 *
 * @note takes no arguments and returns nothing. 
 ********************************************************************************/
void triangle::print() const
{
	shape::print();
	cout << "triangle, height " << height << ", base " << base << ", area " <<  get_area() << endl;
}

/**
 * This member function returns the area of a triangle.
 *
 * @return the area of a triangle.
 *
 * @note takes no arguments. 
 ********************************************************************************/
double triangle::get_area() const
{
	return (0.5 * (height * base));
}
