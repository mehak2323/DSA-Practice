/* ACTIVITY SELECTION PROBLEM
You are given n activities with their start and finish times. Select the maximum
number of activities that can be performed by a single person, assuming that a person
can only work on a single activity at a time.

Link: www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
*/

#include <bits/stdc++.h>
using namespace std;

//activity with start and finish time
struct activity{
    int start;
    int finish;
};
//compare function to sort activity in increasing order of finish time
bool compareActivity(activity s1, activity s2)
{
    return (s1.finish < s2.finish);
}
//function to find maximum no. of activities
int max_activity(activity acts[], int n)
{
    int max_acts=0;
    //greedy method to find activities with least finishing time to maximize activities
    //start will always be less than their respective finish, thus sort on finish
    sort(acts,acts+n,compareActivity);

    int i=0;
    //first activity will always be selected, rest depending on conditions
    cout<<acts[i].start<<","<<acts[i].finish<<"\n";
    max_acts++; //count of included activities
    i++; //index of latest included activity

    //loop for rest of the activities where next's start time is bigger than current's finish time
    for(int j=1; j<n; j++)
    {
        if(acts[j].start>=acts[i-1].finish)
        {
            cout<<acts[j].start<<","<<acts[j].finish<<"\n";
            max_acts++; i=j;
        }
    }
    return max_acts;
}

int main()
{
    int n, max_acts;
    cin>>n;
    activity acts[n];
    for(int i=0; i<n; i++)
    {
        cin>>acts[i].start>>acts[i].finish;
    }
    max_acts = max_activity(acts, n);
    cout<<max_acts;

    return 0;
}
/*
Test Case:
    Input:
    6
    1 2 3 4 0 6 5 7 8 9 5 9

    To understand input, start finish pairs:
    {(1,2),(3,4),(0,6),(5,7),(8,9),(5,9)}

    Output:
    1,2
    3,4
    5,7
    8,9
    4

    Time Complexity: O(n*log n) //log n to sort and n for linear loop
    Space Complexity: O(1) //sorted in same array
*/
