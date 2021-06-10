/* Given an Integer N, write a program to reverse it.

Link: https://www.codechef.com/LRNDSA01/problems/FLOW007
*/

#include <iostream>
using namespace std;

int main()
{
    int t,n,num=0;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    while(n>0)
	    {
	        num= (num*10) + n%10;
	        n/=10;
	    }
	    cout<<num<<"\n";
	    num=0;
	}
    return 0;
}
/*
Test Case:
    Input:
    4
    12345
    31203
    2123
    2300
    Output:
    54321
    30213
    3212
    32
*/
