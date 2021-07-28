#include<bits/stdc++.h>

using namespace std;

class Graph
{
    private:
        map<int,bool> visited;
        map<int,list<int>> adj;
    
    public:
        void dfs(int);
        
        void addEdge(int u,int v);
        
        void dfs_util(int v,stack<int> &stack);
};

void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

void Graph::dfs_util(int v,stack<int> &stack)
{
    visited[v]=true;
    cout<<v<<" ";
    for(auto i: adj[v])
    {
        if(!visited[i])
        {
            stack.push(v);
            dfs_util(i,stack);
        }
    }
    stack.pop();
}

void Graph::dfs(int source)
{
    stack<int> stack;
    stack.push(source);
    while(!stack.empty())
    {
        int x=stack.top();
        stack.pop();
        if(!visited[x])
        {
            stack.push(x);
            dfs_util(x,stack);
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
    g.dfs(0);
    return 0;
}
