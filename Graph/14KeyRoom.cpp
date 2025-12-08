//Leetcode 841 Keys and Rooms
#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

bool canVisitAllRoom(vector<vector<int>> &rooms){
    unordered_set<int> visited;
    queue<int> qu;
    qu.push(0);
    visited.insert(0);
    
    while(qu.size() != 0){
        int curr = qu.front();
        qu.pop();
        for(int neighbour : rooms[curr]){
            if(visited.count(neighbour) == 0){
                qu.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
    return (visited.size() == rooms.size());
}

int main(){
    vector<vector<int>> rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
    cout<<canVisitAllRoom(rooms)<<endl;
}