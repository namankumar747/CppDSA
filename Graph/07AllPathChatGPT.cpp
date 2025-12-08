#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

void Print(const vector<string> &arr) {
    for (const string &ele : arr) {
        cout << ele << endl;
    }
}

void dfs(vector<list<int>> &graph, int curr, int end, string s, vector<string> &ans, unordered_set<int> &visited) {
    if (curr == end) {
        s += to_string(curr);
        ans.push_back(s);
        return;
    }
    
    visited.insert(curr);
    s += to_string(curr) + "->";
    
    for (auto neighbour : graph[curr]) {
        if (visited.count(neighbour) == 0) {
            dfs(graph, neighbour, end, s, ans, visited);
        }
    }
    
    visited.erase(curr);
}

vector<string> AllPath(vector<list<int>> &graph, int start, int end) {
    unordered_set<int> visited;
    vector<string> ans;
    dfs(graph, start, end, "", ans, visited);
    return ans;
}

int main() {
    vector<list<int>> graph = {{1, 3}, {0, 2, 4}, {1, 5, 6}, {0, 4}, {1, 3}, {2, 6}, {2, 5}};
    int start = 0, end = 6;

    vector<string> ans = AllPath(graph, start, end);
    if (ans.empty()) {
        cout << "No path found" << endl;
    } else {
        cout << "Paths between " << start << " and " << end << ":" << endl;
        Print(ans);
    }

    return 0;
}