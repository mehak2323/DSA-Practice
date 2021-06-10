/* Lapindrome is defined as a string which when split in the middle,
gives two halves having the same characters and same frequency of each character.
If there are odd number of characters in the string,
we ignore the middle character and check for lapindrome.
Your task is simple. Given a string, you need to tell if it is a lapindrome.

Link: https://www.codechef.com/LRNDSA01/problems/LAPIN
*/

#include <iostream>
using namespace std;

int main()
{
    int t,mid,len,count;
	string str;
	cin>>t;
	while(t--)
	{
	   cin>>str;
	   len=str.length();
	   if(len%2==0)
	       mid=len/2;
	   else
	       mid=(len/2)+1;

	   count=0;
	   for(int i=0; i<len/2;i++)
	   {
	       for(int j=mid; j<len;j++)
	       {
	           if(str[i]==str[j])
	           {
	               str[j]='0';
	               count++;
	               break;
	           }
	       }
	   }
	   if(count==len-mid)
	       cout<<"YES\n";
	   else
	       cout<<"NO\n";
	}

    return 0;
}
/*
Test Case:
    Input:
    6
    gaga
    abcde
    rotor
    xyzxy
    abbaab
    ababc

    Output:
    YES
    NO
    YES
    YES
    NO
    NO
*/
