#include "LockBox.h"
#include <vector>
#include "ClientFeedback.h"

/* Constructs a client feedback object that stores a base null int vector of {0,0} of responses. */
ClientFeedback::ClientFeedback()
{
    responses = {0,0};
}

/* Set the responses int vector to the {incorrectResponse, correctResponse}. */
void ClientFeedback::setResponse(int correctResponse, int incorrectResponse)
{
    std::vector<int> v{correctResponse,incorrectResponse};
    responses = v;
}

/* Returns the response int vector stored in client feedback object. */
std::vector<int> ClientFeedback::getResponse() const
{
    return responses;
}

/* Overrides == operator for proper comparision between client feedback objects. */
bool operator==(const ClientFeedback& lhs, const ClientFeedback& rhs)
{
    return lhs.responses == rhs.responses;
}

/* Overrides << operator for proper printing (in cout) of client feedback objects. */
std::ostream& operator<<(std::ostream& ostr, const ClientFeedback& feedback)
{
    ostr << "Correct Location # : " << feedback.responses[0] << ", Incorrect Location # : " << feedback.responses[1];
    return ostr;
}

