/* FIND DUPLICATE NUMBER IN ARRAY

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

Link: https://leetcode.com/problems/find-the-duplicate-number/
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        //Floyd's Tortoise and Hare (Cycle Detection)
        int slow=nums[0], fast= nums[0];

        //move to the index at current's value
        //using slow and fast pointers till they meet
        do
        {
            slow = nums[slow]; // one step
            fast= nums[nums[fast]]; //two steps

        }while(slow!=fast);

        //distance from collision point to duplicate and
        //starting to duplicate is same
        fast= nums[0];

        while(slow!=fast)
        {
            fast= nums[fast];
            slow= nums[slow];
        }
        //when both slow and fast meet, they meet at duplicate value, return it
        return slow;
    }
};
/*
Test Cases:

    Input: nums = [1,3,4,2,2]
    Output: 2

    Input: nums = [3,1,3,4,2]
    Output: 3

    Input: nums = [1,1]
    Output: 1

    Input: nums = [1,1,2]
    Output: 1

Time Complexity: O(n)
Space Complexity: O(1)
*/
