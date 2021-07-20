/* REVERSE A STRING */

#include <iostream>
using namespace std;

int main()
{
    //string mystring="abracadabra1234";
    string mystring;
    cin>>mystring;

    //start i from beginning and j from end and swap
    for(int i = 0,j = mystring.length()-1; i<=j; i++, j--)
    {
        swap(mystring[i],mystring[j]);
    }

    //string reversed
    cout<<mystring;

    return 0;
}
/*
Test Cases:
    Input: abracadabra1234
    Output: 4321arbadacarba

    Input: madman
    Output: namdam

Time Complexity: O(n)
Space Complexity: O(1)
*/
