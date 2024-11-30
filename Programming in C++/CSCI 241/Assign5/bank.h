//***************************************************************************
//
//  bank.h
//  CSCI 241 Assignment 5
//
//  Created by Reinaldo Moraga (z1864815)
//
//***************************************************************************

#ifndef BANK_H
#define BANK_H
#include "account.h"
#include <string>

using namespace std;

class bank								
{									// declare class bank
	private:							// declare private data members for bank class
		char bankName[31];
		account accObj[20];
		int numElements;

	public:								// declare public member functions for bank class
		bank();
		void read_accounts(const string&);
		void process_transactions(const string&);
		void print() const;
		void sort_accounts();
		int binary_search(char*);
};

#endif /* BANK_H */
