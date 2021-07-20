/* SUBSET SUMS

Given a list arr of N integers, print sums of all subsets in it.
Output should be printed in increasing order of sums.

Link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1
*/

class Solution
{
public:

    void sumz(vector<int> &arr, int &N, int i, vector<int> &ans, int sum)
    {
        //whole array traversed
        if(i==N)
        {
            //store the final sum for each recursion end
            ans.push_back(sum);
            return;
        }

        //Recur by skipping current element
        sumz(arr,N,i+1,ans,sum);
        //Recur by taking current element in sum
        sumz(arr,N,i+1,ans,sum + arr[i]);

        return; //not needed
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        //Answer vector
        vector<int> ans;
        //Helping function to be used for recursion
        sumz(arr, N, 0, ans, 0);
        //Sums will be unsorted so we need to sort them
        sort(ans.begin(), ans.end());

        return ans;
    }
};
/*
Test Cases:
    Input:
        N = 2
        arr[] = {2, 3}
    Output:
        0 2 3 5
    Explanation:
        When no elements is taken then Sum = 0.
        When only 2 is taken then Sum = 2.
        When only 3 is taken then Sum = 3.
        When element 2 and 3 are taken then
        Sum = 2+3 = 5.

    Input:
        N = 3
        arr = {5, 2, 1}
    Output:
        0 1 2 3 5 6 7 8

Time Complexity: O(2^N log(2^N) + 2^N) //sort after recursion
Space Complexity: O(2^N)
*/
