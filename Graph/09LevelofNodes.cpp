#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<climits>
using namespace std;

void PrintVector(vector<int> arr){
    int n = arr.size();
    for(int i = 0 ; i < n ; i++){
        cout<<i<<" -> "<<arr[i]<<endl;
    }
}

void bfs(vector<vector<int>> graph, int startNode, int vertex, vector<int> &LevelVector){
    queue<int> qu;
    unordered_set<int> visited;
    qu.push(startNode);
    visited.insert(startNode);
    LevelVector.resize(vertex, INT_MAX);
    LevelVector[startNode] = 0;

    while(qu.size() != 0){
        int curr = qu.front();
        qu.pop();
        for(int neighbour : graph[curr]){
            if(visited.count(neighbour) == 0){
                qu.push(neighbour);
                visited.insert(neighbour);
                LevelVector[neighbour] = LevelVector[curr] + 1;
            }
        }
    }
}

int main(){
    vector<vector<int>> graph = {{1, 3}, {0, 2, 4}, {1, 5, 6}, {0, 4}, {1, 3}, {2, 6}, {2, 5}};//Adj List
    vector<int> LevelVector;
    bfs(graph, 0, 7, LevelVector);
    PrintVector(LevelVector);

}
