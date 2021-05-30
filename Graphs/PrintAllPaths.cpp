/* PRINT ALL PATHS (between 2 graph nodes)
1. You are given a graph, a source vertex and a destination vertex.
2. You are required to find and print all paths between source and destination. Print
   them in lexicographical order.
    E.g. Check the following paths
         012546
         01256
         032546
         03256
   The lexicographically smaller path is printed first.

Link: www.pepcoding.com/resources/online-java-foundation/graphs/print-all-paths-official/ojquestion
*/

#include<bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt){
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

void allPaths(vector<vector<Edge>> graph, int source, int dest, vector<bool> visited, string psf)
{
    //print path if destination reached
    if(source==dest)
    {
        cout<<psf<<endl;
        return;
    }
    //visit current node
    visited[source]=true;
    //psf.append(to_string(source)); //error to avoid

    //traverse in current's neighbor, unvisited
    for(auto itr: graph[source])
    {
        if(visited[itr.nbr]==false)
        {
            visited[itr.nbr]=true;
            //pass path so far in recursion, current source becomes neighbor
            allPaths(graph,itr.nbr,dest,visited,psf.append(to_string(itr.nbr)));
            //at this point, rest of path is either printed or incorrect so pop the neighbor added
            psf.pop_back();
        }
    }
    //no need to mark visited false (as opposed to solution in link) as function returns
    //and previous function will have this node unvisited anyways
}
int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    vector<vector<Edge>> graph(nodes);
    int src, nbr, wt;

    for(int i=0; i<edges; i++)
    {
        cin>>src>>nbr>>wt;
        Edge e1(src,nbr,wt);
        graph[src].push_back(e1);
        Edge e2(nbr,src,wt);
	    graph[nbr].push_back(e2);
    }

    int source,dest;
    cin>>source>>dest;

    vector<bool> visited(nodes);

    allPaths(graph,source,dest,visited,to_string(source).append(""));

    return 0;
}
/*
Test Case:
    Input:
    7
    8
    0 1 10
    1 2 20
    2 3 30
    0 3 10
    3 4 10
    4 5 20
    5 6 30
    4 6 5
    0
    6

    Output:
    0123456
    012346
    03456
    0346

    Time Complexity: O(n+e) //nodes, edges //traversing in adjacency list (or O(n*e)) ?
    Space Complexity: O(n) //for visited array, O(n) //for path so far string  ?
*/
