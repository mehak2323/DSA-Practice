/* FLOOD FILL
1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a. The numbers can be 1 or 0 only.
4. You are standing in the top-left corner and have to reach the bottom-right corner.
Only four moves are allowed 't' (1-step up), 'l' (1-step left), 'd' (1-step down) 'r' (1-step right). You can only move to cells which have 0 value in them. You can't move out of the boundaries or in the cells which have value 1 in them (1 means obstacle)
5. Complete the body of floodfill function - without changing signature - to print all paths that can be used to move from top-left to bottom-right.

Note1 -> Please check the sample input and output for details
Note2 -> If all four moves are available make moves in the order 't', 'l', 'd' and 'r'

Link: www.pepcoding.com/resources/online-java-foundation/recursion-backtracking/flood-fill-official/ojquestion
*/

#include <iostream>
#include<vector>
using namespace std;

void floodfill(vector<vector<int>> maze, int i, int j, string psf,vector<vector<int>> visited) {
    //if out of maze return
    if(i>maze.size()-1 || i<0 || j<0 || j>maze[i].size()-1|| maze[i][j]==1 || visited[i][j]==1)
        return;
    //if reached end return
    if(i==maze.size()-1 && j==maze[i].size()-1)
    {
        cout<<psf<<endl;
        return;
    }
    //visit current then recur for t,l,d,r
    visited[i][j]=1;
    floodfill(maze,i-1,j, psf.append("t"),visited);
    psf.pop_back();
    floodfill(maze,i,j-1,psf.append("l"),visited);
    psf.pop_back();
    floodfill(maze,i+1,j,psf.append("d"),visited);
    psf.pop_back();
    floodfill(maze,i,j+1,psf.append("r"),visited);
    psf.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    //visited array to avoid recursion for traversed cell
    vector<vector<int>> visited(n, vector < int > (m));
    //psf=path so far in floodfill function
    floodfill(arr,0,0,"",visited);
    return 0;
}
/*
Test Case:
    Input:
    3 3
    0 0 0
    1 0 1
    0 0 0

    Output:
    rddr

    Time Complexity: O(n*m) ?
    Space Complexity: O(n*m)
*/
