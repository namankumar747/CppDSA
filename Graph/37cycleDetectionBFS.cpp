#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>>& graph, int src, vector<bool>& visited){
    queue<pair<int, int>> qu;
    qu.push({src, -1});
    visited[src] = true;
    while(qu.size() != 0){
        pair<int, int> curr = qu.front();
        int sr = curr.first; //source
        int pr = curr.second; //parent
        qu.pop();
        for(int neighbour : graph[sr]){
            if(visited[neighbour] == true && neighbour != pr) return true; //cycle found
            if(visited[neighbour] == false){
                visited[neighbour] = true;
                qu.push({neighbour, sr});
            }
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& graph){
    int vertex = graph.size();
    vector<bool> visited(vertex, false);
    for(int i = 0; i < vertex; i++){
        if(visited[i] == false){
            bool res = bfs(graph, i, visited);
            if(res == true) return true;
        }
    }
    return false;
} 

int main(){
    vector<vector<int>> graph = {{1, 2, 3}, {0}, {0}, {0, 4}, {3, 5}, {4, 6}, {3, 5, 7}, {6, 8, 9}, {7}, {7}};
    if(isCycle(graph) == true) cout<<"Cycle Detected"<<endl;
    else cout<<"No Cycle"<<endl;
}
//If neighbour is visited and neighbour is its parent → cycle found
//If neighbour is unvisited → visit it
