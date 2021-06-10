/* SORT COLORS
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects
of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Link: https://leetcode.com/problems/sort-colors/
*/

//Method 1: Count sort (2*O(n))
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int zeroes=0, ones=0,twos=0;
        //count no. of ones, twos and threes
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
                zeroes++;
            else if(nums[i]==1)
                ones++;
            else
                twos++;
        }
        //Fill total zeroes then ones then twos
        for(int i=0; i<nums.size(); i++)
        {
            if(zeroes)
            {
                nums[i]=0;
                zeroes--;
            }
            else if(ones)
            {
                nums[i]=1;
                ones--;
            }
            else
            {
                nums[i]=2;
                twos--;
            }
        }
    }
};
//Method 2: Dutch National flag algorithm (O(n))
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low=0, mid=0, high=nums.size()-1;

        //three pointers, left side of low to have 0s,
        //right side of high to have 2s, mid to traverse
        while(mid<=high)
        {
            switch(nums[mid])
            {
                case 0:
                    swap(nums[low], nums[mid]);
                    mid++; low++;
                    break;

                case 1:
                    mid++;
                    break;

                case 2:
                    swap(nums[mid], nums[high]);
                    high--;
                    break;
            }
        }
    }
};
/*
Test Cases:
    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

    Input: nums = [2,0,1]
    Output: [0,1,2]

    Input: nums = [0]
    Output: [0]

    Input: nums = [1]
    Output: [1]

Time Complexity: O(n) for both, method 2 faster
Space Complexity: O(1)
*/
