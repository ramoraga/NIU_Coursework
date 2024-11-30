//*******************************************************************
//
//  shape.cpp
//  CSCI 241 Assignment 12
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#include "shape.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::string;
using std::cout;

/**
 * This is the constructor for the shape class.
 *
 * @param color a const string& that represents the color of the shape.
 *
 * @note returns nothing. 
 ********************************************************************************/
shape::shape(const string& color) 
{
	this->color = color;
}

/**
 * This is the destructor for the shape class.
 *
 * @note has no body. 
 ********************************************************************************/
shape::~shape()
{
}

/**
 * This is the print member function for the shape class.
 *
 * Prints the color of the shape.
 *
 * @note takes no arguments and returns nothing. 
 ********************************************************************************/
void shape::print() const
{
	cout << color << " ";
}
