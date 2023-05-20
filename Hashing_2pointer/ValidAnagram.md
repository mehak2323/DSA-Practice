### Valid Anagram
[Leetcode](https://leetcode.com/problems/valid-anagram/)

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
```
Input: s = "anagram", t = "nagaram"
Output: true
```
Example 2:
```
Input: s = "rat", t = "car"
Output: false
```

Constraints:
```
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
```

### Solution

1. Storing count of each alphabet in array
```java
    public boolean isAnagram(String s, String t) {
        //If not same length, not anagram
        if(s.length() != t.length()) return false;

        int[] countsT = new int[26];
        int[] countsS = new int[26];

        //Store number of chars of each alphabet 
        for(int i=0; i<s.length(); i++){
            countsT[t.charAt(i) - 'a']++;
            countsS[s.charAt(i) - 'a']++;
        }

        //Check if all alphabets have same counts in both
        for(int i=0; i<countsT.length; i++){
            if(countsT[i]!=countsS[i]) return false;
        }

        return true;
    }
```
`Time complexity: O(n)` | `Space complexity: O(1)`

2. Hashmap
```java
class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character,Integer> smap=new HashMap<>();
        int sl=s.length();
        int tl=t.length();
        if(sl!=tl){return false;}
        //Add in map for s, remove char if present in t
        for(int i=0;i<sl;i++){
            //put(where, what)
            smap.put(s.charAt(i),smap.getOrDefault(s.charAt(i),0)+1);
            smap.put(t.charAt(i),smap.getOrDefault(t.charAt(i),0)-1);
        }
        //Check all alphabets are 0 or not
        for(char c:smap.keySet()){
            if(smap.get(c)!=0){return false;}
        }
        
        return true;
    }
}
```
`Time complexity: O(n)` | `Space complexity: O(1)`

3. Sort both and compare
```java
    public boolean isAnagram(String s, String t) {

        if(s.length() != t.length()) return false;

        char[] arrS = s.toCharArray();
        Arrays.sort(arrS);

        char[] arrT = t.toCharArray();
        Arrays.sort(arrT);

        for(int i=0; i<s.length(); i++){
            if(arrS[i]!=arrT[i]) return false; 
        }

        return true;
    }
```
`Time: n + n logn + n + n logn + n = n log n` | `Space: n + n = O(1)`
- Space depends on the sorting implementation which, usually, costs O(1) auxiliary space if heapsort is used.
- Note that in Java, toCharArray() makes a copy of the string so it costs O(n) extra space.
