//*******************************************************************
// 
//  mylist.h
//  CSCI 241 Assignment 10
//
//  Created by Reinaldo Moraga and z1864815
//
//*******************************************************************

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <stdexcept>

// Forward declaration of the mylist template class
template <class T>
class mylist;

// Forward declaration of the mylist template class
template <class T>
std::ostream& operator<<(std::ostream&, const mylist<T>&);

template <class T>
struct node
{
	T value;
	node<T>* prev;
	node<T>* next;

	node(const T& value = T(), node<T>* prev = nullptr, node<T>* next = nullptr)
	{
		this->value = value;
		this->prev = prev;
		this->next = next;
	}
};

template <class T>
class mylist
{
	friend std::ostream& operator<< <>(std::ostream&, const mylist<T>&);

	private:
		node<T>* l_front;
		node<T>* l_back;
		size_t l_size;
	
	public:
		mylist();
		~mylist();
		mylist(const mylist<T>&);
		mylist<T>& operator=(const mylist<T>&);
		void clear();
		size_t size() const;
		bool empty() const;
		const T& front() const;
		T& front();
		const T& back() const;
		T& back();
		void push_front(const T&);
		void push_back(const T&);
		void pop_front();
		void pop_back();
		bool operator==(const mylist<T>& rhs) const;
		bool operator<(const mylist<T>& rhs) const;
		void clone(const mylist<T>&);
};

/**
 * This is the default constructor for the mylist class.
 *
 * Sets l_front and l_back to nullptr and l_size to 0.
 *
 * @note takes no arguments and returns nothing.
 ********************************************************************************/
template <class T>
mylist<T>::mylist()
{
	l_front = nullptr;
	l_back = nullptr;
	l_size = 0;
}

/**
 * This is the destructor for the mylist class.
 *
 * Calls the clear() function.
 *
 * @note takes no arguments and returns nothing. 
 ********************************************************************************/
template <class T>
mylist<T>::~mylist()
{
	clear();
}

/**
 * This is the copy constructor for the mylist class.
 *
 * @param x The existing mylist object that is passed to be copied.
 *
 * @note Returns nothing.
 ********************************************************************************/
template <class T>
mylist<T>::mylist(const mylist<T>& x)
{
	l_front = l_back = nullptr;
	l_size = 0;

	clone(x);
}

/**
 * This is the copy assignment operator for the mylist class.
 *
 * The rest of the lines are a more detailed description of the
 * function that outlines what it does and anything interesting about
 * how it does it.
 *
 * @param x The existing mylist object that is passed to be assigned.
 *
 *
 * @note T
 ********************************************************************************/
template <class T>
mylist<T>& mylist<T>::operator=(const mylist<T>& x)
{
	if (this != &x) {
		clear();
		clone(x);
	}

	return *this;
}

template <class T>
void mylist<T>::clear()
{
	while (empty() == false) {
		pop_front();
	}
}

template <class T>
size_t mylist<T>::size() const
{
	return l_size;
}

template <class T>
bool mylist<T>::empty() const
{
	if (l_size == 0) {
		return true;
	} else {
		return false;
	}
}

template <class T>
const T& mylist<T>::front() const
{
	if (empty()) {
		throw std::underflow_error("underflow exception on call to front()");
	}
	return l_front->value;
}

template <class T>
T& mylist<T>::front()
{
	if (empty()) {
		throw std::underflow_error("underflow exception on call to front()");
	}
	return l_front->value;
}

template <class T>
const T& mylist<T>::back() const
{
	if (empty()) {
		throw std::underflow_error("underflow exception on call to back()");
	}
	return l_back->value;
}

template <class T>
T& mylist<T>::back()
{
	if (empty()) {
		throw std::underflow_error("underflow exception on call to back()");
	}
	return l_back->value;
}

template <class T>
void mylist<T>::push_front(const T& value)
{
	node<T>* new_node = new node<T>(value);
	new_node->next = l_front;
	if (empty()) {
		l_back = new_node;
	} else {
		l_front->prev = new_node;
	}
	l_front = new_node;
	l_size = l_size + 1;
}

template <class T>
void mylist<T>::push_back(const T& value)
{
	node<T>* new_node = new node<T>(value);
	new_node->prev = l_back;
	if (empty()) {
		l_front = new_node;
	} else {
		l_back->next = new_node;
	}
	l_back = new_node;
	l_size = l_size + 1;
}

template <class T>
void mylist<T>::pop_front()
{
	if (empty()) {
		throw std::underflow_error("underflow exception on call to pop_front()");
	}

	node<T>* del_node = l_front;
	l_front = del_node->next;
	if (l_front == nullptr) {
		l_back = nullptr;
	} else {
		l_front->prev = nullptr;
	}
	delete del_node;
	l_size = l_size - 1;
}

template <class T>
void mylist<T>::pop_back()
{
	if (empty()) {
		throw std::underflow_error("underflow exception on call to pop_front()");
	}

	node<T>* del_node = l_back;
	l_back = del_node->prev;
	if (l_back == nullptr) {
		l_front = nullptr;
	} else {
		l_back->next = nullptr;
	}
	delete del_node;
	l_size = l_size - 1;
}

template <class T>
bool mylist<T>::operator==(const mylist<T>& rhs) const
{
	node<T>* ptr1;
	node<T>* ptr2;

	if (l_size != rhs.l_size) {
		return false;
	}

	for (ptr1 = l_front, ptr2 = rhs.l_front; ptr1 != nullptr && ptr2 != nullptr; ptr1 = ptr1->next, ptr2 = ptr2->next) {
		if (ptr1->value != ptr2->value) {
			return false;
		}
	}

	return true;
}

template <class T>
bool mylist<T>::operator<(const mylist<T>& rhs) const
{
	node<T>* ptr1;
	node<T>* ptr2;
	
	for (ptr1 = l_front, ptr2 = rhs.l_front; ptr1 != nullptr && ptr2 != nullptr; ptr1 = ptr1->next, ptr2 = ptr2->next) {
		if (ptr1->value < ptr2->value) {
			return true;
		} else {
			if (ptr1->value > ptr2->value) {
				return false;
			}
		}
	}

	if (ptr1 == nullptr && ptr2 != nullptr) {
		return true;
	} else {
		if (ptr1 == nullptr && ptr2 == nullptr) {
			return false;
		} else {
			if (ptr1 != nullptr && ptr2 == nullptr) {
				return false;
			}
		}
	}
	return true;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const mylist<T>& obj)
{	
	node<T>* ptr;

	for (ptr = obj.l_front; ptr != nullptr; ptr = ptr->next) {
		os << ptr->value << " ";
	}

	return os;
}

template <class T>
void mylist<T>::clone(const mylist<T>& x)
{
	node<T>* ptr = x.l_front;

	while (ptr != nullptr) {
		push_back(ptr->value);
		ptr = ptr->next;
	}
}

#endif /* MYLIST_H */
