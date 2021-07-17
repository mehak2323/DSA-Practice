/* N MEETINGS IN ONE ROOM (LIKE ACTIVITY SELECTION)

There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i])
where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only
one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
*/

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        int maxMeet=1; //one or more meetings
        vector<pair<int,int>> acts (n);
        //Make a vector of pair to sort
        for(int i=0; i<n; i++)
        {
            acts[i].first = end[i];
            acts[i].second = start[i];
        }
        //sort activities based on finish time
        sort(acts.begin(), acts.end());

        int prev=0;
        //loop for remaining activities
        for(int i=1; i<n; i++)
        {
            //if start of current greater than finish of previous taken
            if(acts[i].second > acts[prev].first)
            {
                //take index of counted meeting as previous
                prev=i;
                //increase noumber of meeting
                maxMeet++;
            }
        }

        return maxMeet;
    }
};

/*
Test Cases:
    Input:
        N = 6
        start[] = {1,3,0,5,8,5}
        end[] =  {2,4,6,7,9,9}
    Output:
        4
    Explanation:
        Maximum four meetings can be held with
        given start and end timings.
        The meetings are - (1, 2),(3, 4), (5,7) and (8,9)

    Input:
        N = 3
        start[] = {10, 12, 20}
        end[] = {20, 25, 30}
    Output:
        2
    Explanation:
        Only two meetings can be held
        with given start and end timings.

Time Complexity: O(n log n) //n log n to sort and 2n for linear loops
Space Complexity: O(n) //to modify our input, not needed otherwise
*/
