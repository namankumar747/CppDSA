#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

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
    vector<list<int>> graph = {{1, 3}, {0, 2, 4}, {1, 5, 6}, {0, 4}, {1, 3}, {2, 6}, {2, 5}};
    if(isAnyPath(graph, 0, 5) == true) cout<<"Path Exists"<<endl;\
    else cout<<"Path Not Exist"<<endl;
}