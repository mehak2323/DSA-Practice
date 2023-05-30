## Longest Substring Without Repeating Characters
[Leetcode](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```
Example 2:
```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```
Example 3:
```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

Constraints:
- 0 <= s.length <= 5 * 104
- s consists of English letters, digits, symbols and spaces.

## Solution
Sliding window
```java
class Solution {
    
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character,Integer> charInd = new HashMap<>();
        char[] arr = s.toCharArray();
        int maxLen = 0, start = 0;

        for(int i=0; i<s.length(); i++){
            //If repeated
            if(charInd.containsKey(arr[i]) ){
                //start substring after prev occurrence,
                //update curr occurrence index
                start = Math.max(charInd.get(arr[i]) + 1, start);
                charInd.put(arr[i], i);
            }
            else{
                //Add unique char to set and map
                charInd.put(arr[i], i);
            }
            //Len = curr ind - updated start ind (removing last repeated char)
            maxLen = Math.max(i-start+1, maxLen);
        }

        return maxLen;
    }  
}
```

## Approach:
Keep a map of characters and the last index they appeared in. Iterate once and find curr len as current index - start ind. 
Update start index to a later position (not before current start) if repeated char is found, to the index next to when the current character was found. 
So if something re-appears, remove its previous occurance and start ahead, but if we are already much ahead, start there.

`Time Complexity: O(n)` | `Space Complexity: O(n)`
