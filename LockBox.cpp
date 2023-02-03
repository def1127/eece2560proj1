#include "LockBox.h"
#include <ctime>
#include <random>
#include <algorithm>
#include <iostream>

lockBox::lockBox()
{
    //default constructor
    combination = generateCombination(3, 9);

}

lockBox::lockBox(int n, int m)
{
    
    combination = generateCombination(n, m);

}

lockBox::lockBox(std::vector<int> input)
{

    combination = input;

}

std::vector<int> lockBox::generateCombination(int n, int m)
{

    std::vector<int> comb;

    srand( (unsigned)time(0) );

    for(int i = 0; i < n; i++)
    {
        comb.push_back(((rand())%m));

    }

    return comb;

} // closes combination generator function

int lockBox::correctLocation(lockBox input)
{

    int count = 0;

    for(int i = 0; i < combination.size(); i++){

        if(combination[i] == input.combination[i])
        {
            count++;
        }

    }

    return count;

} // closes correct location function

std::vector<int> lockBox::printCombination()
{
        return combination;

}

int lockBox::incorrectLocation(lockBox input)
{

    int count = 0;
    std::vector<int> alreadyCounted;

    for(int i = 0; i < combination.size(); i++)
    {

        alreadyCounted.push_back(combination[i]);

        for(int j = 0; j < input.combination.size(); j++)
        {
            if(combination[i] == input.combination[j])
            {
                if(std::find(alreadyCounted.begin(), alreadyCounted.end(), combination[i]) != alreadyCounted.end())
                {
                    count++;
                }
            }
        }

    }

    return count - correctLocation(input);

}