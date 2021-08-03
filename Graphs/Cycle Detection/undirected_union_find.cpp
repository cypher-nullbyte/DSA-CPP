#include<bits/stdc++.h>

using namespace std;

vector<int> dsuf;  //disjoint set union find

int find(int v)
{
    if(dsuf[v]==-1)
        return v;
    return find(dsuf[v]);
}

void union_op(int fromP,int toP)
{
    fromP=find(fromP);
    toP=find(toP);
    dsuf[fromP]=toP;
}


bool isCyclic(vector<pair<int,int>>& edge_list)
{
    for(auto p: edge_list)
    {
        int fromP=find(p.first);
        int toP=find(p.second);
        if(fromP==toP) return true;
        
        union_op(fromP,toP);
    }
    return false;
}

int main()
{
    int E;
    int V;
    cin>>E>>V;
    
    dsuf.resize(V,-1); // Mark all vertices as separate subsets with 1 element
    vector<pair<int,int>> edge_list;
    for(int i=0;i<E;i++)
    {
        int from,to;
        cin>>from>>to;
        edge_list.push_back({from,to});
    }
    if(isCyclic(edge_list)) cout<<"True\n";
    else cout<<"False\n";
    return 0;
}

/*
3
4
0 1
1 3
1 2

OR

4
4
0 1
1 3
1 2
3 2
*/
