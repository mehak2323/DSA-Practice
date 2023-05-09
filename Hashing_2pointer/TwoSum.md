### Two Sum
[Problem Link](https://leetcode.com/problems/two-sum/description/) |
[Video Link](https://www.youtube.com/watch?v=UXDSeD9mN-k&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=19)

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```
Example 2:
```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```
Example 3:
```
Input: nums = [3,3], target = 6
Output: [0,1]
```

### Solution
Java:
``` java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        HashMap<Integer,Integer> temp = new HashMap<>();

        // Traverse in array
        for(int i=0; i<nums.length; i++){
            //If complement num (target - current ind) exists in map/was found before
            if(temp.containsKey(target-nums[i])){
                //Take current and compement index from map and return ans
                ans[0] = i;
                ans[1] = temp.get(target-nums[i]);
                return ans;
            }
            //Else 
            else
                temp.put(nums[i],i);
        }
        return ans;
    }
}
```
Cpp:
``` cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        //hashing
        unordered_map<int,int> umap;
        int remaining;
        
        for(int i=0; i<nums.size(); i++){
            remaining = target-nums[i];
            
            //If remaining already present
            if(umap.find(remaining) == umap.end()){
                ans[0]= pair[remaining].second;
                ans[1]= nums[i];
                break;
            }
            //Else add current element 
            else{
                pair[nums[i]]=i;
            }
        }
        
        //n square
        /*
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    ans[0]=i;
                    ans[1]=j;
                    break;
                }
            }
        }
        */
        
        return ans;
    }
};

//Eg: nums = [3,2,4], target = 6
//map=[(3,0),(2,1),(4,2)]
```

### Approach:
- n squared solution is: first loop to traverse, second to search for another elem whose sum with first equals target.
- While we are iterating and inserting elements into the hash table, we also look back to check if current element's complement already exists in the hash table. 
If it exists, we have found a solution and return the indices immediately.


`Time: O(n)` | 
`Space: O(n) ` 
