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
        
        void dfs_util(int v,list<int> &stack,int &res);
};

void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}

void Graph::dfs_util(int v,list<int> &stack,int &res)
{
    visited[v]=true;
    for(auto i: adj[v])
    {
        for(auto j: stack)
        {
            if(i==j)res++;
        }
        if(!visited[i])
        {
            stack.push_front(i);
            dfs_util(i,stack,res);
        }
       
    }
    stack.pop_front();
}

void Graph::dfs(int source)
{
    list<int> stack;
    int res=0;
    for(auto i: adj) 
    {
        int x=i.first;
        if(!visited[x])
        {
            stack.push_front(x);
            dfs_util(x,stack,res);
        }
    }
    cout<<"There are "<<res<<" cycles"<<endl;
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
    g.addEdge(11,10);
    g.addEdge(10,11);
    g.addEdge(12,13);
    g.dfs(0);
    return 0;
}
