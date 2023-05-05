#include <iostream>
#include <string>
#include <cmath>
#include <tgmath.h>

// Beck Christensen, Fri May 5th, Practice program

/*@problem:
A left-truncatable prime is a prime number that contains no 0 digits and, when the first digit is successively removed, the result is always prime.

A right-truncatable prime is a prime number that contains no 0 digits and, when the last digit is successively removed, the result is always prime.

Create a function that takes an integer as an argument and:

If the integer is only a left-truncatable prime, return "left".
If the integer is only a right-truncatable prime, return "right".
If the integer is both, return "both".
Otherwise, return "none".*/

using namespace std;

/*given a number and index, this function will use modular
arithmatic to remove the value of the index from the given number
Example: input (123, 2), output (13) */
int removeDigit(int num, int pos)
{
    int p = pow(10, pos);
    int b = pow(10, pos + 1);

    return (num - (num % b)) / 10 + num % p;
}

/*returns the number of factors for a given number*/
bool isPrime(int num)
{

    int i;
    int factors = 0;

    // 1 isnt a prime number
    if (num == 1)
    {
        return false;
    }

    for (i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            ++factors;
        }
    }

    return factors < 3;
}

/*given a number, this function will use logorithmic functions
to return the number of digits in a number*/
int count_digit(int num)
{
    return int(log10(num) + 1);
}

/*given a number, this function checks if the number
can be used for truncation. A number is truncatable
if it contains no zero digits*/
void checkNum(int num)
{

    int numDigits = count_digit(num);
    int newNum;

    try
    {
        for (int i = 0; i < numDigits; ++i)
        {
            newNum = num / pow(10, i);
            if (newNum % 10 == 0)
            {
                throw 505;
            }
        }
    }

    catch (...)
    {
        cout << "Error: Contains a zero digit" << endl;
        exit(EXIT_SUCCESS);
    }
}

/*given a number this function checks if the number is left-truncatable*/
bool checkLeft(int num)
{

    int numDigits = count_digit(num);
    int primeCount = 0;
    int newNum;

    for (int i = numDigits; i > 0; --i)
    {
        newNum = removeDigit(num, i);
        num = newNum;
        if (isPrime(newNum))
        {
            ++primeCount;
        }
    }

    return primeCount == numDigits;
}

/*given a number this function checks if the number is right-truncatable*/
bool checkRight(int num)
{

    int numDigits = count_digit(num);
    int primeCount = 0;

    for (int i = 0; i < numDigits; ++i)
    {
        int newNum = num / (pow(10, i));
        if (isPrime(newNum))
        {
            ++primeCount;
        }
    }

    return primeCount == numDigits;
}

/*Returns the string value of a boolean input
1 = True, 0 = False*/
string btos(bool x)
{
    if (x)
        return "True";
    return "False";
}

/*given a number this function returns "left", "right",
or "both" depending on if its left or right truncatable
or both*/
string truncatable(int num)
{
    if (checkLeft(num))
    {
        if (checkRight(num))
        {
            return "both";
        }

        return "left";
    }
    else if (checkRight(num))
    {
        if (checkLeft(num))
        {
            return "both";
        }

        return "right";
    }
    else
    {
        return "none";
    }
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    checkNum(num);

    if (truncatable(num) == "left" || truncatable(num) == "right")
    {
        cout << "Your number is " << truncatable(num) << "-truncatable" << endl;
    }
    else if (truncatable(num) == "both")
    {
        cout << "Your number is truncatable both ways" << endl;
    }
    else
    {
        cout << "Your number is not a truncatable prime" << endl;
    }

    return 0;
}