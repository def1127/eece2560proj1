
#include "LockBox.h"
#include <vector>
#include <iostream>

#ifndef  _CLIENTFEEDBACK
#define  _CLIENTFEEDBACK


class ClientFeedback{
private:
    /**vector that stores the values provided
     * in response to the client's guess*/
    std::vector<int> responses;

public:
    /* Constructs a client feedback object that stores a base null int vector of {0,0} of responses. */
    ClientFeedback();
    /* Set the responses int vector to the {incorrectResponse, correctResponse}. */
    void setResponse(int incorrectResponse, int correctResponse);
    /* Returns the response int vector stored in client feedback object. */
    std::vector<int> getResponse() const;
    /* Overrides == operator for proper comparision between client feedback objects. */
    friend bool operator==(const ClientFeedback& lhs, const ClientFeedback& rhs);
    /* Overrides << operator for proper printing (in cout) of client feedback objects. */
    friend std::ostream& operator<<(std::ostream& ostr, const ClientFeedback& feedback);

};


#endif


