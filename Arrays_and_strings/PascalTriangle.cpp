/* PASCAL'S TRIANGLE

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

Link: https://leetcode.com/problems/pascals-triangle/
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans(numRows);

        //using resize function, memory less than 68.62%, 6.5MB
        for(int i=0 ; i<numRows; i++)
        {
            ans[i].resize(i+1);
            ans[i][0]= ans[i][i]=1;
            for(int j=1; j<i; j++)
            {
                ans[i][j]=ans[i-1][j-1]+ ans[i-1][j];
            }
        }

        /*
        //without resize, just pushback, memory less than 31.43%, 6.6MB
        for(int i=0 ; i<numRows; i++)
        {
            for(int j=0; j<i+1; j++)
            {
                if(j==0 || j==i)
                    ans[i].push_back(1);
                else
                    ans[i].push_back(ans[i-1][j-1]+ ans[i-1][j]);
            }
        }
        */
        return ans;

    }
};

/*
Test Cases:

    Input: numRows = 5
    Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1

    Input: numRows = 1
    Output: [[1]]

Time Complexity: O(n^2) //n is no. of rows
Space Complexity: O(n^2) //for ans
*/
