/***************************************************************
 CSCI 240         Program 6     Fall 2019
 
 Programmer: Reinaldo Moraga
 
 Section: 2
 
 Date Due: 10/25/2019
 
 Purpose: To write a program that will simulate a game of
 roulette
 ***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

char betOptionsMenu(); //declares functions
int spinWheel();
int getSingleNum();
void displayWheelResult(char type, int pocketNumber);
char getPocketColor(int pocketNumber);
char getPocketEvenOdd(int pocketNumber);

int main()
{
    srand(6); // seed value is 6
    char choice; //decalres variables
    int userNumber;
    int gameNumber;
    char color;
    char style;
    choice = betOptionsMenu(); //call betOptionsMenu function, choice will be filled w/ player's choice
    
    while (choice!= 'Q') {
        gameNumber = spinWheel(); //call spinWheel function, gameNumber will equal generated number
        if (choice == 'S') { //if choice = S
            userNumber = getSingleNum(); //call getSingleNum function, userNumber will be filled w/ player's number
            displayWheelResult(choice, gameNumber); //call displayWheelResult function, choice and gameNumber fill in for type and pocketNumber
            if (userNumber == gameNumber) {
                cout << "\nYou WON!" << endl << endl; //if player's number = generated number, player wins, if not they lose
                choice = 'Q';
            } else {
                cout << "\nYou LOSE!" << endl << endl;
                choice = 'Q';
            }
        } else {
            if (choice == 'R' || choice == 'G' || choice == 'B') { //if choice =R,G,or B
                color = getPocketColor(gameNumber); //call getPocketColor function, color will equal generated result, generated number fills in for pocketNumber
                displayWheelResult(choice, gameNumber);
                if (color == choice) { //if color = choice, player wins, if not they lose
                    cout << "\nYou WON!" << endl << endl; //message states they win
                    choice = 'Q';
                } else {
                    cout << "\nYou LOSE!" << endl << endl; //message states they lose
                    choice = 'Q';
                }
            } else {
                if (choice == 'E' || choice == 'O') { //if choice =E or O
                    style = getPocketEvenOdd(gameNumber); //call getPocketEvenOdd function, style will equal generated result, generated number fills in for pocketNumber
                    displayWheelResult(choice, gameNumber);
                    if (style == choice) { //if style=choice, then player wins, if not they lose
                        cout << "\nYou WIN!" << endl << endl;
                        choice = 'Q';
                    } else {
                        cout << "\nYou LOSE!" << endl << endl;
                        choice = 'Q';
                    }
                }
            }
        }
    }
    return 0;
}

/***************************************************************
Function: char betOptionsMenu()
 
Use: This function asks the user for their choice of bet on
    the game of roulette or to quit (S, R, B, E, O, Q)

Arguments: None

Returns: char variable type which is the player's choice

Note: None
***************************************************************/
char betOptionsMenu()
{
    char type;
    cout << "What type of bet would you like?\n\t(S = single number, R = red, B = black, E = even, O = odd, Q = quit the game):";
    cin >> type;
    while ((type != 'S') && (type != 'R') && (type != 'B') && (type != 'E') && (type != 'O') && (type != 'Q')) {
        cout << "Invalid Option! Try again:";
        cin >> type;
    }
    return type;
}

/***************************************************************
Function: int spinWheel()
 
Use: This function generates a random number between
    0-36

Arguments: None

Returns: int variable pocketNumber which is the
    generated number

Note: None
***************************************************************/
int spinWheel()
{
    int pocketNumber = (rand()%37);
    return pocketNumber;
}

/***************************************************************
Function: int getSingleNum()
 
Use: This function asks the user what number between
    0-36 would they like to bet on

Arguments: None

Returns: int variable answer which is the player's choice

Note: None
***************************************************************/
int getSingleNum()
{
    int answer;
    cout << "What number would you like to bet on (0-36)?:";
    cin >> answer;
    while ((0 > answer || 36 < answer)) {
        cout << "Invalid Number! Try again:";
        cin >> answer;
    }
    return answer;
}

/***************************************************************
Function: void displayWheelResult(char type, int pocketNumber)
 
Use: This function displays the results on whether they won
    or lost the game based on their bet

Arguments: type - a character that represents the type of bet
                made by the player
        pocketNumber - an integer that represents the number
                    generated by the spinwheel

Returns: Nothing

Note: None
***************************************************************/
void displayWheelResult(char type, int pocketNumber)
{
    cout << "\nThe wheel is spinning...and landed on ";
    if (type == 'S') {
        cout << pocketNumber << endl;
    }
    if (type == 'R') {
        cout << getPocketColor(pocketNumber) << " (" << pocketNumber << ")" << endl;
    }
    if (type == 'B') {
        cout << getPocketColor(pocketNumber) << " (" << pocketNumber << ")" << endl;
    }
    if (type == 'G') {
        cout << getPocketColor(pocketNumber) << " (" << pocketNumber << ")" << endl;
    }
    if (type == 'E') {
        cout << getPocketEvenOdd(pocketNumber) << " (" << pocketNumber << ")" << endl;
    }
    if (type == 'O') {
        cout << getPocketEvenOdd(pocketNumber) << " (" << pocketNumber << ")" << endl;
    }
}

/***************************************************************
Function: getPocketColor(int pocketNumber)
 
Use: This function determines whether the number generated
    by the spinwheel is green, black, or red

Arguments: pocketNumber - an integer that represents the number
                        generated by the spinwheel

Returns: char variable PocketColor which is the color of the
        pocket the ball lands on

Note: None
***************************************************************/
char getPocketColor(int pocketNumber)
{
    if (pocketNumber == 0) {
        char PocketColor = 'G';
        return PocketColor;
    }
    if ((1<=pocketNumber && pocketNumber<=10) || (19<=pocketNumber && pocketNumber<=28)) {
        if (pocketNumber % 2==0) {
            char PocketColor = 'B';
            return PocketColor;
            } else {
                char PocketColor = 'R';
                return PocketColor;
            }
    }
    if ((11<=pocketNumber && pocketNumber<=18) || (29<=pocketNumber && pocketNumber<=36)) {
        if (pocketNumber % 2==0) {
            char PocketColor = 'R';
            return PocketColor;
            } else {
                char PocketColor = 'B';
                return PocketColor;
                }
            }
    return 0;
}

/***************************************************************
Function: getPocketEvenOdd(int pocketNumber)
 
Use: This function determines whether the number generated
    by the spinwheel is zero, even, or odd

Arguments: pocketNumber - an integer that represents the number
                        generated by the spinwheel

Returns: char variable PocketEvenOdd which determines the style of the
        number the spinwheel generated

Note: None
***************************************************************/
char getPocketEvenOdd(int pocketNumber)
{
    if (pocketNumber == 0) {
        char PocketEvenOdd = 'Z';
        return PocketEvenOdd;
    } else {
        if (pocketNumber % 2 == 0) {
            char PocketEvenOdd = 'E';
            return PocketEvenOdd;
        } else {
            char PocketEvenOdd = 'O';
            return PocketEvenOdd;
        }
    }
}
