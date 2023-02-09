/********************************************************
 * Filename: ClientFeedback.cpp
 * Purpose: Implements the ClientFeedback class methods
*/

/* System Libraries */
#include <vector>

/* User Libraries */
#include "ClientFeedback.h"
#include "LockBox.h"

/** Creates an instance of a ClientFeedback object with initialized response values of 0
 */
ClientFeedback::ClientFeedback()
{
    responses = {0,0};
}

/** Function to set the response to a client's guess
 * @param incorrectResponse Value that holds the number of right digits in the wrong location
 * @param correctResponse Value that holds the number of right digits in the right location
 * @return None
 */
void ClientFeedback::setResponse(int correctResponse, int incorrectResponse)
{
    std::vector<int> v{correctResponse,incorrectResponse};
    responses = v;
}

/** Function to get the stored correctLocation and incorrectLocation
 * values from a lockBox object
 * @param None
 * @return vector of type int which holds the response to a client's guess
 */
std::vector<int> ClientFeedback::getResponse() const
{
    return responses;
}

/** Global function that overloads the == operator to compare two lockBox objects
 * @param lhs the lockBox object that holds secret code
 * @param rhs the lockBox object that holds the client's guess
 * @return bool true if secret code and client guess code are equivalent, false otherwise
 */
bool operator==(const ClientFeedback& lhs, const ClientFeedback& rhs)
{
    return lhs.responses == rhs.responses;
}

/** Global function that overloads the << operator and prints out a ClientFeedback object
 * @param ostr ostream object
 * @param feedback ClientFeedback object that holds the response to a client's guess
 * @return ostream object, allows for response to be printed
 */
std::ostream& operator<<(std::ostream& ostr, const ClientFeedback& feedback)
{
    ostr << "Correct Location # : " << feedback.responses[0] << ", Incorrect Location # : " << feedback.responses[1];
    return ostr;
}

