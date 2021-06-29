/* MERGE OVERLAPPING INTERVALS

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Link: https://leetcode.com/problems/merge-intervals/
*/

class Solution {
public:
    //compare function to sort used in first method, not needed
    /*
    static bool compare( const vector<int>& v1, const vector<int>& v2 )
    {
        return v1[0] < v2[0];
    }*/

    vector<vector<int>> merge(vector<vector<int>> &intervals) {

        //Answer vector
        vector<vector<int>> ans;

        //If no elements
        int n = intervals.size();
        if(n==0)
            return ans;

        //sort according to arrival //no need for compare function
        sort(intervals.begin(), intervals.end());

        //Temp interval to store merged intervals until next interval can't be merged
        vector<int> tempInt(2);
        //store first interval in temp
        tempInt = intervals[0];
        //loop for next intervals
        for(int i=1; i<n; i++)
        {
            //if next is starting after or same time as first is ending, merge
            if(tempInt[1]>=intervals[i][0])
            {
                //first intervals start will always be minimum
                //ending of merged interval be max of both's ending time
                tempInt[1]=max(tempInt[1], intervals[i][1]);

            }
            else
            {
                ans.push_back(tempInt);
                tempInt= intervals[i];
            }

        }
        ans.push_back(tempInt);
        return ans;

        /*
        //Brute , extra space, extra loop, removed & from function input

        int n = intervals.size();
        //sort according to arrival
        sort(intervals.begin(), intervals.end(), compare);
        //store which indexes to delete
        vector<int> delIndex(n);
        //Answer vector
        vector<vector<int>> ans;

        //find and label overlapping intervals and make the next interval continuous
        for(int i=0; i<n-1; i++)
        {
            if(intervals[i][1]>=intervals[i+1][0])
            {
                intervals[i+1][0]=intervals[i][0];
                if(intervals[i][1]>intervals[i+1][1])
                    intervals[i+1][1]= intervals[i][1];
                delIndex[i]=1;
            }

        }

        //Copy elements avoid deleting ones
        int len=0;
        for(int i=0; i<n; i++)
        {
            if(delIndex[i]==1)
                continue;
            else
            {
                ans.push_back(vector<int>(2));
                ans[len][0]=intervals[i][0];
                ans[len][1]=intervals[i][1];
                len++;
            }
        }

        return ans;
        */

    }
};
/*
Test Cases:

    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

    Input: intervals = [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Time Complexity: O(n log n)  // n + n logn
Space Complexity: O(n) or O(log n)  //making new array for sorting for ans array
                                    //OR if sorting original, log n space for sorting
*/
