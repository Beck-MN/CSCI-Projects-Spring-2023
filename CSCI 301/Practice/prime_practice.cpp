#include <iostream>
#define MAX 100

using namespace std;

/*@problem: list the first 100 prime numbers,
 make it as fast as possible*/

int c = 0;
int n = 2;

//returns the number of factors for a given number
int factor(int num) {

    int i;
    int factors = 0;

    for(i = 1; i <= num; i++) {
        if(num % i == 0) {
            ++factors;
        }
    }

    return factors;
}

int main () {

    while (c <= MAX) {
        if(n % 2 > 0 && n != 2) {
            if(factor(n) < 3) {
                cout << n << endl;
                ++c;
            }
        }
        ++n;
    }
    return 0;
}