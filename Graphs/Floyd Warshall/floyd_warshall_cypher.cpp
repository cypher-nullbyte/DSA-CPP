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
        
        template <class Tf>
        friend void floydWarshall(Graph<Tf>*g);
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

template<typename T>
void floydWarshall(Graph<T>* graph)
{
    int V=graph->V;
    double matrix[V][V];
    map<T,int> id;
    
    //block to make ids index
    {
        int i=0;
        for(auto x: graph->Vertices)
        id[x]=i++;
    }
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            double inf=numeric_limits<double>::infinity();
            matrix[i][j]=(i==j) ? 0 : inf;
        }
    }
    
    for(auto i: graph->adj)
    {
        T u=i.first;
        for(auto j: i.second)
        {
            T v=j.first;
            double weight=j.second;
            matrix[id[u]][id[v]]=weight;
        }
    }
    
    // Floyd Warshall 
    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(i==j) continue;
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
    cout<<" \t";
    for(auto i: id) cout<<i.first<<"\t";
    cout<<endl<<"--------------------------------------------"<<endl;
    auto it=id.begin();
    for(int i=0;i<V;i++)
    {
        cout<<(*it).first<<" |\t";
        for(int j=0;j<V;j++)
            cout<<matrix[i][j]<<"\t";
        cout<<endl;
        it++;
    }
}

int main()
{
    Graph<char>*g =new Graph<char>();
    g->addEdge('A','B',-1); //A-B
    g->addEdge('A','C',4);  //A-C
    g->addEdge('B','C',3);  //B-C
    g->addEdge('B','D',2);  //B-D
    g->addEdge('B','E',2);  //B-E
    g->addEdge('D','C',5);  //D-C
    g->addEdge('D','B',1);  //D-B        
    g->addEdge('E','D',-3); //E-D
    
    g->print_graph();

    floydWarshall<char>(g);
    return 0;
}
