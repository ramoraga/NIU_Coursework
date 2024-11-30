//*******************************************************************
//
//  rectangle.cpp
//  CSCI 241 Assignment 12
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#include "rectangle.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::string;
using std::cout;
using std::endl;

/**
 * This is the constructor for the rectaqngle class.
 *
 * @param color A const string& that is passed to the shape constructor.
 * @param height An int that represents the height of a rectangle.
 * @param width An int that represents the width of a rectangle.
 *
 * @note returns nothing. 
 ********************************************************************************/
rectangle::rectangle(const string& color, int height, int width) : shape(color)
{
	this->height = height;
	this->width = width;
}

/**
 * This is the print member function for the rectangle class.
 *
 * Prints color, shape, height, width, and area.
 *
 * @note takes no arguments and returns nothing. 
 ********************************************************************************/
void rectangle::print() const
{
	shape::print();
	cout << "rectangle, height " << height << ", width " << width << ", area " <<  get_area() << endl;
}

/**
 * This is member functions returns the area of a rectangle.
 *
 * @return the area of a rectangle.
 *
 * @note takes no arguments. 
 ********************************************************************************/
double rectangle::get_area() const
{
	return (height * width);
}
