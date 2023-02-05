#include <vector>

#ifndef _LOCKBOX
#define _LOCKBOX

class lockBox
{

public:
    /* Returns the number of digits (int) where the numbers and positions match in input lockbox and in object. */
    int correctLocation(lockBox input);
    /* Returns the number of singular ints (int) that are in input lockbox that are also in object in the incorrect location. */
    int incorrectLocation(lockBox input);
    /* Constructs a lockbox object with a combination of length three (with each digit between 0 and 9).*/
    lockBox();
    /* Constructs a lockbox object with a combination of n length (with each digit between 0 and m).*/
    lockBox(int n, int m);
    /* Construct a lockbox object with combination that matches int vector. */
    lockBox(std::vector<int> input);
    /* Prints out the lockboc combination in console.*/
    std::vector<int> printCombination();

private:
    /* Combination stored as private int vector. */
    std::vector<int> combination;
    /* Generates a combination of random digits (int vector) of length n with each digit in range 0 - m. */
    std::vector<int> generateCombination(int n, int m);

};

#endif