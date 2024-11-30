# PROGRAM:    assign5
# PROGRAMMER: Reinaldo
# LOGON ID:   z1864815
# DATE DUE:   3/27/2020
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Rule to link object code files to create executable file
assign5: assign5.o
	$(CXX) $(CXXFLAGS) -o assign5 $^

# Rules to compile source code files to object code
assign5.o: assign5.cc

# Phony target to remove object code and executable files
clean:
	rm -f assign5 *.o
