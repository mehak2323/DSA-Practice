/* MATRIX MULTIPLICATION
We have to multiply two matrices of any size.
Link: https://www.geeksforgeeks.org/c-program-multiply-two-matrices/
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //size of first matrix (m,n), size of second matrix (p,q)
    int m=2, n=3, p=3, q=4,j, sum = 0;
    int first[10][10], second[10][10], multiply[10][10];

    cout<<"\nEnter elements of first matrix\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin>>first[i][j];

    cout<<"\nEnter elements of second matrix\n";
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            cin>>second[i][j];

    //loop 1 for first matrix rows
    for (int i = 0; i < m; i++)
    {
        //loop 2 for second matrix columns
        for (j = 0; j < q; j++)
        {
            sum=0; //initialize sum as 0
            //loop 3 for common value (first's col, second's rows)
            for (int k = 0; k < p; k++)
                sum = sum + first[i][k]*second[k][j];
            //store the sum in multiply matrix
            multiply[i][j] = sum;
        }
    }
    //display multiplied matrix
    cout<<"\nProduct of the matrices:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
            cout<<multiply[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
/* Test Case:
    Input:
    Enter elements of first matrix
    1 2 3
    4 5 6

    Enter elements of second matrix
    1 0 0 0
    0 1 0 0
    0 0 1 0

    Output:
    Product of the matrices:
    1 2 3 0
    4 5 6 0

Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/
