/* HAS PATH? (between 2 graph nodes)
1. You are given a graph, a src vertex and a destination vertex.
2. You are required to find if a path exists between src and dest. If it does, print true
otherwise print false.

Link: www.pepcoding.com/resources/online-java-foundation/graphs/has-path-official/ojquestion
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
    printEdge(void){
        //cout<< this->src<< " "<< this->nbr << " " <<this->wt <<endl;
        cout<< "nbr: "<<this->nbr << " wt: " <<this->wt <<endl;
    }
};

void printGraph(vector<vector<Edge>> graph)
{
    cout<<"Graph:\n";
    for(int i=0; i<graph.size(); i++)
    {
        cout<<"Source Node no.: "<<graph[i][0].src<<"\n";
        for(int j= 0; j< graph[i].size(); j++)
        {
            cout<<"Neighbor no. "<<j<<"  ";
            graph[i][j].printEdge();
        }
    }
}

bool hasPath(vector<vector<Edge>> graph, int source, int dest, vector<bool> visited)
{
    //source becomes current source's neighbor in recursion call
    if(source==dest)
        return true;
    //mark current node traversed
    visited[source]=true;
    //iterate current node's neighbors
    for(auto itr: graph[source])
    {
        if(visited[itr.nbr]==false)
        {
            bool path= hasPath(graph,itr.nbr,dest,visited);
            //if we can reach destination by one of the neighbors
            //we can reach destination by current node
            if(path)
                return true;
        }
    }
    //none of the neighbors reached destination
    return false;
}
int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    //a vector of nodes and each node has a vector of it's adjacent edges
    vector<vector<Edge>> graph(nodes);

    //source or current, neighbor, weight of edge
    int src, nbr, wt;

    for(int i=0; i<edges; i++)
    {
        cin>>src>>nbr>>wt;
        //undirected edges so storing neighbor in both
        Edge e1(src,nbr,wt);
        graph[src].push_back(e1);
        Edge e2(nbr,src,wt);
	    graph[nbr].push_back(e2);
    }

    int source,dest;
    cin>>source>>dest;

    //printGraph(graph);
    vector<bool> visited(nodes);
    cout<<"\nHas path? : "<<hasPath(graph,source,dest,visited);

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
    true
*/
