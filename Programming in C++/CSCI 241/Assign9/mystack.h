//*******************************************************************
//
//  mystack.h
//  CSCI 241 Assignment 7
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#ifndef MYSTACK_H
#define MYSTACK_H
#include <cstddef>
#include <cstdlib>

class mystack
{		
	private:
		char* point;				// pointer to char that represents the stack array pointer
		size_t cap;				// variable that holds the capacity of elements that can be stored in stack array
		size_t ssize;				// variable that holds  the number of values currently stored in stack array
	public:
		mystack();	
		mystack(const mystack&);
		~mystack();
		mystack& operator=(const mystack&);
		size_t capacity() const;
		size_t size() const;
		bool empty() const;
		void clear();
		void reserve(size_t);
		const char& top() const;
		void push(char);
		void pop();
};

#endif /* MYSTACK_H */
