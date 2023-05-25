## Insert Interval
[Leetcode](https://leetcode.com/problems/insert-interval/)

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.


Example 1:
```
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```
Example 2:
```
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
``` 

Constraints:
```
0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
```

## Solution 
Linear search
```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> merged = new ArrayList<>();
        int i = 0, n = intervals.length;
        
        // Add intervals before the newInterval that do not overlap
        while (i < n && intervals[i][1] < newInterval[0]) {
            merged.add(intervals[i]);
            i++;
        }
        
        // Merge intervals that overlap with the newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        // Add the merged interval
        merged.add(newInterval);
        
        // Add the remaining intervals after the newInterval
        while (i < n) {
            merged.add(intervals[i]);
            i++;
        }
        
        return merged.toArray(new int[merged.size()][2]);
    }
```
```java
    //Incorrect code, before I asked chatgpt to correct it :') 
    /*
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int i=0, j=0, intInd=0, n=intervals.length;
        int[][] ans = new int[n][2];

        //Fill starting intervals
        for(i=0, j=0; i<n; i++, j++){
            //find position for start of new interval (6>4)
            //For [4,8], [[1,2],[3,5],here,[6,7],[8,10],[12,16]]
            if(intervals[i][0] > newInterval[0]){
                i--;
                intInd = i;
                break;
            }
            //Otherwise keep adding intervals to answer
            ans[j][0] = intervals[i][0];
            ans[j][1] = intervals[i][1];
        }

        //Get merged interval, if possible
        for( ; i<n; i++){
            //till newInt end is <= currInt end we can merge, 
            //else stop and write final merged
            //For [4,8], [[1,2],([3,5]),[6,7],[8,(10)],[12,16]]
            if(intervals[i][1] > newInterval[1]){
                ans[intInd][0] = Math.min(intervals[intInd][0], newInterval[0]);
                ans[intInd][1] = Math.max(intervals[i-1][1], newInterval[1]);
                break;
            }
        }

        //Fill remaining intervals
        for(; i<n && j<n; i++, j++){
            ans[j][0] = intervals[i][0];
            ans[j][1] = intervals[i][1];
        }
        
        return ans;
    }
    */

}
```

can also do binary search

`Time complexity: O(n)` | `Space Complexity: O(1)` as list is part of answer not computation
