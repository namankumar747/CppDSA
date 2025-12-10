//Leetcode 1034. Coloring A Border
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> internalNode;

void dfs(vector<vector<int>>& grid, int r, int c, int newColor, int originalColor){
    if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return;
    if(grid[r][c] != originalColor) return;

    grid[r][c] = -newColor;
    dfs(grid, r+1, c, newColor, originalColor);
    dfs(grid, r-1, c, newColor, originalColor);
    dfs(grid, r, c+1, newColor, originalColor);
    dfs(grid, r, c-1, newColor, originalColor);

    if(!(r == 0 || c == 0 || r == grid.size()-1 || c == grid[0].size()-1 || grid[r+1][c] != -newColor || grid[r-1][c] != -newColor || grid[r][c+1] != -newColor || grid[r][c-1] != -newColor)){
        internalNode.push_back({r, c});
    }
}

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    int originalColor = grid[row][col];
    if(originalColor == color) return grid;
    dfs(grid, row, col, color, originalColor);
    for(auto p : internalNode){
        int i = p.first;
        int j = p.second;
        grid[i][j] = originalColor;
    }
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] < 0) grid[i][j] *= -1;
        }
    }
    return grid;
}

int main(){
    vector<vector<int>> grid = { {1,1,1,1,1}, {1,2,2,2,1}, {1,2,2,2,1}, {1,2,2,2,1}, {1,1,1,1,1} };
    int row = 2, col = 2;
    int color = 9;
    vector<vector<int>> res = colorBorder(grid, row, col, color);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[0].size(); j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
