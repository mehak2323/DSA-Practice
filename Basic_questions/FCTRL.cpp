/* For any positive integer N, Z(N) is the number of zeros at the end of the decimal form of number N!.
They noticed that this function never decreases. If we have two numbers N1<N2 then Z(N1)≤Z(N2).
It is because we can never "lose" any trailing zero by multiplying by any positive number.
We can only get new and new zeros. We need a computer program that can determine its value efficiently.

Link: https://www.codechef.com/LRNDSA01/problems/FCTRL
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int t, i;
	long long int n,fives;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    fives=0;
	    for(i=5; n/i>=1; i=i*5)
	    {
	            fives=fives+n/i;
	    }
	    cout<<fives<<"\n";
	}
	return 0;
}
/*
Test Case:
    Input:
    6
    3
    60
    100
    1024
    23456
    8735373

    Output:
    0
    14
    24
    253
    5861
    2183837
*/
