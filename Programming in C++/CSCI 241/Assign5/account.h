//***************************************************************************
//
//  account.h
//  CSCI 241 Assignment 5
//
//  Created by Reinaldo Moraga (z1864815)
//
//***************************************************************************

#ifndef ACCOUNT_H
#define ACCOUNT_H

class account								// declare account class
{									// declare private data members for account class
	private:
		char accNum[11];
		char name[21];
		double accBal;

	public:								// declare public member functions for account class
		account();
		account(int);
		const char* get_account_number() const;
		double get_balance() const;
		void process_deposit(double);
		bool process_withdrawal(double);
		void print() const;
};

#endif /* ACCOUNT_H */
