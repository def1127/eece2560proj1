/********************************************************
 * Filename: ClientFeedback.h
 * Purpose: Declares an interface for the ClientFeedback
 * class providing data and the necessary operations
*/

/* System Libraries */
#include <vector>
#include <iostream>

/* User Libraries */
#include "LockBox.h"


#ifndef  _CLIENTFEEDBACK
#define  _CLIENTFEEDBACK


class ClientFeedback{
private:
    /**vector that stores the values provided
     * in response to the client's guess*/
    std::vector<int> responses;

public:

    /** Creates an instance of a ClientFeedback object with initialized response values of 0*/
    ClientFeedback();

    /** Function to set the response to a client's guess
     * @param incorrectResponse Value that holds the number of right digits in the wrong location
     * @param correctResponse Value that holds the number of right digits in the right location
     * @return None
     */
    void setResponse(int incorrectResponse, int correctResponse);

    /** Function to get the stored correctLocation and incorrectLocation
     * values from a lockBox object
     * @param None
     * @return vector of type int which holds the response to a client's guess
     */
    std::vector<int> getResponse() const;

    /** Global function that overloads the == operator to compare two lockBox objects
     * @param lhs the lockBox object that holds secret code
     * @param rhs the lockBox object that holds the client's guess
     * @return bool true if secret code and client guess code are equivalent, false otherwise
     */
    friend bool operator==(const ClientFeedback& lhs, const ClientFeedback& rhs);

    /** Global function that overloads the << operator and prints out a ClientFeedback object
     * @param ostr ostream object
     * @param feedback ClientFeedback object that holds the response to a client's guess
     * @return ostream object, allows for response to be printed
     */
    friend std::ostream& operator<<(std::ostream& ostr, const ClientFeedback& feedback);

};


#endif
