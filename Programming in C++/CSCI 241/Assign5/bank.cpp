//***************************************************************************
//
//  bank.cpp
//  CSCI 241 Assignment 5
//
//  Created by Reinaldo Moraga (z1864815)
//
//***************************************************************************

#include "bank.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

bank::bank()					// default constructor
{
	// defines private data members 
	const char def[] = "None";
	strcpy(bankName, def);
	numElements = 0;
}

void bank::read_accounts(const string& fileName)
{
	// call ifstream class
	ifstream in_file;

	// opens fileName(accounts)
	in_file.open(fileName);
	if (!in_file) {
		// ERROR
		cerr << "Error - unable to open input file " << fileName << endl;
		exit(1);
	}
	
	// reads accounts, closes file, and calls sort_accounts 
	// member function to sort accounts
	in_file.read((char*) this, sizeof(bank));

	in_file.close();

	sort_accounts();
}

void bank::process_transactions(const string& fileData)
{
	// print report header and column headers
	cout << "Transaction Report" << endl << endl;
	cout << "Date" << setw(11) <<  "Account" << setw(10) << "Type" << setw(10) << "Amount" << setw(16) << "New Balance" << endl;

	string date;			// date transaction was made
	char account_number[11];	// account number
	char type;			// type of transaction (deposit || withdrawal)
	double amount;			// amount of money that is deposited or withdrawn

	int index;			// used for binary_search member function

	// call istream class
	ifstream trans_file;

	// opens fileData(transactions.txt)
	trans_file.open(fileData);
	if (!trans_file) {
		// ERROR
		cerr << "Error - unable to open trans file " << fileData << endl;
		exit(1);
	}
	
	// reads input from file
	while (trans_file >> date) {
		trans_file >> account_number;
		trans_file >> type;
		trans_file >> amount;
		
		// print date, account number, type, and amount in format
		cout << endl << date << setw(13) << account_number << setw(4) << type << setw(15) << amount;

		// calls binary_search member function
		// index = result
		index = binary_search(account_number);

		// if index = -1, the account number is invalid
                if (index == -1) {
			cout << setw(33) << "*** Invalid account number ***";
		} else {
			// if type of transaction is deposit, call process_deposit
			// member function and print new balance using get_balance
			if (type == 'D') {
				accObj[index].process_deposit(amount);
				cout << setw(11) << accObj[index].get_balance();
			} else {
				// if type of transaction is withdrawal, call process_withdrawal
				// member function. If process_withdrawal returns true,
				// then print new balance using get_balance
				if (accObj[index].process_withdrawal(amount) == true) {
					cout << setw(11) << accObj[index].get_balance();
				} else {
					// if process_withdrawal returns false, then print error
					// message
					cout << setw(29) << "*** Insufficient funds ***";
				}
			}
		}
	}
	cout << endl;
	// close file
	trans_file.close();

	return;
}

void bank::print() const
{
	// print header
	cout << endl << "Account Listing for " << bankName << endl << endl;
	// print accounts by using print member function from account class
	// in format
	for (int i = 0; i < numElements; i++) {
		accObj[i].print();
		cout << endl;
	}
}

void bank::sort_accounts()		// sorts accounts in numerical order
{
	// account object temp declared
	account temp;
	int j;

	for (int i = 1; i < numElements; i++) {
		temp = accObj[i];
		// check if one account number is smaller than the one below it
		for (j = i; j > 0 && strcmp(accObj[j-1].get_account_number(), temp.get_account_number()) > 0; j--) {
			accObj[j] = accObj[j-1];
		}
		accObj[j] = temp;
	}
}

int bank::binary_search(char* accNum)	// searches for account number
{
	int low = 0;
	int high = numElements;
	int mid; 
	int ret;			// value used to check strcmp
	const char* comp = accNum;	// account number from transactions.txt (search key)
	while (low <= high) {
		mid = (low + high) / 2;
		// if search key is == to account number, then return subscript
		if ((ret = strcmp(accObj[mid].get_account_number(), comp)) ==  0) {
			return mid;
		} else {
			// else, if search key is less than account number, adjust end subscript
			if ((ret = strcmp(accObj[mid].get_account_number(), comp)) > 0) {
				high = mid - 1;
			} else {
				// else, adjust start subscript
				low = mid + 1;
			}
		}
	}
	// returns -1 if search key is not found
	return -1;
}

