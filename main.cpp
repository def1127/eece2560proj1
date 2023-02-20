/*****************************************************************************
 * File: main.cpp
 * @author: Anwar S., David F., Julian C.
 * Date Created: February 8, 2023
 * The program uses lockBox objects to create an store a secret combination
 * of the client's desired length and digit range, and uses lockBox objects 
 * to store the client's guess. Additionally, the program employs ClientFeedback
 * objects and SmartClient objects to help the client in their guess by providing
 * feedback! 
******************************************************************************/

/*System Libraries*/
#include <iostream>

/*User Libraries*/
#include "SmartClient.h"
#include "LockBox.h"
#include "ClientFeedback.h"


using namespace std;

int main()
{
    /*Declare variables to store secret combo length and range of digits*/
    int digits, range;

    /*Declare vector of type integer to store client guess*/
    std::vector<int> input;

    /*Prompt user input*/
    cout << "Enter number of digits in combination: ";
    cin >> digits;

    /*Error handling*/
    if(cin.fail())
    {
        return 1;
    }

    /*Prompt user input*/
    cout << "\nEnter range of digits: ";
    cin >> range;

    /*Error handling*/
    if(cin.fail())
    {
        return 1;
    }

    /*Use time to help randomize secret combination*/
    cout << "\nGenerating combination...\n";

    /*Declare instance of SmartClient object, with user input as parameters*/
    SmartClient instance(digits,range);

    /*Call openLockBox method on SmartClient object*/
    instance.openLockBox();

    return 0;//end program

}