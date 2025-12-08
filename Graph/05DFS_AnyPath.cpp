#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
//Check If There is any Path Between two Nodes or not
void add_edge(vector<list<int>> &graph, int source, int destination, bool bi_dirc = true){
    graph[source].push_back(destination);
    if(bi_dirc == true){
        graph[destination].push_back(source);
    }
}

bool dfs(vector<list<int>> graph, int curr, int end, unordered_set<int> &visited){
    if(curr = end) return true;
    visited.insert(curr);
    for(auto neighbour : graph[curr]){
        if(visited.count(neighbour) == 0){
            bool result = dfs(graph, neighbour, end, visited);
            if(result == true) return true;
        }
    }
    return false;
}

bool isAnyPath(vector<list<int>> graph, int curr, int end){
    unordered_set<int> visited;
    return dfs(graph, curr, end, visited);
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
}