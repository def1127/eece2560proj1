#include "LockBox.h"
#include <ctime>
#include <random>
#include <algorithm>

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
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, m); // define the range

    distr(gen);

    for(int i = 0; i < n; i++)
    {
        comb.push_back(distr(gen));

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