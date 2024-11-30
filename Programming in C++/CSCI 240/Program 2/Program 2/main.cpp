/***************************************************************
 CSCI 240         Program 2     Fall 2019
 
 Programmer: Reinaldo Moraga
 
 Section: 2
 
 Date Due: 9/13/2019
 
 Purpose: To write a program that will calculate the amount that
 a customer spends on tickets at a movie theater.
 ***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int adult,child; //declare integer values
    
    cout << "Enter the number of adult tickets that are being purchased:"; //ask user for number of adult tickets
    cin >> adult; //get integer from keyboard
    
    cout << "Enter the number of child tickets that are being purchased:"; //ask user for number of child tickets
    cin >> child; //get integer from keyboard
    
    double total=(11.25)*adult+(4.50*child); //declare double value and compute total purchase
    
    cout << "\n******************************************\n" << setw(28) << "Theater Sale\n" << "******************************************\n";
    
    cout << "Number of Adult Tickets:" << setw(18) << right << adult << endl; //number of adult tickets are displayed. Right justified by 18 characters from quote
    cout << "Number of Child Tickets:" << setw(18) << right << child << endl; //number of child tickets are displayed. Right justified by 18 characters from quote
    cout << "\nTotal Purchase:" << setw(27) << right << fixed << setprecision(2) << total << endl; //Computed total purchase is displayed. Right justified by 27 characters
    
    return 0;
}
