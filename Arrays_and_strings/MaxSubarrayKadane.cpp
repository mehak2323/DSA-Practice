/* MAXIMUM SUBARRAY (KADANE'S ALGORITHM)

Given an integer array nums, find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

Link: https://leetcode.com/problems/maximum-subarray/
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //Kadane's algorithm
        int n=nums.size(), sum=0, maxsf = nums[0] ;
        for(int i=0; i<nums.size(); i++)
        {
            //find sum of continuous elements where positive sum
            sum+=nums[i];
            //update maximum sum so far, considering positive sum
            if(sum>maxsf)
                maxsf=sum;
            //ignore subarrays with negative sum
            if(sum<0)
                sum=0;
        }

        return maxsf;

        /*
        //Without using 3rd for loop, optimizing first method O(n^2)

        int n=nums.size(), sum, maxsf = INT_MIN ;
        for(int i=0; i<n; i++)
        {
            sum=0;
            for(int j=i; j<n; j++)
            {
                sum+=nums[j];
                if(maxsf<sum )
                    maxsf=sum;
            }
        }
        return maxsf;
        */

        /*
        //3 for loops, TLE, obviously, but correct sol O(n^3)

        int n=nums.size(), sum, maxsf = INT_MIN ;
        //1st loop for starting point of subarray
        for(int i=0; i<n; i++)
        {
            //loop for ending of subarray
            for(int j=i; j<n; j++)
            {
                sum=0;
                //loop to find sum of eleemnts in current subarray
                for(int k=i; k<=j; k++)
                {
                    sum+=nums[k];
                }
                if(maxsf<sum )
                    maxsf=sum;
            }
        }
        return maxsf;
        */
    }
};
/*
Test Cases:
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.

    Input: nums = [1]
    Output: 1

    Input: nums = [5,4,-1,7,8]
    Output: 23

Time Complexity: O(n)
Space Complexity: O(1)
*/
