//*******************************************************************
//
//  assign12.cpp
//  CSCI 241 Assignment 12
//
//  Created by Reinaldo Moraga (z1864815)
//
//*******************************************************************

#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	// Declare vector of pointers to shape objects
	vector<shape*> shapes;

	cout << "Printing all shapes...\n" << endl;

	// Dynamically creating circles, rectangles, and triangles
	// and adding them to the vector.
	shapes.push_back(new circle("green", 10));
	shapes.push_back(new rectangle("red", 8, 6));
	shapes.push_back(new triangle("yellow", 8, 4));
	shapes.push_back(new triangle("black", 4, 10));
	shapes.push_back(new circle("orange", 5));
	shapes.push_back(new rectangle("blue", 3, 7));

	// Looping through the vector and printing each shape.
	for (size_t i = 0; i < shapes.size(); i++) {
		shapes[i]->print();
	}

	cout << "\nPrinting all circles...\n" << endl;

	// Looping through the vector and printing only circles
	for (size_t i = 0; i < shapes.size(); i++) {
		circle* p = dynamic_cast<circle*>(shapes[i]);
		if (p != nullptr) {
			p->print();
		}
	}
	
	// Looping through the vecotor and deleting each object.
	for (size_t i = 0; i < shapes.size(); i++) {
		delete shapes[i];
	}

	return 0;
}
