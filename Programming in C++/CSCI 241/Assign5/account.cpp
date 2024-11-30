//***************************************************************************
//
//  account.cpp
//  CSCI 241 Assignment 5
//
//  Created by Reinaldo Moraga (z1864815)
//
//***************************************************************************

#include "account.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

account::account()		//default constructor
{	
	// define private data members
	const char def[] = "None";
	strcpy(accNum, def);
	strcpy(name, def);
	accBal = 0;
}

const char* account::get_account_number() const	
{
	// returns account number
	return accNum;
}

double account::get_balance() const
{
	// returns account balance
	return accBal;
}

void account::process_deposit(double deposit)
{
	// adds deposit amount to balance
	accBal = accBal + deposit;
}

bool account::process_withdrawal(double withdrawal)
{
	// returns false if balance is less than withdrawal amount
	if (accBal < withdrawal) {
		return false;
	} else {
		// subtracts withdrawal amount from balance and returns
		// true if balance is greater than withdrawal amount
		accBal = accBal - withdrawal;
		return true;
	}
}

void account::print() const
{
	// prints account number, name on the account, and total balance
	// in format
	cout << "Account Number: " << accNum << endl;
	cout << "Name: " << name << endl;
	cout << "Balance: $" << fixed << setprecision(2) << accBal << endl;
}
