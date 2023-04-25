/*
@Project 3 kSmallest
@author Beck Christensen
@starID rg6291gh
@duedate 2.13.2022
@instructor Jie Meichsner 
*/

#include <iostream>

using namespace std;

int partition(int *a, int start, int end)
{
	
int pivot = a[start], p1 = start + 1, i, temp;
for (i = start + 1; i <= end; i++)
{
if (a[i] < pivot) {

if (i != p1) {
	
temp = a[p1];
a[p1] = a[i];
a[i] = temp;

}
p1++;
}
}
if (start <= end) //special case
{
a[start] = a[p1 - 1];
a[p1 - 1] = pivot;
}
return p1 - 1;
}

 /** 
     * This method finds the kths smallest element in a given array by using quicksort
     * @param *arr the given array
     * @param l the leftmost index 
	   @param r the rightmost index
	   @param k the kth element chosen
     * @return the kth smallest element in the array
     */  
int kthSmallest(int *arr, int l, int r, int k)
{

if (k > 0 && k <= r - l + 1) {

int index = partition(arr, l, r);

// If position is same as k

if (index - l == k - 1) {

return arr[index];
}
// for left subarray

if (index - l > k - 1) {

return kthSmallest(arr, l, index - 1, k);
}
// Else recur for right subarray

return kthSmallest(arr, index + 1, r,
k - index + l - 1);
}
return INT_MAX;
}

// Driver program to test above methods

int main()
{
int *arr = new int[7]{10, 4, 5, 8, 6, 11, 26};
int n = 7;
//test case where kth small is in S1
cout << "The Array: 10, 4, 5, 8, 6, 11, 26" << endl;
cout << "3rd smallest element is "
<< kthSmallest(arr, 0, n - 1, 3) << endl;
//test case where kth small is the pivot
int *arr2 = new int[7]{1, 4, 12, 8, 6, 11, 26};
cout << "The Array: 1, 4, 12, 8, 6, 11, 26" << endl;
cout << "1st smallest element is "
<< kthSmallest(arr2, 0, n - 1, 1) << endl;
//test case where kth small is in S2
int *arr3 = new int[7]{1, 5, 4, 8, 6, 11, 26};
cout << "The Array: 1, 5, 4, 8, 6, 11, 26" << endl;
cout << "6th smallest element is "
<< kthSmallest(arr3, 0, n - 1, 6) << endl;
return 0;

}