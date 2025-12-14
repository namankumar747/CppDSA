#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool dfs(vector<vector<int>>& graph, int src, int parent, unordered_set<int>& visited){
    visited.insert(src);
    for(int neighbour : graph[src]){
        if(visited.count(neighbour) == 1 && neighbour != parent) return true;
        if(visited.count(neighbour) == 0){
            bool result = dfs(graph, neighbour, src, visited);
            if(result == true) return true;
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& graph){
    unordered_set<int> visited;
    int vertex = graph.size();
    bool result = false;
    for(int i = 0; i < vertex; i++){
        if(visited.count(i) == 0){
            result = dfs(graph, i, -1, visited);
            if(result == true) return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> graph = {{1, 2, 3}, {0}, {0}, {0, 4}, {3, 5}, {4, 6}, {3, 5, 7}, {6, 8, 9}, {7}, {7}};
    if(isCycle(graph) == true) cout<<"Cycle Detected"<<endl;
    else cout<<"No Cycle"<<endl;
}

//if visited node is not parent node then cycle detected