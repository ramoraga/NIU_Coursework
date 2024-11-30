/***************************************************************
 CSCI 240         Program 3     Fall 2019
 
 Programmer: Reinaldo Moraga
 
 Section: 2
 
 Date Due: 9/20/2019
 
 Purpose: To write a program that will calculate the amount that
 a customer spends on tickets at a movie theater and to apply a
 discount if available
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
    
    string coupon,type; //declare string values
    cout << "Do you have a discount coupon (Y for Yes)?"; //ask user if they have a coupon
    cin >> coupon; //get answer from keyboard
    
    if (coupon=="Y") { //if "Yes", then ask for type of coupon
        double discount; //decalre double value
        cout << "Is the discount for an adult or child's ticket (A for adult, C for child)?";
        cin >> type; //get type from keyboard
        if (type=="A") {
            discount=11.25; //if type is adult coupon, then discount is 11.25
        } else {
            if (type=="C") {
                discount=4.50; //else, type is child coupon, then discount is 4.50
            } else {
                cout << "Error: " << type << " is not a valid discount type. No discount will be applied\n";
                discount=0.00; //if user inputs anything other than A or C, then type value is invalid and discount is 0.00
            }
        }
        double total=((11.25*adult)+(4.50*child))-discount; //declare double value and compute total purchase w/ discount
        
        cout << "\n******************************************\n" << setw(28) << "Theater Sale\n" << "******************************************\n";
        
        cout << "Number of Adult Tickets:" << setw(18) << right << adult << endl; //number of adult tickets are displayed. Right justified by 18 characters from quote
        cout << "Number of Child Tickets:" << setw(18) << right << child << endl; //number of child tickets are displayed. Right justified by 18 characters from quote
        cout << "\nDiiscount:" << setw(32) << right << fixed << setprecision(2) << discount << endl; //discount is displayed. Right justified by 32 characters from quote
        cout << "\nTotal Purchase:" << setw(27) << right << fixed << setprecision(2) << total << endl; //Computed total purchase is displayed. Right justified by 27 characters
        
        return 0;
    }
    double total=(11.25)*adult+(4.50*child); //declare double value and compute total purchase
    
    cout << "\n******************************************\n" << setw(28) << "Theater Sale\n" << "******************************************\n";
    
    cout << "Number of Adult Tickets:" << setw(18) << right << adult << endl; //number of adult tickets are displayed. Right justified by 18 characters from quote
    cout << "Number of Child Tickets:" << setw(18) << right << child << endl; //number of child tickets are displayed. Right justified by 18 characters from quote
    cout << "\nTotal Purchase:" << setw(27) << right << fixed << setprecision(2) << total << endl; //Computed total purchase is displayed. Right justified by 27 characters
    
    return 0;
}
