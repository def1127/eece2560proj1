
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

    ClientFeedback();
    void setResponse(int incorrectResponse, int correctResponse);
    std::vector<int> getResponse() const;
    friend bool operator==(const ClientFeedback& lhs, const ClientFeedback& rhs);
    friend std::ostream& operator<<(std::ostream& ostr, const ClientFeedback& feedback);

};


#endif


