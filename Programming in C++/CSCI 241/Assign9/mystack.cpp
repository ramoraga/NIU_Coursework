//*******************************************************************
//
//  mystack.cpp
//  CSCI 241 Assignment 7
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#include "mystack.h"
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Default constructor for the mystack class.
 *
 * Initializes a new mystack object to an empty stack. Sets stack size to
 * 0, stack capacity to 0, and stack array pointer to nullptr.
 * 
 * @note takes no paramaters and returns nothing.
 ********************************************************************************/
mystack::mystack()
{
	ssize = 0;
	cap = 0;
	point = nullptr;
}

/**
 * Copy constructor for the mystack class.
 *
 * Initializes a new mystack object to the same string as the 
 * existing mystack object x. Sets stack size, stack capacity,
 * and stack array pointer to object x's stack size, capacity,
 * and array pointer.
 *
 * @param x an existing mystack object.
 * 
 * @note returns nothing.
 ********************************************************************************/
mystack::mystack(const mystack& x)
{
	cap = x.cap;
	ssize = x.ssize;

	if (cap > 0) {
		point = new char[cap];
		for (size_t i = 0; i < ssize; i++) {
			point[i] = x.point[i];
		}
	} else {
		point = nullptr;
	}
}

/**
 * Destructor for the mystack class.
 *
 * Deletes the stack array.
 * 
 * @note takes no parameters and returns nothing.
 ********************************************************************************/
mystack::~mystack()
{
	delete[] point;
}

/**
 * Overload copy assignment operator for the mystack class.
 *
 * Assigns one mystack object to another.
 *
 * @param x an existing mystack object.
 *
 * @return The new assigned mystack object. 
 ********************************************************************************/
mystack& mystack::operator=(const mystack& x)
{
	if (this != &x) {
		delete[] point;
		cap = x.cap;
		ssize = x.ssize;
		if (cap > 0) {
			point = new char[cap];
			for (size_t i = 0; i < ssize; i++) {
				point[i] = x.point[i];
			}
		} else {
			point = nullptr;
		}
	}

	return *this;
}

 /**
 * Member function that returns the stack capacity of the
 * object that was called.
 *
 * @return The stack capacity.
 *
 * @note takes no parameters.
 ********************************************************************************/
size_t mystack::capacity() const
{
	return cap;
}

/**
 * Member function that returns the stack size.
 * object that was called.
 *
 * @return The stack size.
 *
 * @note takes no parameters.
 ********************************************************************************/

size_t mystack::size() const
{
	return ssize;
}

/**
 * Member function that checks if the stack
 * is empty or not.
 *
 * @return bool variable that equals false if 
 * 	stack size is 0  and true if stack is not
 * 	empty.
 *
 * @note takes no parameters .
 ********************************************************************************/
bool mystack::empty() const
{
	bool valid = false;
	
	if (ssize == 0) {
		valid = true;
		return valid;
	}

	return valid;
}

/**
 * Member function that sets stack size back to 0.
 *
 * @note takes no parameters and returns nothing.
 ********************************************************************************/
void mystack::clear()
{
	ssize = 0;
}

/**
 * Member function that modifies stack capacity.
 *
 * Takes a mystack object's stack capacity and changes
 * it without changing the stack size or the contents of
 * the stack array.
 *
 * @param n a number that represents the new stack capacity.
 *
 * @note returns nothing.
 ********************************************************************************/
void mystack::reserve(size_t n)
{
	if (n < ssize || n == cap) {
		return;
	} else {
		char* temp;
		temp = new char[n];
		for (size_t i = 0; i < cap; i++) {
			temp[i] = point[i];
		}
		cap = n;
		delete[] point;
		point = temp;
	}
	
	return;
}

/**
 * Member function that returns the top item in the stack.
 *
 * @return Top item in stack.
 *
 * @note takes no parameters.
 ********************************************************************************/
const char& mystack::top() const
{
	return point[ssize-1];
}

/**
 * Member function that pushes a char value onto the top of
 * the stack.
 * 
 * Checks if stack size is equavlent to stack capacity and changes
 * the stack capacity accordingly. Then it pushes char value to the top
 * of the stack.
 *
 * @param value a char variable that is pushed to the top of the stack.
 *
 * @note returns nothing.
 ********************************************************************************/
void mystack::push(char value)
{
	if (ssize == cap) {
		if (cap == 0) {
			reserve(1);
		} else {
			reserve(cap * 2);
		}
	}
	point[ssize] = value;
	ssize = ssize + 1;

	return;
}

/**
 * Member function that pops the top item off the stack.
 *
 * Pops the top item off by decreasing the stack size by 1.
 *
 * @note takes no parameters and returns nothing.
 ********************************************************************************/
void mystack::pop()
{
	ssize = ssize - 1;
	return;
}
