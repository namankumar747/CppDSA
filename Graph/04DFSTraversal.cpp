#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

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
    vector<list<int>> graph = {{1, 3}, {0, 2, 4}, {1, 5, 6}, {0, 4}, {1, 3}, {2, 6}, {2, 5}};
    dfsTraversal(graph, 0);
    
}
