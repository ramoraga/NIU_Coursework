#include "sml.h"
#include "simplesim.h"
#include <iostream>
#include <iomanip>

using namespace std;

simplesim::simplesim()
{
	accumulator = 0;
	instruction_counter = 0;
	instruction_register = 0;
	operation_code = 0;
	operand = 0;

	for (int i = 0; i < 100; i++) {
		memory[i] = 4444;
	}
}

bool simplesim::load_program()
{
	int n = 0;
	int num;
	int test[100];
	int cap = 100;
	bool success = true;

	while (cin >> num && num != -99999) {
		test[n] = num;
		n++;
	}
		
	if (n > cap) {
		cout << "*** ABEND: pgm load: pgm too large ***" << endl;
		success = false;
		return success;
	} else {
		for (int j = 0; j < n; j++) {
			if (test[j] >= 9999 || -9999 >= test[j]) {
				cout << "*** ABEND: pgm load: invalid word ***" << endl;
				success = false;
				return success;
			} else {
				memory[j] = test[j];
			}
		}
	}
	return success;
}

void simplesim::execute_program()
{
	bool done = false;
	
	while (!done) {
		if (instruction_counter < 100 && -1 < instruction_counter) {
			instruction_register = memory[instruction_counter];
			operation_code = instruction_register/100;
			operand = instruction_register % 100;
		} else {
			cout << "*** ABEND: addressability error ***" << endl;
			return;
		}

		switch (operation_code) {
			case READ:
				int word;
				cin >> word;

				if (-9999 >= word || word >= 9999) {
					cout << "*** ABEND: illegal input ***" << endl;
					return;
					} else {
						memory[operand] = word;
					}
				cout << "READ: " << showpos << setfill('0') << internal << setw(5) << memory[operand] << endl;
				return;
				break;

			case WRITE:
				cout << showpos << setfill('0') << internal << setw(5) << memory[operand] << endl;
				break;

			case LOAD:
				accumulator = memory[operand];
				cout << "Peh" << endl;
				return;
				break;

			case HALT:
				cout << "*** Simplesim execution terminated ***" << endl;
				break;

			default:
				cout << "*** ABEND: invalid opcode ***" << endl;
				return;
				break;
		
		}
	}

}

void simplesim::dump() const
{
	cout << "REGISTERS:\t" << endl << "accumulator:\t\t" << showpos << setfill('0') << internal << setw(5) << accumulator << endl;
	cout << "instruction_counter:\t" << noshowpos << setw(2) << instruction_counter << endl;
	cout << "instruction_register:\t" << showpos << internal << setw(5) << instruction_register << endl;
	cout << "operation_code:\t\t" << noshowpos << setw(2) << operation_code << endl;
	cout << "operand:\t\t" << setw(2) << operand << endl << endl;
	cout << "MEMORY:" << endl << setw(8);
	
	cout << setfill(' ');

	for (int i = 0; i < 10; i++) {
		cout << i << setw(6);
	}
	int y = 0;
	for (int j = 0; j < 100; j = j+10) {
		cout << endl << noshowpos << setw(2) << j << " " << setfill('0') << internal << setw(5);
	       	for (int k = 0; k < 10; k++) {
				cout << showpos << memory[y] << " " << setfill('0') << internal << setw(5);
				y++;

		}
	}
	cout << endl;
	return;
}
