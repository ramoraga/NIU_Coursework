/***************************************************************
CSCI 240         Program 8     Fall 2019

Programmer: Reinaldo Moraga

Section: 2

Date Due: 11/24/2019

Purpose: To write a driver program that calls various
 methods to display a number, the sum, the reverse
 order, the odd, the even digits of the number, as well
 as the zero digits
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

class myInt // class definition
{
public: //methods available to driver code
    myInt(); //defaulty constructor prototype
    myInt(int); //another constructor prototype that expects an in
    
    void print(); //prototype methods
    
    int getIntValue();
    void setInt(int);
    
    int sumDigits();
    int reverse();
    void digitTypeCount(int&, int&, int&);

private: //not directly available to the driver code
    int num; //non zero integer for an object of this class
};

const int NUM_VALUES = 10; //symbolic constants
const int SEED_VALUE = 312;

int main() //main driver starts
{
    myInt myNumber; //object
    int oddCnt, evenCnt, zeroCnt; //variables to hold to hold the count of the different types of digit
    srand(SEED_VALUE); //set seed value
    
    for (int cnt = 0; cnt < NUM_VALUES; cnt++) {
        myNumber.setInt(rand()); //generate random number and call setInt method
        cout << "The number is ";
        myNumber.print(); //display the random integer that is in the object
        
        //display the result of adding and reversing the digits
        cout << endl
        << "----------------------------------------" << endl
        << "Adding the digits" << setw(18) << myNumber.sumDigits() << endl
        << "Reversing the digits" << setw(15) << myNumber.reverse()
        << endl;
        
        myNumber.digitTypeCount(oddCnt, evenCnt, zeroCnt); //determine and display the number of odd, even, and zero digits
        
        cout << "\nOdd digits" << setw(25) << oddCnt << endl
        << "Even digits" << setw(24) << evenCnt << endl
        << "Zero" << setw(31) << zeroCnt << endl << endl;
    }
    return 0;
}
/***************************************************************
Function: myInt()

Use: This function sets the value of the int num to be 0

Arguments: None

Returns: None

Note: None
***************************************************************/
myInt::myInt()
{
    num = 0;
}

/***************************************************************
Function: void print()

Use: This function displays the value of int num

Arguments: None

Returns: None

Note: None
***************************************************************/
void myInt::print()
{
    cout << num;
}

/***************************************************************
Function: int getIntValue()

Use: This function returns the value of int num

Arguments: None

Returns: num

Note: None
***************************************************************/
int myInt::getIntValue()
{
    return num;
}

/***************************************************************
Function: void setInt(int rand)

Use: This function generates and sets the value of int num
 to a random value

Arguments: int rand

Returns: None

Note: None
***************************************************************/
void myInt::setInt(int rand)
{
    num = abs(rand);
}

/***************************************************************
Function: int sumDigits()

Use: This function adds each digit from the random num

Arguments: None

Returns: sum

Note: None
***************************************************************/
int myInt::sumDigits()
{
    int temp1, temp2, sum;
    sum = 0;
    temp2 = num;
    while (num != 0) {
        temp1 = num % 10;
        num = num / 10;
        sum = sum + temp1;
    }
    num = temp2;
    return sum;
}

/***************************************************************
Function: int reverse()

Use: This function reverse the order of digits in int num

Arguments: None

Returns: reverseNum

Note: None
***************************************************************/
int myInt::reverse()
{
    int reverseNum, temp1, temp2;
    reverseNum = 0;
    temp2 = num;
    while (num != 0) {
        reverseNum = reverseNum * 10;
        temp1 = num % 10;
        reverseNum = temp1 + reverseNum;
        num = num / 10;
    }
    num = temp2;
    return reverseNum;
}

/***************************************************************
Function: void digitTypeCount (int& odd, int& even, Int& zero)

Use: This functions determines the number of odd, even
 and zero digits in int num

Arguments: int& odd, int& even, int& zero

Returns: None

Note: None
***************************************************************/
void myInt::digitTypeCount(int& odd, int& even, int& zero)
{
    int temp1, temp2, io, ie, iz;
    temp2 = num;
    temp1 = 0;
    io = 0;
    ie = 0;
    iz = 0;
    while (num != 0) {
        temp1 = num % 10;
        if (temp1 == 0) {
            iz++;
        } else {
            if (temp1 % 2 == 0) {
                ie++;
            } else {
                io++;
            }
        }
        num = num / 10;
    }
    odd = io;
    even = ie;
    zero = iz;
    num = temp2;
}
