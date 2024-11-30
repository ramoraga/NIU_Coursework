//*******************************************************************
//
//  mystack.cpp
//  CSCI 241 Assignment 8
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
 * 0, and stack node pointer to nullptr.
 * 
 * @note takes no paramaters and returns nothing.
 ********************************************************************************/
mystack::mystack()
{
	stk_size = 0;
	stk_topPoint = nullptr;
}

/**
 * Copy constructor for the mystack class.
 *
 * Initializes a new mystack object to the same string as the 
 * existing mystack object x. Sets stack size,and stack node 
 * pointer to object x's stack size,and node pointer.
 *
 * @param x an existing mystack object.
 * 
 * @note returns nothing.
 ********************************************************************************/
mystack::mystack(const mystack& x)
{
	stk_size = x.stk_size;

	if (stk_size == 0) {
		stk_topPoint = nullptr;
	} else {
		clone(x);
	}
}

/**
 * Destructor for the mystack class.
 *
 * Deletes the mystack object by calling clear().
 * 
 * @note takes no parameters and returns nothing.
 ********************************************************************************/
mystack::~mystack()
{
	clear();
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
		clear();
		stk_size = x.stk_size;
		clone(x);
	}

	return *this;
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
	return stk_size;
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

	if (stk_size == 0) {
		valid = true;
		return valid;
	}
	
	return valid;
}

/**
 * Member function that clears a stack by calling pop()
 * until it's empty
 *
 * @note takes no parameters and returns nothing.
 ********************************************************************************/
void mystack::clear()
{
	while (empty() == false) {
		pop();
	}
}

/**
 * Member function that returns the top item in the stack.
 *
 * @return Top item in stack.
 *
 * @note takes no parameters.
 ********************************************************************************/
const int& mystack::top() const
{
	return stk_topPoint->value;
}

/**
 * Member function that pushes an int value onto the top of
 * the stack.
 * 
 * Creates new node that represents value and pushes to the top
 * of the stack.
 *
 * @param value an int variable that is pushed to the top of the stack.
 *
 * @note returns nothing.
 ********************************************************************************/
void mystack::push(int value)
{
	node *new_node = new node(value, stk_topPoint);

	stk_topPoint = new_node;

	stk_size = stk_size + 1;
}

/**
 * Member function that pops the top item off the stack.
 *
 * Creates a temporary node that stores the top item in the stack. Then
 * it moves the top item pointer to the next item and deletes the temporary
 * node and adjusts the size accordingly.
 *
 * @note takes no parameters and returns nothing.
 ********************************************************************************/
void mystack::pop()
{
	node *delete_node;
	delete_node = stk_topPoint;
	stk_topPoint = stk_topPoint->next;

	delete delete_node;

	stk_size = stk_size - 1;
}

/**
 * Member function that clones a mystack object.
 *
 * Called by an assignment member function, the clone function
 * takes a mystack object and duplicates it through a while loop.
 *
 * @param an existing mystack object X.
 *
 * @note takes returns nothing.
 ********************************************************************************/
void mystack::clone(const mystack& x)
{
	node *last = nullptr;
	node *ptr = x.stk_topPoint;

	while (ptr != nullptr) {
		node *new_node = new node(ptr->value);

		if (last == nullptr) {
			stk_topPoint = new_node;
		} else {
			last->next = new_node;
		}

		last = new_node;
		ptr = ptr->next;
	}
}
