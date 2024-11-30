/***************************************************************
 CSCI 240         Program 1     Fall 2019
 
 Programmer: Reinaldo Moraga
 
 Section: 2
 
 Date Due: 9/6/2019
 
 Purpose: The purpose of this program is to calculate and display
 the gravitational force between two objects.
 
 The user provides the mass of the two objects and the
 distance between the objects.
 ***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double gre,answer;
    gre=0.667e-10;
    
    float mass1,mass2,distance;
    
    cout << "Enter the mass for object 1 (in kg):";
    cin >> mass1;
    
    cout << "Enter the mass for object 2 (in kg):";
    cin >> mass2;
    
    cout << "Enter the distance between the two objects (in meters):";
    cin >> distance;
    
    answer=(mass1*mass2*gre)/(distance*distance);
    
    cout << "\nThe force of gravitational force is " << answer << " newtons\n";

    return 0;
}
