#include<bits/stdc++.h>

using namespace std;

template<class T>
class Graph{
    private:
        int V,E;
        std::vector<T> Vertices;
        map<T,list<pair<T,double>>> adj;
    public:
        Graph(int v=0,int e=0): V{v}, E(e) {}
        void addEdge(T u,T v,double w)
        {
            if(find(Vertices.begin(),Vertices.end(),u)==Vertices.end()) Vertices.push_back(u);
            if(find(Vertices.begin(),Vertices.end(),v)==Vertices.end()) Vertices.push_back(v);
            V=Vertices.size();
            E++;
            pair<T,double> temp=make_pair(v,w);
            adj[u].push_back(temp);
        }
        
        template<class T2> // if you don't mention this template, it will show errors and erros!!
        friend void BellmanFord(Graph<T2>* graph,T2 src);
        
        void print_graph();
};

template <typename T>
void Graph<T>::print_graph()
{
    cout<<"-----------------------"<<endl;
    cout<<"Printing your Graph!\n";
    cout<<"-----------------------"<<endl;
    for(auto i: adj)
    {
        for(auto j: i.second)
        {
            cout<<i.first<<": "<<j.first<<"("<<j.second<<")\n";
        }
    }
    cout<<"-----------------------"<<endl;
    cout<<"Vertices: "<<V<<" | Edges: "<<E<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"-----------------------"<<endl;
}

template< class T>
void BellmanFord(Graph<T> *graph,T src)
{
    double INT_MX=std::numeric_limits<double>::infinity();
    T V=graph->V;
    T E=graph->E;
    map<T,double> dist;
    for(auto x: graph->Vertices)
    {
        dist[x]=INT_MX;
    }
    dist[src]=0;
    //Relaxation
    
    for(int i=1;i<V;i++)
    {
        for(auto j: graph->adj)
        {
            T u=j.first;
            if(dist[u]==INT_MX) continue;
            for(auto k: j.second )
            {
                T v=k.first;
                double weight=k.second;
                if(dist[u]+weight<dist[v])
                    dist[v]=dist[u]+weight;
            }
        }
    }
    
    // Negative-weight cycle check
    for(auto i: graph->adj)
    {
        T u=i.first;
        if(dist[u]==INT_MX) continue;
        for(auto j: i.second )
        {
            T v=j.first;
            double weight=j.second;
            if(dist[u]+weight<dist[v])
            {
                cout<<"Graph Contains Negative-Weight cycle, BellmanFord Can't be applied :(\n";
                return;
            }
        }
    }
    
    
    // printing
    cout<<"------BellmanFord------"<<endl;
    cout<<"Vertex | Dist. from "<<src<<"\n";
    for(auto i:dist)
    {
        cout<<i.first<<"\t:\t"<<i.second<<endl;
    }
    cout<<"-----------------------"<<endl;
}


int main()
{
    Graph<int>*g =new Graph<int>();
    g->addEdge(0,1,-1); //A-B
    g->addEdge(0,2,4);  //A-C
    g->addEdge(1,2,3);  //B-C
    g->addEdge(1,3,2);  //B-D
    g->addEdge(1,4,2);  //B-E
    g->addEdge(3,2,5);  //D-C
    g->addEdge(3,1,1);  //D-B        // change weight to -1 too see Negative-Weight wroking!
    g->addEdge(4,3,-3); //E-D
    
    g->print_graph();
    
    BellmanFord<int>(g,0);
    return 0;
}
