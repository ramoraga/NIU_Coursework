//***************************************************************************
//
//  main.cpp
//  CSCI 241 Assignment 5
//
//  Created by Reinaldo Moraga (z1864815)
//
//***************************************************************************

#include "bank.h"

int main()
{
	bank b;						// create class object b
	b.read_accounts("accounts");			// call read_accounts member function and read accounts file
	b.print();					// call print member function to print accounts file
	b.process_transactions("transactions.txt");	// call process_transactions member function and read transactions.txt
	b.print();					// call print member function again to print accounts with changes
}
