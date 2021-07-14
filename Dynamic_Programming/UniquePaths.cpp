/* UNIQUE PATHS

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the
bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Link: https://leetcode.com/problems/unique-paths/
*/

class Solution {
public:
    int uniquePaths(int m, int n) {

        int dp[n][m];
        //Ways to reach first box
        dp[0][0]=0;

        //Loop for all boxes in grid
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                //Only 1 way to reach anybox in first row or column
                if(i==0 || j==0)
                    dp[i][j]=1;
                //We can reach a box either from it's top or left
                else
                    dp[i][j]= dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[n-1][m-1];
    }
};
/*
Test Cases:
    Input: m = 3, n = 7
    Output: 28
    Array:
    0  1  1  1  1  1  1
    1  2  3  4  5  6  7
    1  3  6 10 15 21 28

    Input: m = 3, n = 2
    Output: 3
    Explanation:
    From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
    1. Right -> Down -> Down
    2. Down -> Down -> Right
    3. Down -> Right -> Down

    Input: m = 7, n = 3
    Output: 28

    Input: m = 3, n = 3
    Output: 6

Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/
