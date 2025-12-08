#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<queue>
using namespace std;


void bfsTraversal(vector<list<int>> graph, int startNode){
    unordered_set<int> visited;
    queue<int> q;
    q.push(startNode);
    visited.insert(startNode);

    while(q.size() != 0){
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";

        for(auto neighbour : graph[curr]){
            if(visited.count(neighbour) == 0){
                q.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
}


int main(){
    vector<list<int>> graph = {{1, 3}, {0, 2, 4}, {1, 5, 6}, {0, 4}, {1, 3}, {2, 6}, {2, 5}};
    bfsTraversal(graph, 0);  
}