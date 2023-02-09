/*********************************************************************************************
 * File name: SmartClient.h
 * Purpose: Declares an interface for the SmartClient class
 * providing data and necessary operations
 */

/* User Libraries */
#include "LockBox.h"
#include "ClientFeedback.h"

/* System Libraries */
#include <vector>
#include <iostream>


#ifndef  _SMARTCLIENT
#define  _SMARTCLIENT


class SmartClient{
private:
    /* Private lockBox object that stores generated combination. */
    lockBox secretBox;
    int comboLength;
public:
    /**Constructs a smart client object that generates a lockBox object with inputs (5,10)
    * @post A new smart client object is created
    */
    SmartClient();

    /**Constructs a smart client object that generates a lockBox object with inputs (5,10)
     * @post A new smart client object is created
     * @param n The length value for the combination
     * @param m The range value for the combination
     */
    SmartClient(int n, int m);

    /**Prints secret combination stored in secretBox */
    void printSecretCode();

    /**Returns a lock box object with the combination of the input int vector.
    * @param input A vector of type integer which stores the client's guess
    * @return lockBox object which stores the client's guess*/
    lockBox clientGuess(std::vector<int> input) const;

    /** Returns a client feedback object that stores the guesses matching input lockbox.
    * @param box A lockBox object
    * @return ClientFeedback object which stores the response to a client's guess*/
    ClientFeedback getFeedback(lockBox box);

    /** Checks to see if feedback object guesses show that lockBox is opened (0, non-zero).
    * @param feedback reference to the memory location in which ClientFeedback object is stored*/
    bool isOpened(const ClientFeedback& feedback) const;

    /** Initializes lockBox with random combination and lets user guess combination through console.
    * After ten guesses the guessing feature becomes disabled.
    * @param None
    * @return None
    * */
    void openLockBox();
};


#endif
