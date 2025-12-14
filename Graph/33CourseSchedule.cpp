//Leetcode 210. Course Schedule II
//Straight Forward Topological sort
//Similar Question: Leetcode 207. Course Schedule
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses); //creating graph adjacency list using given edge array
    int n = prerequisites.size();
    for(int i = 0; i < n; i++){
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        graph[b].push_back(a);
    }
    //from here straight forward topological sort algo
    vector<int> indegree(numCourses, 0);
    for(int i = 0; i < numCourses; i++){
        for(int neighbour : graph[i]) indegree[neighbour]++;
    }
    queue<int> qu;
    unordered_set<int> visited;
    for(int i = 0; i < numCourses; i++){
        if(indegree[i] == 0){
            qu.push(i);
            visited.insert(i);
        }
    }
    vector<int> res;
    while(qu.size() != 0){
        int currNode = qu.front();
        res.push_back(currNode);
        qu.pop();
        for(int neighbour : graph[currNode]){
            if(visited.count(neighbour) == 0){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
    // check if res array all the nodes ? if yes return 'res', otherwise return empty array
    if(res.size() != numCourses) return {};
    else return res;
}

int main(){
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> res = findOrder(numCourses, prerequisites);
    for(int ele : res) cout<<ele<<" ";
    cout<<endl;
}