#include <vector>

#ifndef _LOCKBOX
#define _LOCKBOX

class lockBox
{

public:
    /* Returns the number of digits (int) where the numbers and positions match in input lockbox and in object. */
    /* @param input is the input lockbox which contains an input combination for comparision */
    /* @return returns the number of positions where the combination of this lockbox and the input are the same. */
    int correctLocation(lockBox input);
    /* Returns the number of singular ints (int) that are in input lockbox that are also in object in the incorrect location. */
    /* @param input is the input lockbox which contains an input combination for comparision */
    /* @return returns the number of digits in the input that are in the lockbock combo but not in the correct location. */
    int incorrectLocation(lockBox input);
    /* Constructs a lockbox object with a combination of length three (with each digit between 0 and 9).*/
    lockBox();
    /* Constructs a lockbox object with a combination of n length (with each digit between 0 and m).*/
    /* @param n is the number of digits in combination. */
    /* @param m is the upper limit that each digit can be. */
    lockBox(int n, int m);
    /* Construct a lockbox object with combination that matches int vector. */
    /* @param input is the combination for lockbox to store. */
    lockBox(std::vector<int> input);
    /* Prints out the lockboc combination in console.*/
    /* @return the combination stored in lockbox as a int vector. */
    std::vector<int> printCombination();

private:
    /* Combination stored as private int vector. */
    std::vector<int> combination;
    /* Generates a combination of random digits (int vector) of length n with each digit in range 0 - m. */
    /* @param n is the length of the combination. */
    /* @param m is the upper limit that each digit can be. */
    /* @return a int vector of length n with each digit being randomly between 0 and m. */
    std::vector<int> generateCombination(int n, int m);

};

#endif