#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

// All Paths Between Two Nodes
void add_edge(vector<list<int>> &graph, int source, int destination, bool bi_dirc = true) {
    graph[source].push_back(destination);
    if (bi_dirc) {
        graph[destination].push_back(source);
    }
}

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
    vector<list<int>> graph;
    int vertex;
    cout << "Enter No Of Vertices: ";
    cin >> vertex;
    graph.resize(vertex, list<int>());
    
    int edges;
    cout << "Enter No Of Edges: ";
    cin >> edges;
    cout << "Enter Edges (source <space> destination)" << endl;
    while (edges--) {
        int s, d;
        cin >> s >> d;
        add_edge(graph, s, d);
    }

    int start, end;
    cout << "Enter start and end nodes: ";
    cin >> start >> end;

    vector<string> ans = AllPath(graph, start, end);
    if (ans.empty()) {
        cout << "No path found" << endl;
    } else {
        cout << "Paths between " << start << " and " << end << ":" << endl;
        Print(ans);
    }

    return 0;
}
