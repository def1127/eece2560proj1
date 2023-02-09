/*********************************************************************************************
 * File name: SmartClient.cpp
 * Purpose: Implements the SmartClient class methods
 */

/* System Libraries */
#include <algorithm>

/* User Libraries */
#include "LockBox.h"
#include "ClientFeedback.h"
#include "SmartClient.h"


/**Constructs a smart client object that generates a lockBox object with inputs (5,10)
 * @post A new smart client object is created
 */
SmartClient::SmartClient()
{
    lockBox newBox(5,10);
    secretBox = newBox;
    comboLength = 5;
}

/**Constructs a smart client object that generates a lockBox object with inputs (5,10)
 * @post A new smart client object is created
 * @param n The length value for the combination
 * @param m The range value for the combination
 */
SmartClient::SmartClient(int n, int m)
{
    lockBox newBox(n,m);
    secretBox = newBox;
    comboLength = n;
}

/**Prints secret combination stored in secretBox */
void SmartClient::printSecretCode()
{
    std::vector<int> combination = secretBox.printCombination();
    for(int i: combination)
        std::cout << i << " ";
}

/**Returns a lock box object with the combination of the input int vector.
 * @param input A vector of type integer which stores the client's guess
 * @return lockBox object which stores the client's guess*/
lockBox SmartClient::clientGuess(std::vector<int> input) const
{
    return lockBox(input);
}

/** Returns a client feedback object that stores the guesses matching input lockbox.
 * @param box A lockBox object
 * @return ClientFeedback object which stores the response to a client's guess*/
ClientFeedback SmartClient::getFeedback(lockBox box)
{
    ClientFeedback feedback;//need to be able to setResponse;
    feedback.setResponse(secretBox.correctLocation(box), secretBox.incorrectLocation(box));
    return feedback;
}

/** Checks to see if feedback object guesses show that lockBox is opened (0, non-zero).
 * @param feedback reference to the memory location in which ClientFeedback object is stored*/
bool SmartClient::isOpened(const ClientFeedback& feedback) const
{
    //check if none are incorrectly placed AND that number of correctly guessed is nonzero
    return feedback.getResponse()[1] == 0 && feedback.getResponse()[0] == comboLength;
}

/** Initializes lockBox with random combination and lets user guess combination through console.
 * After ten guesses the guessing feature becomes disabled.
 * @param None
 * @return None
 * */
void SmartClient::openLockBox()
{
    /**Guess count to keep track of # of client's guesses,
     * num to store user input*/
    int guessCount = 0, num;

    //Vector to store client guess
    std::vector<int> input;

    //Store contents of secret lockBox combination
    std::vector<int> combination = secretBox.printCombination();

    //Iterator to access a vector's elements
    std::vector<int>::iterator iter;

    //Print out the secret lockBox combination
    printSecretCode();

    while(true){
        //Prompt client guess
        std::cout<<"\nEnter guess : \n";

        //User input into vector
        for (iter = combination.begin(); iter != combination.end(); iter++){
            std::cin >> num;
            input.push_back(num);
        }

        //Rectify vector order
        // for (iter = input.begin(); iter != input.end(); iter++)
        //     std::reverse(input.begin(), input.end());

        //Create lockBox object out of input vector
        lockBox guessBox = clientGuess(input);

        //Create ClientFeedback object that stores response to client's guess
        ClientFeedback feedback = getFeedback(guessBox);

        //Overloaded << operator to print response to client's guess
        std::cout << feedback << std::endl;

        //Check if the box has been opened
        isOpened(feedback);

        //Increment number of guesses
        guessCount++;

        //If client guesses > 9 or client guesses the correct combo, break loop
        if(isOpened(feedback) || guessCount == 10){
            break;
        }

        input.clear();
    }

    if (guessCount == 10)
    {
        std::cout << "\nNo more guesses! Lock Box disabled" << std::endl;
    }

    else
    {
        std::cout << "\nLock Box opened!" << std::endl;
    }

}