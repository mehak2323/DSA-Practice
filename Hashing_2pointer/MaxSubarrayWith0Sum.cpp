/* LARGEST SUBARRAY WITH ZERO SUM

Given an array having both positive and negative integers. The task is to
compute the length of the largest subarray with sum 0.

Link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

int maxLen(int A[], int n)
{
    int sum=0, length=0, lsf=0;
    unordered_map<int, int> ssf; //sum,index

    for(int i=0; i<n; i++)
    {
        sum+=A[i]; //prefix sum

        //if sum so far is zero
        if(sum==0)
            lsf=i+1;

        //if sum so far already present
        //__s__+__0__ = s ,find length whose sum zero
        else if(ssf.find(sum)!=ssf.end())
            lsf = i - ssf.find(sum)->second;

        //store current sum,index in map
        else
            ssf[sum] = i;

        //Check if it's bigger than previous max length
        if(lsf>length)
            length= lsf;
    }
    return length;
}

/*
Test Case:
    Input:
        N = 8
        A[] = {15,-2,2,-8,1,7,10,23}
    Output: 5
    Explanation: The largest subarray with
        sum 0 will be -2 2 -8 1 7.

Time Complexity: O(n log n) //log n to find elem if not present
Space Complexity: O(n)
*/
