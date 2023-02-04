
#include "LockBox.h"
#include "ClientFeedback.h"
#include <vector>
#include <iostream>

#ifndef  _SMARTCLIENT
#define  _SMARTCLIENT


class SmartClient{
private:
    lockBox secretBox;
public:
    SmartClient();
    SmartClient(int n, int m);
    void printSecretCode();
    lockBox clientGuess(std::vector<int> input) const;
    ClientFeedback getFeedback(lockBox box);
    bool isOpened(const ClientFeedback& feedback) const;
    void openLockBox();

};


#endif
