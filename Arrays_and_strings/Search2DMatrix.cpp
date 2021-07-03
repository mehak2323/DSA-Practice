/* SEARCH 2D MATRIX

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

Link: https://leetcode.com/problems/search-a-2d-matrix/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();
        int low,high, mid;

        //loop over rows
        for(int i=0; i<n; i++)
        {
            //see if target is less than last elem of row
            if(target<=matrix[i][m-1])
            {
                //if target is last elem of row
                if(target==matrix[i][m-1])
                    return true;

                //if target is present in current row
                else
                {
                    // return binary_search();
                    low=0, high=m-1;
                    while(low<=high)
                    {
                        mid= (low+high) / 2;

                        //update low
                        if(target > matrix[i][mid])
                            low=mid+1;

                        //update high
                        else if(target < matrix[i][mid])
                            high=mid-1;

                        //elem found
                        else
                            return true;
                    }
                }
            }
        }
        return false;
    }
};
/*
Test Cases:
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false

Time Complexity: O(n + log m)
Space Complexity: O(1)
*/
