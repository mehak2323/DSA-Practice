/* FRACTIONAL KNAPSACK
Given weights and values of n items, we need to put these items in a knapsack of
capacity W to get the maximum total value in the knapsack.

Link: https://www.geeksforgeeks.org/fractional-knapsack-problem/
*/

#include<bits/stdc++.h>
using namespace std;
//struct to store weights values and initialize them
struct Knap
{
    int weight;
    int value;
    Knap(int value, int weight)
    {
       this->value=value;
       this->weight=weight;
    }
};
//compare pairs by value/weight
bool compareValByWeight(Knap k1, Knap k2)
{
    if(float(k1.value/k1.weight) > float(k2.value/k2.weight))
        return true;
    return false;
}

int knapsack(Knap k[], int n, int capacity)
{
    //sort pairs by val/weight
    sort(k, k+n, compareValByWeight);
    int maxVal=0, wt=0;
    //loop over all sorted pairs
    for(int i=0; i< n; i++)
    {
        //if capacity available, take part of it
        if(capacity-wt>0)
        {
            //if capacity left after taking current pair's weight, take full weight
            if(k[i].weight<=(capacity-wt)){
                wt+= k[i].weight;
                maxVal+=k[i].value;
            }
            //else take fraction of weight, current profit*capacity left
            else{
                maxVal+=(capacity-wt)*(k[i].value/k[i].weight);
            }
        }
        else
            break;
    }
    return maxVal;
}
int main()
{
    Knap arr[] = {{60, 10}, {100, 20}, {120, 30}} ;
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans,capacity=50;
    ans= knapsack(arr,n,capacity);
    cout<<ans;
    return 0;
}
/*
Test Case:
    Input:
    {60, 10}, {100, 20}, {120, 30}
    Output:
    240

    Input:
    {60, 10}, {100, 20}, {120, 30}
    Output:
    50
Time Complexity: O(n log(n))
Space Complexity: O(1)
*/
