/* REMOVE DUPLICATES FROM SORTED ARRAY

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place
such that each unique element appears only once. The relative order of the elements should
be kept the same.

Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n=nums.size();

        //If empty return 0
        if(n==0)
            return 0;

        //Index of unique elements
        int k=0;

        //Iterate for rest of the array
        for(int i=1; i<n; i++)
        {
            //If a new number is encountered,
            //store it in k index and increase k
            if(nums[k]!=nums[i])
            {
                nums[k+1]=nums[i];
                k++;
            }
        }

        //return count of unique elements
        return k+1;
    }
};
/*
Test Cases:

    Input: nums = [1,1,2]
    Output: 2, nums = [1,2,_]
    Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
    It does not matter what you leave beyond the returned k (hence they are underscores).

    Input: nums = [0,0,1,1,1,2,2,3,3,4]
    Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
    Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
    It does not matter what you leave beyond the returned k (hence they are underscores).

Time Complexity: O(n)
Space Complexity: O(1)
*/
