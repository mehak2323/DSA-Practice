/* You are developing a smartphone app. You have a list of potential customers for your app.
Each customer has a budget and will buy the app at your declared price if and only if the price is less than
or equal to the customer's budget. You want to fix a price so that the revenue you earn from the app is maximized.
Find this maximum possible revenue.

Link: https://www.codechef.com/LRNDSA01/problems/ZCO14003
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,max=0 , i;
	cin>>n;
	long long int arr[n];

	for(i=0; i<n; i++)
	{
	    cin>>arr[i];
	}
	sort(arr,arr+n);
	for(i=0; i<n; i++)
	{
	    if(arr[i]*(n-i)>max)
	        max=arr[i]*(n-i);
	}

	cout<<max;
	return 0;
}
/*
Test Case:
    Input:
    4
    30
    20
    53
    14
    Output:
    60

    Input:
    5
    40
    3
    65
    33
    21
    Output:
    99
*/
