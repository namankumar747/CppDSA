#include<iostream>
#include<vector>
#include<list>
using namespace std;
//Graph Creation by Adjacency List

vector<list<int>> graph;
int vertex; //Number of Vertices

void add_edge(int source, int destination, bool bi_dirc = true){
    graph[source].push_back(destination);
    if(bi_dirc == true){
        graph[destination].push_back(source);
    }
}

void display(){
    for(int i = 0 ; i < graph.size() ; i++){
        cout<<i<<" -> ";
        for(auto ele : graph[i]){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

int main(){
    cout<<"Enter No Of Vertices ";
    cin>>vertex;
    graph.resize(vertex, list<int> ());
    int edges;
    cout<<"Enter No Of Edges ";
    cin>>edges;
    cout<<"Enter Edges (source <space> destination)"<<endl;
    while(edges != 0){
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
        edges = edges -1;
    }
    cout<<endl;
    display();
}
