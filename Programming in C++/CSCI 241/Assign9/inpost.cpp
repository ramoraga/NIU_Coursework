//*******************************************************************
//
//  inpost.cpp
//  CSCI 241 Assignment 7
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#include "inpost.h"
#include "mystack.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;


/**
 * Used for calculating precdence of current character.
 *
 * Returns a number for the passed char to determine whether
 * it is less than or equal to the number that represents the top of
 * the stack.
 *
 * @param op  A char value that represents the current character.
 *
 * @returns an integer that represents the operator.
 ********************************************************************************/
int precedence(char op)
{
	if (op == '+' || op == '-') {
		return 1;
	} else if (op == '*' || op == '/') {
		return 2;
	} else if (op == '~' || op == '^') {
		return 3;
	} else {
		return 0;
	}
}	

/**
 * Converts infix to postfix
 *
 * Takes a string in infix format and converts it into postfix format.
 * It does this by going through each character and checking whether it's 
 * an operand or opertor and appending it to another string.
 *
 * @param infix a string that holds an infix expression.
 *
 * @returns a string that holds the postfix expression.
 ********************************************************************************/
string convert(const string& infix)
{
	string post;
	std::string::const_iterator iter = infix.begin();
	mystack opstack;
  
	while (iter != infix.end()) {
		if (islower(*iter)) {
			post += *iter;
			post += ' ';
			iter++;
		} else if (isdigit(*iter)) {
            while (isdigit(*iter)) {
				post += *iter;
				iter++;
            }
			post += ' ';
		} else if (isspace(*iter)) {
			iter++;
		} else if (*iter == '(') {
			opstack.push(*iter);
			iter++;
		} else if (*iter == ')') {
			while (!opstack.empty() && opstack.top() != '(') {
				post += opstack.top();
                post += ' ';
				opstack.pop();
            }
			if (!opstack.empty()) {
				opstack.pop();
			}
			iter++;
		} else {
			while (!opstack.empty() && precedence(*iter) <= precedence(opstack.top())) {
				post += opstack.top();
				post += ' ';
				opstack.pop();
			}
			opstack.push(*iter);
			iter++;
		}
	}
	
	while (!opstack.empty()) {
		post += opstack.top();
        post += ' ';
		opstack.pop();
	}

    post.pop_back();

	return post;
}	
