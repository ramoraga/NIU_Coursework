#
# PROGRAM:    Assignment 8
# PROGRAMMER: Reinaldo Moraga
# LOGON ID:   z1864815
# DATE DUE:   3/24/2020
#
    
# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11 -g
        
# Rule to link object code files to create executable file
inpost: inposteval_main.o inpost.o eval.o mystack.o
	$(CXX) $(CXXFLAGS) -o inpost $^

# Rules to compile source code file to object code
inposteval_main.o: inposteval_main.cpp inpost.h
inpost.o: inpost.cpp inpost.h mystack.h
eval.o: eval.cpp eval.h mystack.h
mystack.o: mystack.cpp mystack.h
   
# Pseudo-target to remove object code and executable files
clean:
	rm -f inpost *.o
