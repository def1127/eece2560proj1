
#include "LockBox.h"
#include "ClientFeedback.h"
#include "SmartClient.h"
#include <algorithm>


SmartClient::SmartClient()
{
    lockBox newBox(5,10);
    secretBox = newBox;

}

SmartClient::SmartClient(int n, int m)
{
    lockBox newBox(n,m);
    secretBox = newBox;
}

void SmartClient::printSecretCode()
{
    std::vector<int> combination = secretBox.printCombination();
    for(int i: combination)
        std::cout << combination[i] << " ";
}

lockBox SmartClient::clientGuess(std::vector<int> input) const
{
    return input;
}

ClientFeedback SmartClient::getFeedback(lockBox box)
{
    ClientFeedback feedback;//need to be able to setResponse;
    feedback.setResponse(secretBox.correctLocation(box), secretBox.incorrectLocation(box));
    return feedback;
}

bool SmartClient::isOpened(const ClientFeedback& feedback) const
{
    //check if none are incorrectly placed AND that number of correctly guessed is nonzero
    return feedback.getResponse()[1] == 0 && feedback.getResponse()[0] != 0;
}
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