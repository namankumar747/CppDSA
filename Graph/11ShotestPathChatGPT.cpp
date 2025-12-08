#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void PrintPaths(const vector<string>& paths) {
    for (const string& path : paths) {
        cout << path << endl;
    }
}

vector<string> findAllShortestPaths(vector<vector<int>>& graph, int startNode, int endNode, int vertex) {
    vector<string> result;
    queue<vector<int>> q;
    unordered_map<int, int> minDist;
    minDist[startNode] = 0;

    q.push({startNode});

    while (!q.empty()) {
        vector<int> path = q.front();
        q.pop();

        int currNode = path.back();

        if (currNode == endNode) {
            // Convert the path to a string format.
            string pathStr = "";
            for (int i = 0; i < path.size(); ++i) {
                pathStr += to_string(path[i]);
                if (i != path.size() - 1) {
                    pathStr += "->";
                }
            }
            result.push_back(pathStr);
            continue;
        }

        for (int neighbour : graph[currNode]) {
            if (minDist.find(neighbour) == minDist.end() || minDist[neighbour] == minDist[currNode] + 1) {
                vector<int> newPath = path;
                newPath.push_back(neighbour);
                q.push(newPath);
                minDist[neighbour] = minDist[currNode] + 1;
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> graph = {{1, 3}, {0, 2, 4}, {1, 5, 6}, {0, 4}, {1, 3}, {2, 6}, {2, 5}}; // Adj List
    int startNode = 2, endNode = 3;

    vector<string> paths = findAllShortestPaths(graph, startNode, endNode, 7);
    PrintPaths(paths);

    return 0;
}
