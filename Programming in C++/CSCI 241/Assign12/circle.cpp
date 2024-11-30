//*******************************************************************
//
//  circle.cpp
//  CSCI 241 Assignment 12
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#include "circle.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using std::string;
using std::cout;
using std::endl;

/**
 * This is the constructor for the circle class.
 *
 * @param color A const string& that is passed to the shape constructor.
 * @param radius The radius of the circle.
 *
 * @note returns nothing. 
 ********************************************************************************/
circle::circle(const string& color, int radius) : shape(color)
{
	this->radius = radius;
}

/**
 * This is the print member function for the circle class.
 *
 * Prints color, shape, radius, and area.
 *
 * @note takes no arguments and returns nothing. 
 ********************************************************************************/
void circle::print() const
{
	shape::print();
	cout << "circle, radius " << radius << ", area " << get_area() << endl;
}

/**
 * This is member function returns the area of a circle.
 *
 * @returns a double that represents the area of a circle.
 *
 * @note takes no arguments. 
 ********************************************************************************/
double circle::get_area() const
{
	return (M_PI * (radius * radius));
}
