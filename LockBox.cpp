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

        std::cout << "Combination: " << combination[i] << " Guess: " << input.combination[i] << std::endl; 

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
    std::vector<int> dupe_check;
    std::vector<int> combo_dupe = combination;
    std::vector<int> input_dupe = input.combination;

    // Removes values for correct val locations
    for (int i = 0; i < input_dupe.size(); i++){
        if (i < combo_dupe.size() && input_dupe[i] == combo_dupe[i]){
            input_dupe.erase(input_dupe.begin()+i);
            combo_dupe.erase(combo_dupe.begin()+i);
        }
    }

    //If both combination and input combination empty after removal, return 0 incorrect locations
    if (input_dupe.empty() && combo_dupe.empty()){
        return 0;
    }

    // Counting incorrect locations
    for (int i = 0; i < input_dupe.size(); i++){
        // Checks if element is not in dupe_check
        if (find(dupe_check.begin(),dupe_check.end(),input_dupe[i])==dupe_check.end()) {
            // Checks if element is in combination
            if ( find(combo_dupe.begin(),combo_dupe.end(),input_dupe[i])!=combo_dupe.end()){
                // Adds to incorrect location count if in combination
                count++;
            }
            // Adds element to dupe_check so no repeat counts
            dupe_check.push_back(input_dupe[i]);
        } 
    }

    return count;
}