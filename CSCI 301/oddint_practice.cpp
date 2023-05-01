#include <iostream>

using namespace std;

/*@problem: Create a function that takes an array and 
finds the integer which appears an odd number of times*/


int getCount(int num, int arr[], int length) {
    int c = 0;

    for(int i = 0; i < length; ++i) {
       if(num == arr[i]){
        ++c;
       }
    }

    return c;
}
int findOdd(int arr[], int length){
    int num = 0;
    

    for(int i = 0; i < length; ++i) {
       if(getCount(arr[i], arr, length) % 2 != 0){
            num = arr[i];
            return num;
       }
    }
    
}

int main () {


    int arr[13] = {20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5 };
    int arr2[11] = {1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5};

    cout << "Odd int for array 1 is: " << findOdd(arr,13) << endl;
    cout << "Odd int for array 2 is: " << findOdd(arr2,11) << endl;


    return 0;
}