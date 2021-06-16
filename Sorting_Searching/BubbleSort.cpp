/* BUBBLE SORT
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping
the adjacent elements if they are in wrong order.

Link: https://www.geeksforgeeks.org/bubble-sort/
*/

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    bool swapped;
    for (i = 0; i < n; i++)
    {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           temp=arr[j];
           arr[j]=arr[j+1];
           arr[j+1]=temp;
           swapped = true;
        }
     }
     // If no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
    }
}
int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter elements of the array:\n";
    for (int i = 0; i < arr_size; i++)
        cin>> arr[i];

    bubbleSort(arr, arr_size);

    cout << "Sorted array using Bubble Sort is: \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";

    return 0;
}
/*
Test Case:
    Input:
    Enter number of elements: 5
    Enter elements of the array:
    5 4 3 6 1

    Output:
    Sorted array using Bubble Sort is:
    1 3 4 5 6
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
