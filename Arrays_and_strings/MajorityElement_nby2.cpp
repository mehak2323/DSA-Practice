/* MAJORITY ELEMENT

Given an array nums of size n, return the majority element.
The majority element is the element that appears more than floor(n / 2) times.
You may assume that the majority element always exists in the array.

Link: https://leetcode.com/problems/majority-element/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int max_count=nums.size()/2;
        int elem=0;

        unordered_map<int,int> counts;
        for(int i: nums)
        {
            //store count of each element
            counts[i]++;
            //if count more than max so far, update index
            if(counts[i]>max_count)
                elem=i;
        }
        return elem;
    }
};
/*
Test Cases:
    Input: nums = [3,2,3]
    Output: 3

    Input: nums = [2,2,1,1,1,2,2]
    Output: 2

Time Complexity: O(n)
Space Complexity: O(n)
*/
