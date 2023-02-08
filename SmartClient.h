
#include "LockBox.h"
#include "ClientFeedback.h"
#include <vector>
#include <iostream>

#ifndef  _SMARTCLIENT
#define  _SMARTCLIENT


class SmartClient{
private:
    /* Private lockbox object that stores generated combination. */
    lockBox secretBox;
    int comboLength;
public:
    /* Constructs a smart client object that generates a lockbox object with inputs (5,10). */
    SmartClient();
    /* Constructs a smart client object that generates a lockbox object with inputs (n,m). */
    SmartClient(int n, int m);
    /* Prints secret combination stored in secretBox. */
    void printSecretCode();
    /* Returns a lock box object with the combination of the input int vector. */
    lockBox clientGuess(std::vector<int> input) const;
    /* Returns a client feedback object that stores the guesses matching input lockbox. */
    ClientFeedback getFeedback(lockBox box);
    /* Checks to see if feedback object guesses show that lockbox is opened (0, non-zero). */
    bool isOpened(const ClientFeedback& feedback) const;
    /* Initializes lockbox with random combination and lets user guess combination through console. */
    /* After ten guesses the guessing feature becomes disabled. */
    void openLockBox();
};


#endif
