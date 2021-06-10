/* LONGEST COMMON SUBSEQUENCE

Given two strings text1 and text2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters
(can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Link: https://leetcode.com/problems/longest-common-subsequence/
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int size1= text1.length();
        int size2= text2.length();
        vector<vector<int>> dp(size1+1, vector<int>(size2+1));

        for(int i=size1-1; i>=0;  i--){
            for(int j=size2-1; j>=0 ;j--)
            {
                if(text1[i]==text2[j])
                {
                    dp[i][j]=dp[i+1][j+1] +1;
                }
                else
                {
                    dp[i][j]= max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
    }
};
/*
Test Case:
    Input: text1 = "abcde", text2 = "ace"
    Output: 3
    Explanation: The longest common subsequence is "ace" and its length is 3.
    DP array:
      a b c c d e -
    a 3 2 2 2 1 1 0
    c 2 2 2 2 1 1 0
    e 1 1 1 1 1 1 0
    - 0 0 0 0 0 0 0
    if same: bottom diagonal, if diff: max(left, right)

    Input: text1 = "abc", text2 = "abc"
    Output: 3
    Explanation: The longest common subsequence is "abc" and its length is 3.

    Input: text1 = "abc", text2 = "def"
    Output: 0
    Explanation: There is no such common subsequence, so the result is 0.

Time Complexity: O(mn)
Space Complexity: O(mn)
*/
