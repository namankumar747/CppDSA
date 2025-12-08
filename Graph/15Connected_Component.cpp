//Number of Connected Components in Given Graph
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

void dfs(int node, vector<vector<int>> &graph, unordered_set<int> &visited){
    visited.insert(node);
    for(int neighbour : graph[node]){
        if(visited.count(neighbour) == 0) dfs(neighbour, graph, visited);
    }
}

int connectedComponent(vector<vector<int>> &graph, int vertex){
    unordered_set<int> visited;
    int result = 0;
    for(int i = 0 ; i< vertex ; i++){
        if(visited.count(i) == 0){
            result++;
            dfs(i, graph, visited);
        }
    }
    return result;
}

int main() {
    vector<vector<int>> graph = {{1, 3}, {0, 4}, {5, 6}, {0, 4}, {1, 3}, {2, 6}, {2, 5}}; //Adj List
    cout<<"Number of Connected Graph: "<<connectedComponent(graph, 7)<<endl;
}
