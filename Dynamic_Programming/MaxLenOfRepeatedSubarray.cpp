/* MAXIMUM LENGTH OF REPEATED SUBARRAY

Given two integer arrays nums1 and nums2, return the maximum length
of a subarray that appears in both arrays.

Link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size();
        int m=nums2.size();
        //Make a dp array of 1 size bigger
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        //To store max length
        int ans=0;

        //loop for rows and columns other than 0th
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                //if elem same in both array,
                //take (len of subarrays before elem) +1
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j]= dp[i-1][j-1] + 1;
                //update our max len so far
                ans = max(dp[i][j],ans);
            }
        }
        return ans;

        /*
        //Wrong answer,tried anything

        int dp[n+1][m+1];
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(nums1[i]==nums2[j])
                    dp[i][j]= dp[i-1][j-1] + 1;

                //error to avoid
                else
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }

        //Important edge case
        // [0,1,1,1,1]
        // [1,0,1,0,1]
        //This ans:3, Expected: 2
        */

    }
};

/*
Test Case:
    Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
    Output: 3
    Explanation: The repeated subarray with maximum length is [3,2,1].

    Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
    Output: 5

Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/
