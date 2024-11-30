# PROGRAM:    dog
# PROGRAMMER: Reinaldo
# LOGON ID:   z1864815
# DATE DUE:   2/21/2020
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Rule to link object code files to create executable file
dog: main.o func.o
	$(CXX) $(CXXFLAGS) -o dog $^

# Rules to compile source code files to object code
main.o: dog.cpp func.h
func.o: func.cpp func.h

# Phony target to remove object code and executable files
clean:
	rm -f dog *.o
