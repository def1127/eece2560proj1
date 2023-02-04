#include "LockBox.h"
#include <vector>
#include "ClientFeedback.h"

ClientFeedback::ClientFeedback()
{
    responses = {0,0};
}


void ClientFeedback::setResponse(int incorrectResponse, int correctResponse)
{
    std::vector<int> v{correctResponse,incorrectResponse};
    responses = v;
}


std::vector<int> ClientFeedback::getResponse() const
{
    return responses;
}


bool operator==(const ClientFeedback& lhs, const ClientFeedback& rhs)
{
    return lhs.responses == rhs.responses;
}


std::ostream& operator<<(std::ostream& ostr, const ClientFeedback& feedback)
{
    ostr << "Correct Location # : " << feedback.responses[0] << ", Incorrect Location # : " << feedback.responses[1];
    return ostr;
}

