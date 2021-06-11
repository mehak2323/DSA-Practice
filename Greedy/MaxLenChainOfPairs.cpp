/* MAXIMUM LENGTH CHAIN OF PAIRS
You are given n pairs of numbers. In every pair, the first number is always smaller than the
second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be
formed in this fashion. Find the longest chain which can be formed from a given set of pairs.

Link: https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/
*/
#include<bits/stdc++.h>
using namespace std;

struct onePair
{
    int a;
    int b;
    //constructor to initialize pair
    onePair(int a=0, int b=0)
    {
        this->a=a;
        this->b=b;
    }
    //function to print pair
    void printPair(void)
    {
        cout<<"{"<<this->a<<","<<this->b<<"}";
    }
};
//compare pairs based on first value
bool comparePairs(onePair p1, onePair p2)
{
    if(p1.a<p2.a)
        return true;
    return false;
}
void maxChainPairs(onePair p[], int n)
{
    //sort the pairs increasing order of first value
    sort(p,p+n,comparePairs);

    //create answer structure
    onePair ans[n];
    //first pair after sorting will always be in answer
    ans[0].a = p[0].a;
    ans[0].b = p[0].b;
    int m=1; //current index of answer structure array
    //loop in rest of the pairs given
    for(int i=1; i<n;i++)
    {
        //if second value of last pair inserted in answer is less than
        //first value of pair we are iterating, include it in answer
        if(ans[m-1].b < p[i].a)
        {
            ans[m].a=p[i].a;
            ans[m].b=p[i].b;
            m++;
        }
    }
    //print all pairs in answer structure array
    for(int i=0; i<m; i++)
    {
        ans[i].printPair();
        cout<<",";
    }
}
int main()
{
    onePair p[]={{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n= sizeof(p)/sizeof(p[0]);
    maxChainPairs(p,n);
    return 0;
}
/*
Test Case:
    Input1:
    {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}
    Output1:
    {5,24},{27,40},{50,90},

    Input2:
    {5, 24}, {15, 25},{27, 40}, {50, 60}
    Output2:
    {5,24},{27,40},{50,60},

Time Complexity: O(n* log(n)) //nlogn + n
Space Complexity: O(n)
*/
