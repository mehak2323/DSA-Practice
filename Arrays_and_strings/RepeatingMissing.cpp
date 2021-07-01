/* REPEATING AND MISSING

Given an unsorted array of size n. Array elements are in the range from 1 to n. One number
from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.

Link: https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
*/

//NOT WORKING, Tried my best, runs example cases
class Solution{
public:
    //Sol: we need to make two equations difference of sum of n terms expected- of array and of
    //squared n terms expected - of array. this gives two equations Exp-Org , (Exp+Org)(Exp-Org), solve
    int *findTwoElement(int *arr, int n) {

        int * ans= new int [2]; //twice,missing

        long long squareSum=((n)*(n+1)*(2*n+1))/6;
        long long sumOfN=((n)*(n+1))/2;


        for(int i=0; i<n; i++)
        {
            sumOfN-= arr[i]; //for x-y
            squareSum-= arr[i]*arr[i]; //for x^2 -y^2
        }

        ans[1]=((squareSum/sumOfN) + sumOfN )/2;
        ans[0]= ans[1] - sumOfN;

        /*
        // xplusy * xminusy (sumOfNOrg- sumOfN)  = x^2- y^2 (squareSumOrg - squareSum)
        xplusy = (squareSumOrg - squareSum) / (sumOfNOrg- sumOfN);

        //missing = 2*x , twice = xplusy - missing

        ans[1]= (xplusy + (sumOfNOrg- sumOfN) )/2;
        ans[0]= xplusy - ans[1];  */

        return ans;
    }
};
/*
Test Cases:
    Input: arr[] = {3, 1, 3}
    Output: Missing = 2, Repeating = 3
    Explanation: In the array,
    2 is missing and 3 occurs twice

    Input: arr[] = {4, 3, 6, 2, 1, 1}
    Output: Missing = 5, Repeating = 1

Time Complexity: O(n)
Space Complexity: O(1)
*/
