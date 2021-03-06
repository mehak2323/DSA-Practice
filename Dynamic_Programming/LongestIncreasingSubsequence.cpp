/* LONGEST INCREASING SUBSEQUENCE
Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements
without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of
the array [0,3,1,6,2,2,7].

Link: https://leetcode.com/problems/longest-increasing-subsequence/
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n= nums.size();
        vector<int> dp(n,1);

        int max_val=1;
        //loop for all elements from second to store the longest
        //increasing subsequence before that element
        for(int i=1; i<n; i++)
        {
            //for all values before current element see if there is increasing order
            //and if the lis of one of the previous element is bigger than current
            for(int j=0; j<i; j++)
            {
                if(nums[j]<nums[i] && dp[i]<=dp[j])
                    dp[i]=dp[j]+1;
            }
            //to find maximum lis from each elements individual lis
            if(dp[i]>max_val)
                max_val=dp[i];
        }
        return max_val;
    }
};

/*
Test Cases:
    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

    Input: nums = [0,1,0,3,2,3]
    Output: 4

    Input: nums = [7,7,7,7,7,7,7]
    Output: 1

Time Complexity: O(n^2)
Space Complexity: O(n)
*/
