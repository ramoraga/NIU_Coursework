//*******************************************************************
//
//  mystack.h
//  CSCI 241 Assignment 8
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
	public:		
		struct node					// declare node data type
		{
			node* next;
			int value;

			node(int value, node* next = nullptr)
			{
				this->value = value;
				this->next = next;
			}
		};
	private:
		node* stk_topPoint;				// declare node pointer
		size_t stk_size;				// declare stack size variable
	public:
		mystack();	
		mystack(const mystack&);
		~mystack();
		mystack& operator=(const mystack&);
		size_t size() const;
		bool empty() const;
		void clear();
		const int& top() const;
		void push(int);
		void pop();
		void clone(const mystack&);
};

#endif /* MYSTACK_H */
