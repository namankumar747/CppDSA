//Leetcode 200 Number of Islands
//DFS Traversal
#include<iostream>
#include<vector>
using namespace std;

void dfs(int currRow, int currCol, int rows, int cols, vector<vector<char>> &grid){
    if(currRow < 0 || currRow >= rows || currCol < 0 || currCol >= cols || grid[currRow][currCol] != '1'){
        return;
    }
    grid[currRow][currCol] = '0';
    dfs(currRow+1, currCol, rows, cols, grid);//check down
    dfs(currRow-1, currCol, rows, cols, grid);//check up
    dfs(currRow, currCol+1, rows, cols, grid);//check left
    dfs(currRow, currCol-1, rows, cols, grid);//check right
}

int numIslands(vector<vector<char>> &grid){
    int rows = grid.size();
    int cols = grid[0].size();
    int cc = 0;
    for(int r = 0 ; r < rows ; r++){
        for(int c = 0 ; c < cols ; c++){
            if(grid[r][c] == '1'){
                cc++;
                dfs(r, c, rows, cols, grid);
            }
            continue;
        }
    }
    return cc;
}

int main(){
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    cout<<"Number of Islands: "<<numIslands(grid)<<endl;
}
