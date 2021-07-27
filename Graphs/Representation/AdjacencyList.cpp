// #include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<pair<int,int>> adj[], int u,int v,int weight)
{
    pair<int,int> edge=make_pair(v,weight);
    pair<int,int> edge2=make_pair(u,weight);
    adj[u].push_back(edge);
    adj[v].push_back(edge2);  //comment it if graph is directed!
}

void printGraph(vector<pair<int,int>>adj[],int V)
{
    for(int i=0;i<V;i++)
    {
        cout<<i<<": ";
        for(auto e: adj[i])
        {
            cout<<"-> "<<e.first<<"("<<e.second<<") ";
        }
        cout<<endl;
    }
}

int main()
{
    int V=5;
    vector<pair<int,int>> adj[V];
    addEdge(adj, 0, 1,3);
    addEdge(adj, 0, 4,4);
    addEdge(adj, 1, 2,5);
    addEdge(adj, 1, 3,6);
    addEdge(adj, 1, 4,9);
    addEdge(adj, 2, 3,1);
    addEdge(adj, 3, 4,2);
    printGraph(adj, V);
    return 0;
}
