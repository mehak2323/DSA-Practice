/* MAXIMIXE ARRAY SUM AFTER K NEGATIONS

Given an array of size n and a number k. We must modify array K number of times.
Here modify array means in each operation we can replace any array element arr[i] by -arr[i].
We need to perform this operation in such a way that after K operations, sum of array must be maximum?

Link: https://www.geeksforgeeks.org/maximize-array-sun-after-k-negation-operations/
*/
#include<bits/stdc++.h>
using namespace std;

int maxSumAfterK(int arr[], int n, int k)
{
    //find minimum value in case we need to negate a positive element
    int sum=0, minimum=abs(arr[0]);
    //loop over all elements
    for(int i=0;i<n;i++)
    {
        if(k<=0)
            break;
        //find minimum absolute value to negate a positive element
        if(abs(arr[i])<minimum)
            minimum=abs(arr[i]);
        //if element is negative add negation of element to max sum
        if(arr[i]<0)
        {
            sum+=arr[i]*(-1);
            k--;
        }
        //else add element to max sum
        else
            sum+=arr[i];
    }
    //if k remains after making negatives into positives
    if(k>0)
    {
        //only update if k is odd, else it'll turn back to positive
        if(k%2!=0)
            sum-=2*minimum;
    }
    return sum;
}
int main()
{
    int arr[] = { -3, -2, -1, 5, 6 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSumAfterK(arr, n, k);
    return 0;
}
/*
Test Cases:
    Input 1: arr[] = {-2, 0, 5, -1, 2}, K = 4
    Output 1: 10
    Explanation 1:
    1. Replace (-2) by -(-2), array becomes {2, 0, 5, -1, 2}
    2. Replace (-1) by -(-1), array becomes {2, 0, 5, 1, 2}
    3. Replace (0) by -(0), array becomes {2, 0, 5, 1, 2}
    4. Replace (0) by -(0), array becomes {2, 0, 5, 1, 2}

    Input 2: arr[] = {9, 8, 8, 5}, K = 3
    Output 2: 20

    Input 3: arr[]={-3, -2, -1, 5, 6}, K=4
    Output 3: 15

Time Complexity: O(n)
Space Complexity: O(1)
*/
