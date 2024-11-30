/***************************************************************
 CSCI 240         Program 5     Fall 2019
 
 Programmer: Reinaldo Moraga
 
 Section: 2
 
 Date Due: 10/11/2019
 
 Purpose: To write a program that will simulate a single
 game of Craps
 ***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

#define win1 7 // define symbolic constants
#define win2 11
#define lose1 2
#define lose2 3
#define lose3 12

using namespace std;
int main()
{
    srand(22); // seed value is 22

    int Roll1 = 1 + (rand() % (6 - 1 + 1)); // declare integer values
    int Roll2 = 1 + (rand() % (6 - 1 + 1));
    int Value = Roll1+Roll2;
    cout << "Roll: " << Roll1 << " + " << Roll2 << " = " << Value << endl;
    
    if (Value == win1 || Value == win2) {  // utilize both win symbolic constants
        cout << "\nCongragulations! You won!" << endl << endl; // if value == 7 or 11, player wins
    } else {
        if (Value ==lose1 || Value == lose2 || Value == lose3) {
            cout << "\nCraps! You lose!" << endl << endl; // if value == 2,3, or 12, player loses
        } else {
            int Point=Value;
            cout << "\nThe point is " << Point << endl << endl; // game continues if value isn't == to decalred symbolic constants and value=point
            bool stop = true; //bool integer decalred
            while (stop == true) { // loop that allows the game to continue and rolls dice
                int Roll1 = 1 + (rand() % (6 - 1 + 1));
                int Roll2 = 1 + (rand() % (6 - 1 + 1));
                int Value = Roll1+Roll2;
                cout << "Roll: " << Roll1 << " + " << Roll2 << " = " << Value << endl;
                if (Value == Point) { //if roll is equal to point, player wins
                    cout << "\nThe point was made! You won!" << endl << endl;
                    stop = false;
                } else {
                    if (Value == win1) { // if roll is equal to declared symbolic constant, the player wins
                        cout << "\nSeven'd out! You lose!" << endl << endl;
                        stop = false;
                    } else {
                        stop = true; // if roll is equal to neither point or symbolic constant, then loop back and continue game
                    }
                }
            }
        }
    }
    return 0;
}
