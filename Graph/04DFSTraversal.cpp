#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

//All Paths Between Two Nodes
void add_edge(vector<list<int>> &graph, int source, int destination, bool bi_dirc = true){
    graph[source].push_back(destination);
    if(bi_dirc == true){
        graph[destination].push_back(source);
    }
}

void dfs(vector<list<int>> graph, int startNode, unordered_set<int> &visited){
    cout<<startNode<<" "; //Visit the Node
    visited.insert(startNode);
    
    for(auto neighbour : graph[startNode]){
        if(visited.count(neighbour) == 0){
            dfs(graph, neighbour, visited);
        }
    }
}

void dfsTraversal(vector<list<int>> graph, int startNode){
    unordered_set<int> visited;
    dfs(graph, startNode, visited);
}


int main(){
    vector<list<int>> graph;
    int vertex;
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
        add_edge(graph, s, d);
        edges = edges -1;
    }
    dfsTraversal(graph, 0);
    
}

/*No of vertices 7 
no of edges 8*/
/*
0 1
0 3
3 4    
1 4
1 2
2 5
5 6
2 6
*/