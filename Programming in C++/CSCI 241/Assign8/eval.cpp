//*******************************************************************
//
//  eval.cpp
//  CSCI 241 Assignment 8
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#include "eval.h"
#include "mystack.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>

using std::string;
using std::stringstream;

/**
 * Calculates postfix expression to determine final value.
 *
 * Works by going through each character and determining if it's a
 * digit, lowercase letter, or operator.
 *
 * @param postfix a string that holds an postfix expression.
 *
 * @returns an integer value that holds the calculated value of
 * 	the postfix expression.
 ********************************************************************************/
int evaluate(const string& postfix)
{
	string op;
	stringstream ss(postfix);
	mystack tokstack;

	while (ss >> op) {
		char tok0 = op.at(0);

		if (isdigit(tok0)) {
			tokstack.push(std::stoi(op));
		} else {
			if (islower(tok0)) {
				tokstack.push(tok0 - 'a');
			} else {
				if (tok0 == '~') {
					int i = tokstack.top();
					tokstack.pop();
					tokstack.push(-i);
				} else {	
					int left, right;

					switch (tok0) {
						case '+':
							right = tokstack.top();
							tokstack.pop();
							left = tokstack.top();
							tokstack.pop();

							tokstack.push(left + right);
							break;
						case '-':
							right = tokstack.top();
							tokstack.pop();
							left = tokstack.top();
							tokstack.pop();

							tokstack.push(left - right);
							break;
						case '*':
							if (tokstack.size() == 1) {
								ss >> op;
							} else {
								right = tokstack.top();
								tokstack.pop();
								left = tokstack.top();
								tokstack.pop();

								tokstack.push(left * right);
							}
							break;
						case '/':
							right = tokstack.top();
							tokstack.pop();
							left = tokstack.top();
							tokstack.pop();

							if (right == 0) {
								std::cerr << "*** Division by 0 ***" << std::endl;
								return 0;
							} else {
								tokstack.push(left / right);
							}
							break;
						case '^':
							if (tokstack.size() == 1) {
								ss >> op;
								if (isdigit(op.at(0))) {
									tokstack.push(std::stoi(op));
								}
								if (islower(op.at(0))) {
									tokstack.push(op.at(0) - 'a');
								}
								right = tokstack.top();
								tokstack.pop();
								left = tokstack.top();
								tokstack.pop();
								tokstack.push(left ^ right);
							} else {
								right = tokstack.top();
								tokstack.pop();
								left = tokstack.top();
								tokstack.pop();

								tokstack.push(left ^ right);
							}
							break;
						default:
							std::cerr << "ERROR: Invalid operator " << op.at(0) << std::endl;
					}
				}
			}
		}
	}

	int value = tokstack.top();
	tokstack.clear();

	return value;
}

