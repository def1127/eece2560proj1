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

    lockBox secret(digits, range);

    std::vector<int> combination = secret.printCombination();

    for(int i: combination)
        cout << combination[i] << " ";

    return 0;

}