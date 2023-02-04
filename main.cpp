#include <iostream>
#include "SmartClient.h"
#include "LockBox.h"
#include "ClientFeedback.h"
#include <chrono>
#include <thread>

using namespace std;

int main()
{

    int digits, range;

    std::vector<int> input;


    cout << "Enter number of digits in combination: ";
    cin >> digits;

    if(cin.fail())
    {
        return 1;
    }

    cout << "\nEnter range of digits: ";
    cin >> range;

    if(cin.fail())
    {
        return 1;
    }

    cout << "\nGenerating combination...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));


    SmartClient instance(digits,range);
    instance.openLockBox();

    return 0;

}