/* SLIDING WINDOW MAXIMUM (DEQUEUE STL)

You are given an array of integers nums, there is a sliding window of size k which is moving
from the very left of the array to the very right. You can only see the k numbers in the window.
Each time the sliding window moves right by one position.
Return the max sliding window.

hackerrank link: https://www.hackerrank.com/challenges/deque-stl/problem
leetcode link: https://leetcode.com/problems/sliding-window-maximum/
geeksforgeeks link: https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
*/

#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k){
	deque<int> dq(k);
    int curr;
    //fill descending order of values' indexes in deque for first window
    for(curr=0; curr<k; ++curr)
    {
        //if dequeue elements less than current, remove them
        while((!dq.empty()) && (arr[dq.back()]<= arr[curr]))
            dq.pop_back();
        dq.push_back(curr);
    }
    //loop for rest of the windows (n-k times)
    for(;curr<n; ++curr)
    {
        //print the max of previous window
        cout<<arr[dq.front()]<<" ";

        //if first index is not in current window, remove it
        if((!dq.empty())&&(dq.front()<= curr-k))
        {
            dq.pop_front();
        }
        //remove numbers smaller than current
        while((!dq.empty())&& (arr[dq.back()]<= arr[curr]))
        {
            dq.pop_back();
        }
        dq.push_back(curr);
    }
    //print last window's max val
    cout<< arr[dq.front()]<<endl;
}
int main(){

	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
/*
Test Cases:
    Input:
    2 //no. of test case
    5 2
    3 4 6 3 4
    7 4
    3 4 5 8 1 4 10

    Output:
    4 6 6 4
    8 8 8 10

    Explanation:

    First case: the contiguous subarrays of size 2 are {3,4},{4,6},{6,3} and {3,4}.
    The 4 maximum elements of subarray of size 2 are: 4 6 6 4.

    Second case: the contiguous subarrays of size 4 are {3,4,5,8},{4,5,8,1},{5,8,1,4}
    and {8,1,4,10}. The 4 maximum element of subarray of size 4 are: 8 8 8 10.

Time Complexity: O(n) //2n operations
Space Complexity: O(k) //for dequeue
*/
