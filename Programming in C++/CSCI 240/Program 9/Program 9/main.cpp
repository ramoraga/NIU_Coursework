/***************************************************************
CSCI 240         Program 9     Fall 2019

Programmer: Reinaldo Moraga

Section: 2

Date Due: 12/6/2019

Purpose: To create, print, and modify Seller objects that
 use c_strings
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Seller //Seller class
{
public: //public constructors and methods
    
    Seller(); //default constructor
    Seller (const char [], const char [], const char [], double); //constructor that takes values
    
    void print();
    void setFirstName(const char []);
    void setLastName(const char []);
    void setID(const char []);
    void setSalesTotal(double);
    double getSalesTotal();
    
private: //private variables
    char firstName[20];
    char lastName[30];
    char ID[7];
    double salesTotal;
};

int main()
{
    Seller seller1("Reinaldo", "Moraga", "CSI240", 1234.56); // create first seller object
    cout << "The First Seller" << endl;
    seller1.print(); //print first seller object
    cout << endl;
    
    Seller seller2; //create second seller object
    cout << "The Second Seller" << endl;
    seller2.setFirstName("None"); //set first name to default
    seller2.setLastName("None"); //set last name to default
    seller2.setID("ZZZ999");  //set ID to default
    seller2.setSalesTotal(0); //set ID to default
    seller2.print();
    seller2.setFirstName("Mitchell");
    seller2.setLastName("Trubisky");
    seller2.setID("QB10");
    seller2.setSalesTotal(246.80);
    seller2.print();
    cout << endl;
    
    Seller seller3("", "Robinson", "TOOBIG999", -876.34); //similar to seller 2
    cout << "The Third Seller" << endl;
    seller3.print();
    seller3.setFirstName("Allen");
    seller3.setID("WIDE12");
    seller3.setSalesTotal(9900000.99);
    seller3.print();
    cout << endl;
    
    Seller seller4("Tarik", "Cohen", "RUN29", 13579.11);
    cout << "The Fourth Seller" << endl;
    cout << "The sales total is $" << seller4.getSalesTotal() << endl << endl; //displays only sales total
    
    Seller seller5("Kyle", "Long", "TACK75", 24680.24);
    cout << "The Fifth Seller" << endl;
    seller5.print();
    seller5.setFirstName(""); //set first & last name & ID to empty string
    seller5.setLastName("");
    seller5.setID("");
    seller5.setSalesTotal(-52.96);
    seller5.print();
    cout << endl;
    
    return 0;
}

/***************************************************************
Function: Seller()

Use: Default constructor

Arguments: None

Returns: None

Note: None
***************************************************************/
Seller::Seller()
{
    
}

/***************************************************************
Function: Seller (const char fName[], const char lName[], const char identification[], double sTotal)

Use: This function takes an argument and sets the data variables

Arguments: const char fName[], const char lName[], const char identification[], double sTotal

Returns: None

Note: None
***************************************************************/
Seller::Seller(const char fName[], const char lName[], const char identification[], double sTotal)
{
    setFirstName(fName);
    setLastName(lName);
    setID(identification);
    setSalesTotal(sTotal);
}

/***************************************************************
Function: print()

Use: This function converts c strings into strings. Displays, first & last name,
 id and sales total

Arguments: None

Returns: None

Note: None
***************************************************************/
void Seller::print()
{
    string strLname(lastName);
    string strFname(firstName);
    cout << fixed << setprecision(2) << left << setw(25) << strLname + ", " + strFname << right << setw(15) << ID << setw(15) << salesTotal << endl;
}

/***************************************************************
Function: setFirstName(const char fName[])

Use: This function sets the firstName data variable to fName[]

Arguments: const char fName[]

Returns: None

Note: None
***************************************************************/
void Seller::setFirstName(const char fName[])
{
    const char lessThan[] = "None";
    if (strlen(fName)>0) {
        strcpy(firstName, fName);
    } else {
        strcpy(firstName, lessThan);
    }
}

/***************************************************************
Function: setLastName(const char lName[])

Use: This function sets the lastName data variable to lName[]

Arguments: const char lName[]

Returns: None

Note: None
***************************************************************/
void Seller::setLastName(const char lName[])
{
    const char lessThan[] = "None";
    if (strlen(lName)>0) {
        strcpy(lastName, lName);
    } else {
        strcpy(lastName, lessThan);
    }
}

/***************************************************************
Function: setID(const char identification[])

Use: This function sets the ID data variable to identification[]

Arguments: const char identification[]

Returns: None

Note: None
***************************************************************/
void Seller::setID(const char identification[])
{
    const char lessThan[] = "ZZZ999";
    if (strlen(identification)>0 && 7>strlen(identification)) {
        strcpy(ID, identification);
    } else {
        strcpy(ID, lessThan);
    }
}

/***************************************************************
Function: setSalesTotal(double sTotal])

Use: This function sets the salesTotal data variable to sTotal

Arguments: double sTotal

Returns: None

Note: None
***************************************************************/
void Seller::setSalesTotal(double sTotal)
{
    if (sTotal >= 0) {
        salesTotal = sTotal;
    } else {
        salesTotal = 0;
    }
}

/***************************************************************
Function: getSalesTotal()

Use: This function returns salesTotal

Arguments: None

Returns: salesTotal

Note: None
***************************************************************/
double Seller::getSalesTotal()
{
    return salesTotal;
}
