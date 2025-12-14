//Topological Sort ----> Kahn's Algorithm
// Directed Acyclic Graph
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

void Topological_sort(vector<vector<int>> directed_graph, int vertex){
    vector<int> indegree(vertex, 0);
    for(int i = 0 ; i < vertex ; i++){
        for(int neighbour : directed_graph[i]){
            indegree[neighbour]++;
        }
    }

    queue<int> qu;
    unordered_set<int> visited;
    for(int i = 0 ; i < vertex ; i++){
        if(indegree[i] == 0){
            qu.push(i);
            visited.insert(i);
        }
    }

    while(qu.size() != 0){
        int node = qu.front();
        cout<<node<<" ";
        qu.pop();
        for(int neighbour : directed_graph[node]){
            if(visited.count(neighbour) == 0){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
}

int main(){
    vector<vector<int>> directed_graph = {{2}, {2, 3}, {4, 6, 5, 3}, {5}, {6}, {6}, {7}, {}};
    int vertex = 8;
    Topological_sort(directed_graph, vertex);
}