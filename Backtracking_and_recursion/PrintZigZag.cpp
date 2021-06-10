/* PRINT ZIGZAG
Figure out the pattern and complete the recursive function pzz to achieve the below for any positive number n.

Input1: 1
Output1: 1 1 1

Input2: 2
Output2: 2 1 1 1 2 1 1 1 2

Input2: 3
Output3: 3 2 1 1 1 2 1 1 1 2 3 2 1 1 1 2 1 1 1 2 3

Link: www.pepcoding.com/resources/online-java-foundation/introduction-to-recursion/print-zig-zag-official/ojquestion
*/

#include <iostream>
using namespace std;

void pzz(int n){
    if(n<1)
        return;
    cout<<n<<" ";
    pzz(n-1);
    cout<<n<<" ";
    pzz(n-1);
    cout<<n<<" ";
}

int main(){
    int n; cin>>n;
    pzz(n);
}
/*
Test Case:
Input: 3
Output: 3 2 1 1 1 2 1 1 1 2 3 2 1 1 1 2 1 1 1 2 3

Time Complexity: O(3^n)
Space Complexity: O(1)
*/
