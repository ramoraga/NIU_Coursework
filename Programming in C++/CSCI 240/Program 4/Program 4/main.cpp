/***************************************************************
 CSCI 240         Program 4     Fall 2019
 
 Programmer: Reinaldo Moraga
 
 Section: 2
 
 Date Due: 9/29/2019
 
 Purpose: To write a program that will write three sets of
 randomly generated numbers from a range of 0-99
 ***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
int main()
{
    srand(5);
    
    int LC=0;
    int count1 = 5 + (rand() % (250 - 5 + 1));
    cout << "There are " << count1 << " numbers in the first set of numbers.\n\n";
    
    for (int i=1; i<=count1; i++) {
        int num=rand()%100;
        if (LC!=20) {
            cout << setw(2) << num << " ";
            LC++;
        } else {
            cout << endl;
            LC=0;
        }
    }
    cout << endl << endl;
    
    LC=0;
    int count2 = 5 + (rand() % (250 - 5 + 1));
    cout << "There are " << count2 << " numbers in the second set of numbers.\n\n";
    
    int i=1;
    while (i<=count2) {
        int num=rand()%100;
        if (LC!=20) {
            cout << setw(2) << num << " ";
            LC++;
        } else {
            cout << endl;
            LC=0;
        }
        i=i+1;
    }
    cout << endl << endl;
    
    LC=0;
    int count3 = 5 + (rand() % (250 - 5 + 1));
    cout << "There are " << count3 << " numbers in the third set of numbers.\n\n";
    
    i=1;
    do {
        int num=rand()%100;
        if (LC!=20) {
            cout << setw(2) << num << " ";
            LC++;
        } else {
            cout << endl;
            LC=0;
        }
        i=i+1;
    } while (i<=count3);
    cout << endl;
    
    return 0;
}
