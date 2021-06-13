/* MINIMUM SUM OF TWO NUMBERS FORMED FROM DIGITS OF AN ARRAY

Given an array of digits (values are from 0 to 9), find the minimum possible sum
of two numbers formed from digits of the array. All digits of given array must be
used to form the two numbers.

Link: https://www.geeksforgeeks.org/minimum-sum-two-numbers-formed-digits-array/
*/

#include<bits/stdc++.h>
using namespace std;

int minSumNumbers(int digits[], int n)
{
    //two arrays for digits of first and second numbers
    int first[n], second[n];
    int j=0, k=0;
    //sort them to get minimum values
    sort(digits,digits+n);
    //loop over array
    for(int i=0; i<n; i++)
    {
        //add digits at even places to second number
        if((i+1)%2==0)
        {
            second[j]=digits[i];
            j++;
        }
        //add digits at odd place to first number
        else
        {
            first[k]=digits[i];
            k++;
        }
    }
    //make numbers out of digits
    int num1=0,num2=0;
    //loop over first number
    for(int i=0; i<k; i++)
    {
        //multiply number so far by 10 to add
        //current digit in ones place (20<=2)
        num1 *= 10;
        num1 += first[i];
    }
    //same for second number
    for(int i=0; i<j; i++)
    {
        num2 *= 10;
        num2 += second[i];
    }
    return num1+num2;
}
int main()
{
    int digits[]={5, 3, 0, 7, 4}; //6, 8, 4, 5, 2, 3
    int n=sizeof(digits)/sizeof(digits[0]);
    cout<<minSumNumbers(digits,n);
    return 0;
}
/*
Test Cases:
    Input: 5, 3, 0, 7, 4
    Output: 82 (047+35)
    Input: 6, 8, 4, 5, 2, 3
    Output: 604 (358+246)

Time Complexity: O(n)
Space Complexity: O(n)
*/
