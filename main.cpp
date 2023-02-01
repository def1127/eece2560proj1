#include <iostream>
#include "ClientFeedback.h"
#include "SmartClient.h"
#include "LockBox.h"
#include <chrono>
#include <thread>

using namespace std;

int main()
{

    int digits, range;

    cout << "Enter number of digits in combination: ";
    cin >> digits;

    cout << "\nEnter range of digits: ";
    cin >> range;

    cout << "\nGenerating combination...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    lockBox secret(digits, range);

    return 0;

}