#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

void dfs(vector<list<int>> graph, int curr, int end, string s, vector<string> &ans, unordered_set<int> &visited){
    string a = to_string(curr);
    if(curr == end){
        s = s + a;
        ans.push_back(s);
        return;
    }
    visited.insert(curr);
    for(auto neighbour : graph[curr]){
        if(visited.count(neighbour) == 0){
            dfs(graph, neighbour, end, s+a+"->", ans, visited);
        }
    }
    visited.erase(curr);
    
}

vector<string> AllPath(vector<list<int>> graph, int curr, int end){
    unordered_set<int> visited;
    vector<string> ans;
    dfs(graph, curr, end, "", ans, visited);
    return ans;
}

int main(){
    vector<list<int>> graph = {{1, 3}, {0, 2, 4}, {1, 5, 6}, {0, 4}, {1, 3}, {2, 6}, {2, 5}};
    vector<string> arr = AllPath(graph, 0, 6);
    for(string ele : arr){
        cout<<ele<<endl;
    }
    cout<<endl;
}
