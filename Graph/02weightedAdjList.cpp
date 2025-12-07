#include<iostream>
#include<vector>
#include<list>
using namespace std;
//Graph Creation by Adjacency List

vector<list<pair<int, int>>> graph;
int vertex;// Number of vertices

void add_edge(int source, int destination, int edgeweight, bool bi_dirc = true){
    graph[source].push_back({destination, edgeweight});
    if(bi_dirc == true){
        graph[destination].push_back({source, edgeweight});
    }
}

void display(){
    for(int i = 0; i<graph.size() ; i++){
        cout<<i<<" -> ";
        for(auto ele : graph[i]){
            cout<<"("<<ele.first<<" "<<ele.second<<") ";
        }
        cout<<endl;
    }
}

int main(){
    cout<<"Enter No Of Vertices ";
    cin>>vertex;
    graph.resize(vertex, list<pair<int, int>> ());
    int edges;
    cout<<"Enter No Of Edges ";
    cin>>edges;
    cout<<"Enter Edges (source <space> destination <space> EdgeWeight)"<<endl;
    while(edges != 0){
        int s, d, wt;
        cin>>s>>d>> wt;
        add_edge(s, d, wt);
        edges = edges -1;
    }
    cout<<endl;
    display();
}