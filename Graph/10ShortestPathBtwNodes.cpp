#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void PrintVector(vector<string> arr) {
    for (string ele : arr) {
        cout << ele << endl;
    }
}

vector<string> findAllShortestPath(vector<vector<int>> graph, int startnode, int endnode, int vertex) {
    vector<string> result;
    queue<vector<int>> qu;
    qu.push({startnode});
    vector<int> LevelVector(vertex, INT_MAX);
    LevelVector[startnode] = 0;

    while (!qu.empty()) {
        vector<int> path = qu.front();
        qu.pop();

        int curr = path.back();

        if (curr == endnode) {
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

        for (int neighbour : graph[curr]) {
            if (LevelVector[neighbour] >= LevelVector[curr] + 1) {//This Logical Statement Plays All the role
                LevelVector[neighbour] = LevelVector[curr] + 1;
                vector<int> newPath = path;
                newPath.push_back(neighbour);
                qu.push(newPath);
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int>> graph = {{1, 3}, {0, 2, 4}, {1, 5, 6}, {0, 4}, {1, 3}, {2, 6}, {2, 5}}; //Adj List
    vector<string> result = findAllShortestPath(graph, 2, 3, 7);
    PrintVector(result);
}
