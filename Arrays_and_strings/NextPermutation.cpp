/* NEXT PERMUTATION

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
The replacement must be in place and use only constant extra memory.

Link: https://leetcode.com/problems/next-permutation/
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        //eg- 243 5 98661 =>  243 6 15689
        int n = nums.size() , i;

        //Find if descending no. from back, swap with
        //smallest greater than it in later array

        //traverse from back to front
        for(i= n-1; i>0; i--)
        {
            //if a descending element found
            if(nums[i-1]<nums[i])
            {
                int minInd=i, j;
                //find smallest greater than descending in further array
                for(j=i; j<n; j++)
                {
                    if(nums[j]<=nums[minInd] && nums[j]>nums[i-1])
                    {
                        minInd=j;
                    }
                }
                swap(nums[i-1],nums[minInd]);
                //after swap break, i will be index till which we reverse
                break;
            }
        }

        //Reverse array till descending element position, Or the whole
        for(int last=n-1 ; i<=last; i++ ,last--)
        {
            swap(nums[i], nums[last]);
        }
    }
};
/*
Test Cases:

    Input: nums = [1,2,3]
    Output: [1,3,2]

    Input: nums = [3,2,1]
    Output: [1,2,3]

    Input: nums = [1,1,5]
    Output: [1,5,1]

    Input: nums = [1]
    Output: [1]

Time Complexity: O(n) //2n to find smallest greater + n to reverse
Space Complexity: O(1)
*/
