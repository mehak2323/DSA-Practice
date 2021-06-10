/* You're given the maximum speed of N cars in the order they entered the long straight segment of the circuit.
Each car prefers to move at its maximum speed. If that's not possible because of the front car being slow,
it might have to lower its speed. It still moves at the fastest possible speed while avoiding any collisions.

Link: https://www.codechef.com/LRNDSA01/problems/CARVANS
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n, cars;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n];
	    cars=1;
	    cin>>arr[0];
	    for(int i=1; i<n;i++)
	    {
	        cin>>arr[i];
	        if(arr[i]<=arr[i-1])
	            cars++;
	        else
	            arr[i]=arr[i-1];
	    }
	    cout<<cars<<"\n";
	}

	return 0;
}
/*
Test Case:
    Input:
    3
    1
    10
    3
    8 3 6
    5
    4 5 1 2 3

    Output:
    1
    2
    2
*/
