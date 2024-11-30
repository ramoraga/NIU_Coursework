/***************************************************************
 CSCI 240         Program 7     Fall 2019
 
 Programmer: Reinaldo Moraga
 
 Section: 2
 
 Date Due: 11/10/2019
 
 Purpose: To write a program that will process two sets of
 numeric information.
 ***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
double lowBound = 1;
double upBound = 250;
int minNum = 30;
int maxNum = 50;
int maxNumDisp = 10;

using namespace std;

int buildFromFile(double array[]); //declare functions
double randDouble();
int buildRandom(double array[]);
void print(string title, double array[], int numberOfValues);
void sort (double array[], int numberOfValues);
int main ()
{
    srand(18); //seed is 18
    double array1[50]; //declare double arrays
    double array2[50];
    int size1, size2;
    string title1 = "Array of numbers from a file"; //declare string titles
    string title2 = "Array of random numbers";
    size1 = buildFromFile(array1); //declare sizes
    size2 = buildRandom(array2);
    cout << "Number of values in the file: " << size1 << "\nNumber of random values: " << size2 << endl << endl;
    print(title1, array1, size1); //print infile and random array
    print(title2, array2, size2);
    sort(array1, size1); //sort infile and random array
    sort(array2, size2);
    title1 = "Sorted array of numbers from a file"; //redefine string titles
    title2 = "Sorted array of random numbers";
    print(title1, array1, size1); //reprint infile and random arrays as sorted arrays
    print(title2, array2, size2);
    
    return 0;
}


int buildFromFile(double array[])
{
    int i=0;
    double num1;
    ifstream infile;
    infile.open("nums.txt");
    
    if (infile.fail()) {
        cout << "fail";
        exit(-1);
    }
    
    infile >> num1;
    while (infile) {
        array[i] = num1;
        i++;
        infile >> num1;
    }
    
    infile.close();
    return i;
}

double randDouble()
{
    double randDouble = lowBound + (rand() / (RAND_MAX / (upBound - lowBound)));
    return randDouble;
}

int buildRandom(double array[])
{
    int numOfValues = minNum + (rand() % (maxNum - minNum + 1));
    int i;
    for (i=0; i<numOfValues; i++) {
        array[i] = randDouble();
    }
    return numOfValues;
}

void print(string title, double array[], int numberOfValues)
{
    cout << title << endl << endl;
    int i;
    int LC=1;
    for (i=0; i<numberOfValues; i++) {
        cout << fixed << setprecision(1) << right << setw(5) << array[i] << " ";
        if (LC==maxNumDisp) {
            cout << endl;
            LC=1;
        } else {
            LC++;
        }
    }
    cout << endl << endl;
}

void sort(double array[], int numberOfValues)
{
    int Begin = 0;
    int End = numberOfValues-1;
    int I, Low;
    double temp;
    
    while (Begin<End) {
        Low = Begin;
        I = Begin + 1;
        while (I <= End) {
            if (array[I] < array[Low]) {
                Low = I;
            }
            I = I + 1;
        }
        temp = array[Low];
        array[Low] = array[Begin];
        array[Begin] = temp;
        Begin = Begin + 1;
    }
}
