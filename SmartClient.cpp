
#include "LockBox.h"
#include "ClientFeedback.h"
#include "SmartClient.h"
#include <algorithm>

/* Constructs a smart client object that generates a lockbox object with inputs (5,10). */
SmartClient::SmartClient()
{
    lockBox newBox(5,10);
    secretBox = newBox;
}

/* Constructs a smart client object that generates a lockbox object with inputs (n,m). */
SmartClient::SmartClient(int n, int m)
{
    lockBox newBox(n,m);
    secretBox = newBox;
}

/* Prints secret combination stored in secretBox. */
void SmartClient::printSecretCode()
{
    std::vector<int> combination = secretBox.printCombination();
    for(int i: combination)
        std::cout << combination[i] << " ";
}

/* Returns a lock box object with the combination of the input int vector. */
lockBox SmartClient::clientGuess(std::vector<int> input) const
{
    return lockBox(input);
}

/* Returns a client feedback object that stores the guesses matching input lockbox. */
ClientFeedback SmartClient::getFeedback(lockBox box)
{
    ClientFeedback feedback;//need to be able to setResponse;
    feedback.setResponse(secretBox.correctLocation(box), secretBox.incorrectLocation(box));
    return feedback;
}

/* Checks to see if feedback object guesses show that lockbox is opened (0, non-zero). */
bool SmartClient::isOpened(const ClientFeedback& feedback) const
{
    //check if none are incorrectly placed AND that number of correctly guessed is nonzero
    return feedback.getResponse()[1] == 0 && feedback.getResponse()[0] != 0;
}

/* Initializes lockbox with random combination and lets user guess combination through console. */
/* After ten guesses the guessing feature becomes disabled. */
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
        for (iter = input.begin(); iter != input.end(); iter++)
            std::reverse(input.begin(), input.end());

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