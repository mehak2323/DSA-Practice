/* IS SUBSEQUENCE
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by
deleting some (can be none) of the characters without disturbing the relative positions of
the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Link: https://leetcode.com/problems/is-subsequence/
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int j=0;
        for(int i=0; i<t.length(); i++)
        {
            if(t[i]==s[j])
                j++;
        }
        if(j==s.length())
            return true;
        return false;
    }
};
/*
Test Cases:
    Input: s = "abc", t = "ahbgdc"
    Output: true

    Input: s = "axc", t = "ahbgdc"
    Output: false

Time Complexity: O(n)
Space Complexity: O(1)
*/
