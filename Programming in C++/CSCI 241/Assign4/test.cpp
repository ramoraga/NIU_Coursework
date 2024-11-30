#include "sml.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int accumulator = 0;
	int instruction_counter = 8;
	int instruction_register = 0;
	int operation_code = 0;
	int operand = 0;
	int memory[100];
	
	for (int i = 0; i < 100; i++) {
		memory[i] = 4444;
	}

	int n = 0;
	int num;
	int test[100];
	int cap = 100;

	while (cin >> num && num != -99999) {
		test[n] = num;
		n++;
	}
		
	if (n > cap) {
		cout << "*** ABEND: pgm load: pgm too large ***" << endl;
	} else {
		for (int j = 0; j < n; j++) {
			if (test[j] > 9999 || -9999 > test[j]) {
				cout << "*** ABEND: pgm load: invalid word ***" << endl;
			} else {
				memory[j] = test[j];
			}
		}
	}

	bool done = false;
	
	while (!done) {
		if (instruction_counter > 100 && -1 <  instruction_counter) {
			instruction_register = memory[instruction_counter];
			operation_code = instruction_register/100;
			operand = instruction_register % 100;
		} else {
			cout << "*** ABEND: addressability error ***" << endl;
			return 0;
		}

		switch (operation_code) {
			case READ:
				int temp[100];
				int num;
				int n;
				while ( cin >> num ) {
				       temp[n] = num;
				       n++;
				}
				
				if (-9999 > temp[n] || temp[n] >= 9999) {
					cout << "*** ABEND: illegal input ***" << endl;
					return 0;
					} else {
						memory[operand] = temp[n];
					}
				cout << "READ: " << showpos << setfill('0') << internal << setw(5) << memory[operand] << endl;
				break;

			case WRITE:
				cout << showpos << setfill('0') << internal << setw(5) << memory[operand] << endl;
				break;

			case HALT:
				cout << "*** Simplesim execution terminated ***" << endl;
				break;
		}
	}

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
	return 0;
}
