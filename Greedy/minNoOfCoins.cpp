/* MINIMUM NUMBER OF COINS
Given a value V, if we want to make a change for V Rs, and we have an infinite supply of
each of the denominations in Indian currency, i.e., we have an infinite supply of
{ 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of
coins and/or notes needed to make the change?

Link: https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/
*/
#include<bits/stdc++.h>
using namespace std;

int minimumCoins(int V, int denom[],int n)
{
    int minCoin=0;
    //Sort the array of coins in decreasing order
    sort(denom, denom+n);

    // Traverse through all denomination
    for(int i=n-1; i>=0;i--)
    {
        // Find coins of current denomination
        while(V-denom[i]>=0)
        {
            V=V-denom[i];
            minCoin++;
        }
    }
    return minCoin;
}
int main()
{
    int V=121;
    int denom[]={ 1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n=sizeof(denom)/sizeof(denom[0]);
    cout<<minimumCoins(V,denom,n);
    return 0;
}
/*
Test Case:
    Input:
    V=121
    denom = 1, 2, 5, 10, 20, 50, 100, 500, 1000
    Output:
    coins=3
Time Complexity: O(n logn)
Space Complexity: O(1)
*/
