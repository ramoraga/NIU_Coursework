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
			if (test[j] > 9999 || -9999 > test[j]) {
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
	int cap = 100;
	
	while (!done) {
		if (instruction_counter > cap) {
			cout << "*** ABEND: addressability error ***" << endl << endl;
			return;
		} else {
			instruction_register = memory[instruction_counter];
			operation_code = (instruction_register) / 100;
			operand = (instruction_register) % 100;
		}
		switch (operation_code) {
			case READ:
				int word;
				cin >> word;

				if (-9999 > word || word > 9999) {
					cout << "*** ABEND: illegal input ***" << endl << endl;
					return;
					} else {
						memory[operand] = word;
					}
				cout << "READ: " << showpos << setfill('0') << internal << setw(5) << memory[operand] << endl;
				break;

			case WRITE:
				cout << showpos << setfill('0') << internal << setw(5) << memory[operand] << endl;	
				break;

			case STORE:
				memory[operand] = accumulator;
				break;

			case LOAD:
				accumulator = memory[operand];
				break;
	
			case ADD:
				int add;
				add = accumulator + memory[operand];
				if (-9999 > add) {
					cout << "*** ABEND: underflow ***" << endl << endl;
					return;
				} else {
					if (9999 < add) {
						cout << "*** ABEND: overflow ***" << endl << endl;
						return;
					} else {
						accumulator = add;
					}
				}
				break;

			case SUBTRACT:
				int sub;
				sub = (accumulator) - memory[operand];
				if (-9999 > sub) {
					cout << "*** ABEND: underflow ***" << endl << endl;
					return;
				} else {
					if (9999 < sub) {
						cout << "*** ABEND: overflow ***" << endl << endl;
						return;
					} else {
						accumulator = sub;
					}
				}
				break;

			case MULTIPLY:
				int mult;
				mult = accumulator * memory[operand];
				if (-9999 > mult) {
					cout << "*** ABEND: underflow ***" << endl << endl;
					return;
				} else {
					if (9999 < mult) {
						cout << "*** ABEND: overflow ***" << endl << endl;
						return;
					} else {
						accumulator = mult;
					}
				}
				break;

			case DIVIDE:
				int div;
				if (memory[operand] == 0) {
					cout << "*** ABEND: attempted division by 0 ***" << endl << endl;
					return;
				} else {
					div = accumulator / memory[operand];
					accumulator = div;
				}
				break;

			case BRANCH:
				instruction_counter = operand;
				break;

			case BRANCHNEG:
				if (accumulator < 0) {
					instruction_counter = operand;
					break;
				} else {
					instruction_counter++;
					break;
				}	

			case BRANCHZERO:
				if (accumulator == 0) {
					instruction_counter = operand;
					break;
				} else {
					instruction_counter++;
					break;
				}

			case HALT:
				cout << "*** Simplesim execution terminated ***" << endl << endl;	
				return;

			default:
				cout << "*** ABEND: invalid opcode ***" << endl << endl;
				return;
		
		}
		if (operation_code != BRANCH && operation_code != BRANCHNEG && operation_code != BRANCHZERO && !done) {
			instruction_counter++;
		}
	}
	return;
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
