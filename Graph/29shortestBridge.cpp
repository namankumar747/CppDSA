//Leetcode Shortest Bridge
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int sr, int sc, queue<pair<int, int>>& qu, vector<vector<int>>& dist){
        int rows = grid.size();
        int cols = grid[0].size();
        if(sr < 0 || sc < 0 || sr >= rows || sc >= cols || grid[sr][sc] != 1) return;
        grid[sr][sc] = -1;

        dfs(grid, sr+1, sc, qu, dist);
        dfs(grid, sr-1, sc, qu, dist);
        dfs(grid, sr, sc+1, qu, dist);
        dfs(grid, sr, sc-1, qu, dist);

        if((sr+1 < rows && grid[sr+1][sc] == 0) || (sr-1 >= 0 && grid[sr-1][sc] == 0) || (sc+1 < cols && grid[sr][sc+1] == 0) || (sc-1 >= 0 && grid[sr][sc-1] == 0)){
            qu.push({sr, sc});
            dist[sr][sc] = 0;
        }//this if condition checks adjacent cell with 0

    } //dfs for marking island 1 with -1 and storing those grid coordinates in queue that have grid[i][j] == 0 as adjacent cell

    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, -2));
        queue<pair<int, int>> qu;

        bool flag = false; //this flag is to break both the loop it stores true if first island found
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1){
                    dfs(grid, r, c, qu, dist);
                    flag = true;
                    break;
                }
            }
            if(flag == true) break; //once first island found apply dfs to mark that island with -1 and break both outer and inner loop
        }

        while(qu.size() != 0){ // apply bfs on queue cells and find shortest distance
            pair<int, int> curr = qu.front();
            qu.pop();
            int i = curr.first;
            int j = curr.second;
            vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
            for(int d = 0; d < 4; d++){
                int nr = i + dir[d][0];
                int nc = j + dir[d][1];
                if(nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue; // out of grid
                if(grid[nr][nc] == -1) continue; //island 1 itself
                if(grid[nr][nc] == 1) return dist[i][j]; //reached the island 2
                if(grid[nr][nc] == 0 && dist[nr][nc] == -2){ // Expand only through unvisited water
                    dist[nr][nc] = dist[i][j] + 1;
                    qu.push({nr, nc});
                }
            }
        }
        return -1;
    }
};
//Inportant Solution Revise Repeately
int main(){
    Solution s;
    vector<vector<int>> grid = {{1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}};
    cout<<s.shortestBridge(grid)<<endl;
}
