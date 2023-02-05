#include "LockBox.h"
#include <ctime>
#include <random>
#include <algorithm>
#include <iostream>

/* Constructs a lockbox object with a combination of length three (with each digit between 0 and 9).*/
lockBox::lockBox()
{
    //default constructor
    combination = generateCombination(3, 9);

}

/* Constructs a lockbox object with a combination of n length (with each digit between 0 and m).*/
lockBox::lockBox(int n, int m)
{

    combination = generateCombination(n, m);

}

/* Construct a lockbox object with combination that matches int vector. */
lockBox::lockBox(std::vector<int> input)
{

    combination = input;

}

/* Generates a combination of random digits (int vector) of length n with each digit in range 0 - m. */
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

/* Returns the number of digits (int) where the numbers and positions match in input lockbox and in object. */
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

/* Prints out the lockboc combination in console.*/
std::vector<int> lockBox::printCombination()
{
    return combination;

}

/* Returns the number of singular ints (int) that are in input lockbox that are also in object in the incorrect location. */
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