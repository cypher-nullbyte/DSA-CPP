#include<bits/stdc++.h>

using namespace std;

class Graph
{
    private:
        map<int,bool> visited;
        map<int,list<int>> adj;
    
    public:
        void dfs();
        
        void addEdge(int u,int v);
        
        void dfs_util(int v);
};

void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

void Graph::dfs_util(int v)
{
    visited[v]=true;
    cout<<v<<" ";
    
    for(auto i: adj[v])
    {
        if(!visited[i]) dfs_util(i);
    }
    
}

void Graph::dfs()
{
    
    for(auto i: adj)
    {
        if(!visited[i.first]) dfs_util(i.first);
    }
}


int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
    g.dfs();
    return 0;
}


// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
