//*******************************************************************
//
//  inpost.cpp
//  CSCI 241 Assignment 8
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
		return 3;
	} else {
		if (op == '*' || op == '/') {
			return 2;
		} else {
			if (op == '~' || op == '^') {
				return 1;
			} else {
				return 0;
			}
		}
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
	int i = 0;
	while (iter != infix.end()) {
		if (islower(*iter)) {
			std::string con(1, *iter);
			post.append(con);
			i++;
			iter++;
			if (iter != infix.end()) {
				post += ' ';
				i++;
			}
		} else {
			if (isdigit(*iter)) {
				std::string con(1, *iter);
				post.append(con);
				i++;
				iter++;
				if (!isdigit(*iter) && iter != infix.end()) {
					post += ' ';
					i++;
				}
			} else {
				if (isspace(*iter)) {
					iter++;
				} else {
					if (*iter == '(') {
						opstack.push(*iter);
						iter++;
					} else {
						if (*iter == ')') {
							while (opstack.empty() == 0 && opstack.top() != '(') {
								const char& top = opstack.top();
								std::string con(1, top);
								post.append(con);
								i++;
								post += ' ';
								i++;
								opstack.pop();
							}
							if (opstack.empty() == 0) {
								opstack.pop();
							}
							iter++;
						} else {
							while (opstack.empty() == 0 && precedence(*iter) <= precedence(opstack.top())) {
								const char& top = opstack.top();
								std::string con(1, top);
								post.append(con);
								i++;
								post += ' ';
								i++;
								opstack.pop();
							}
							opstack.push(*iter);
							iter++;
						}
					}
				}
			}
		}
	}
	while (opstack.empty() == 0) {
		const char& top = opstack.top();
		std::string con(1, top);
		post += ' ';
		i++;
		post.append(con);
		i++;
		opstack.pop();
	}

	for (int j = 2; j <= i; j++) {
		if (post[j-2] == ' ' && post[j-1] == ' ') {
			post.erase(j-1, 1);
		}
	}
	return post;
}	
