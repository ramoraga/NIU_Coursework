//*****************************************************************************
//
//  scc.cpp
//  CSCI 241 Assignment 9
//  Created by name (z-ID)
//
//*****************************************************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
#include "sml.h"
#include "inpost.h"

using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
using std::showpos;
using std::noshowpos;
using std::internal;
using std::istringstream;
using std::string;

/**
 * 
 * Symbol table entry.
 *
 ********************************************************************/
struct table_entry
{
    int symbol;
    char type;      // 'C' constant, 'L' Simple line number, 'V' variable
    int location;   // Simplesim address
};

/**
 * 
 * Simple compiler.
 *
 ********************************************************************/
class scc
{
public:
    
    static const int MEMORY_SIZE = 100;
    static const int SYMBOL_TABLE_SIZE = 1000;
    
    scc();
    void first_pass();
    void second_pass();
    void print_program() const;
    void memory_check() const;
    int search_symbol_table(int, char);

private:
    
    int memory[MEMORY_SIZE];
    int data[MEMORY_SIZE];
    int ndata = 0;
    
    table_entry symbol_table[SYMBOL_TABLE_SIZE];
    int flags[MEMORY_SIZE];
    
    int next_instruction_addr = 0;
    int next_const_or_var_addr = MEMORY_SIZE - 1;
    int next_symbol_table_idx = 0;
};

int main()
{
    scc compiler;

    compiler.first_pass();

    compiler.second_pass();

    compiler.print_program();

    return 0;
}

/**
 * Initializes memory and flags array.
 *
 ********************************************************************/
scc::scc()
{
    // Initialize memory and flags arrays.
    	for (int i = 0; i < MEMORY_SIZE; i++) {
	    memory[i] = 4444;
	    flags[i] = -1;
    	}

}

/**
 * Performs first pass of compilation.
 *
 ********************************************************************/
void scc::first_pass()
{
    string buffer1, buffer2, command;

    int line_number;
    
    while (getline(cin, buffer1))
    {
        buffer2 = buffer1;
        istringstream ss(buffer1);
        
        ss >> line_number;
        
        // Code to add line number to symbol table
        
	symbol_table[next_symbol_table_idx].symbol = line_number;
	symbol_table[next_symbol_table_idx].type = 'L';
	symbol_table[next_symbol_table_idx].location = next_instruction_addr;
	next_symbol_table_idx++;

        // Extract the command from this statement.
        ss >> command;
        
        // Process the command.
        if (command == "input")
        {
	    int name;
	    ss >> name;
            int index = search_symbol_table(line_number, 'V');

	    if (index == -1) {
		symbol_table[next_symbol_table_idx].symbol = name;
		symbol_table[next_symbol_table_idx].type = 'V';
		symbol_table[next_symbol_table_idx].location = next_const_or_var_addr;
		memory[next_const_or_var_addr] = 0;
		next_const_or_var_addr--;
		memory_check();
		memory[next_instruction_addr] = READ * 100 + symbol_table[next_symbol_table_idx].location;
		next_instruction_addr++;
	    } else {
		    int location;
		    location = symbol_table[index].location;
		    memory_check();
		    memory[next_instruction_addr] = READ * 100 + location;
		    next_instruction_addr++;
	    }
        }
        else if (command == "data")
        {
		string data;
		ss >> data;
		
		if (ndata >= MEMORY_SIZE) {
			cout << "*** ERROR: too many data lines ***\n";
			exit(1);
		}
		
		int num;
		size_t sz;

		num = stoi(data, &sz);
		data[ndata] = num;
		ndata++;

        }
        else if (command == "let")
        {
            
        }
        else if (command == "if")
        {
            
        }
        else if (command == "goto")
        {
            
        }
        else if (command == "print")
        {
            
        }
        else if (command == "end")
        {
		memory_check();
		memory[next_instruction_addr] = HALT * 100;
		next_instruction_addr++;
        }
       // else if (command == "rem")
       // {
            // Nothing to do for this instruction.
       // }
    }
}

/**
 * Performs second pass of compilation.
 *
 ********************************************************************/
void scc::second_pass()
{

	int stack_start = next_const_or_var_addr - 1;
	cout << stack_start << endl;

	for (int i = 0; i < next_instruction_addr; i++) {
		if (flags[i] != -1) {
			if (flags[i] > 0) {
				int result = search_symbol_table(flags[i], 'L');
				int address = symbol_table[result].location;
				memory_check();
				memory[next_instruction_addr] = memory[i] + address;
			} else {
				if (flags[i] == -2) {
				memory_check();
				memory[next_instruction_addr] = memory[i] + symbol_table[i].location;
				} else {
					if (flags[i] < -2) {
						int idx = -3 - flags[i];
						memory_check();
						memory[next_instruction_addr] = memory[i] + idx;
					}
				}
			}
		}
	}
}

/**
 * Prints memory and data for the compiled SML program.
 *
 ********************************************************************/
void scc::print_program() const
{
    // Print memory array followed by data array.
	
	cout << setfill('0') << internal << showpos;

	for (int i = 0; i < MEMORY_SIZE; i++) {
		cout << setw(5) << memory[i] << endl;
	}

	cout << -99999 << endl;
	cout << setfill(' ') << noshowpos;

	for (int i = 0; i < ndata; i++) {
		cout << data[i] << endl;
	}
}

void scc::memory_check() const
{
	if (next_instruction_addr >= MEMORY_SIZE) {
		cout << "*** ERROR: Ran out of Simplesim memory ***\n";
		exit(1);
	}
}

int scc::search_symbol_table(int symbol, char type)
{
	for (int i = 0; i < next_symbol_table_idx; i++) {
		if (symbol_table[i].symbol == symbol && symbol_table[i].type == type) {
			return i;
		}
	}

	return -1;
}
