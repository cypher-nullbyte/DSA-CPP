#include<bits/stdc++.h>

using namespace std;

class Graph
{
    private:
        map<int,bool> visited;
        map<int,list<int>> adj;
    
    public:
        void bfs(int);
        
        void addEdge(int u,int v);
        
        void bfs_util(int v,stack<int> &stack);
};

void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

void Graph::bfs_util(int v,stack<int> &stack)
{
    visited[v]=true;
    cout<<v<<" ";
    for(auto i: adj[v])
    {
        if(!visited[i])
        {
            stack.push(v);
            bfs_util(i,stack);
        }
    }
}

void Graph::bfs(int source)
{
    queue<int> queue;
    queue.push(source);
    visited[source]=true;
    while(!queue.empty())
    {
        int v=queue.front();
        cout<<v<<" ";
        queue.pop();
        
        for(auto i: adj[v])
        {
            if(!visited[i])
            {
                visited[i]=true;
                queue.push(i);
            }
        }
        
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
    g.bfs(0);
    return 0;
}

// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
