/* MAX CONSECUTIVE ONES

Given a binary array nums, return the maximum number of consecutive 1's in the array.

Link: https://leetcode.com/problems/max-consecutive-ones/
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int maxOnes=0, ones=0;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            //If one, increase length
            if(nums[i]==1 )
                ones++;
            //If not one, set length to 0
            else
                ones=0;
            //Check if curr length bigger than prev max
            if(ones>maxOnes)
                maxOnes=ones;
        }
        return maxOnes;
    }
};

/*
Test Cases:

    Input: nums = [1,1,0,1,1,1]
    Output: 3
    Explanation: The first two digits or the last three digits are consecutive 1's.
    The maximum number of consecutive 1's is 3.

    Input: nums = [1,0,1,1,0,1]
    Output: 2

Time Complexity: O(n)
Space Complexity: O(1)
*/
