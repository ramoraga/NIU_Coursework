#
# PROGRAM:    Assignment 12
# PROGRAMMER: Reinaldo Moraga
# LOGON ID:   z1864815
# DATE DUE:   4/29/2020
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Rule to link object code files to create executable file

assign12: assign12.o shape.o circle.o rectangle.o triangle.o
	$(CXX) $(CXXFLAGS) -o assign12 $^

# Rules to compile source code files to object code
assign12.o: assign12.cpp shape.h circle.h rectangle.h triangle.h
shape.o: shape.h shape.cpp
circle.o: circle.h circle.cpp
rectangle.o: rectangle.h rectangle.cpp
triangle.o: triangle.h triangle.cpp

circle.h: shape.h
rectangle.h: shape.h
triangle.h: shape.h

# Pseudo-target to remove object code and executable files
clean:
	rm -f assign12 *.o
