//Leetcode 200 Number of Islands
//BFS Traversal
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int numIslands(vector<vector<char>> &grid){
    int rows = grid.size();
    int cols = grid[0].size();
    int cc = 0; // Number of Islands i.e. no of connected components

    for(int r = 0 ; r < rows ; r++){
        for(int c = 0 ; c < cols ; c++){
            if(grid[r][c] == '0'){
                //Its a Water Body
                continue;
            }
            //new unvisited land piece found i.e new connected component
            cc++;
            grid[r][c] = '0';
            queue<pair<int, int>> qu;
            qu.push({r, c});
            while(qu.size() != 0){
                pair<int, int> curr = qu.front();
                qu.pop();
                int currRow = curr.first;
                int currCol = curr.second;
                //check up
                if(currRow-1 >= 0 && grid[currRow-1][currCol] == '1'){
                    qu.push({currRow-1, currCol});
                    grid[currRow-1][currCol] = '0';
                }
                //check down
                if(currRow+1 < rows && grid[currRow+1][currCol] == '1'){
                    qu.push({currRow+1, currCol});
                    grid[currRow+1][currCol] = '0';
                }
                //check left
                if(currCol+1 < cols && grid[currRow][currCol+1] == '1'){
                    qu.push({currRow, currCol+1});
                    grid[currRow][currCol+1] = '0';
                }
                //check Right
                if(currCol-1 >= 0 && grid[currRow][currCol-1] == '1'){
                    qu.push({currRow, currCol-1});
                    grid[currRow][currCol-1] = '0';
                }
            }
        }
    }
    return cc;
}

int main(){
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    cout<<"Number of Islands: "<<numIslands(grid)<<endl;
}
