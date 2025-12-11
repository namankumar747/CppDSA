/Leetcode 417 Pacific Atlantic Water Flow
//dfs
//Wrriten by me
#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>& heights, int currRow, int currCol, vector<vector<bool>>& visited){
    int rows = heights.size();
    int cols = heights[0].size();
    if(currRow < 0 || currCol < 0 || currRow >= rows || currCol >= cols) return;
    if(visited[currRow][currCol] == true) return;
    visited[currRow][currCol] = true;

    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(int d = 0; d < 4; d++){
        int nr = currRow + dir[d][0];
        int nc = currCol + dir[d][1];
        if(nr >= 0 && nc >= 0 && nr <= rows-1 && nc <= cols-1 && heights[nr][nc] >= heights[currRow][currCol]){
            dfs(heights, nr, nc, visited);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int rows = heights.size();
    int cols = heights[0].size();
    vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
    vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

    for(int j = 0; j < cols; j++){
        dfs(heights, 0, j, pacific); //upper
        dfs(heights, rows-1, j, atlantic); //lower
    }
    for(int i = 0; i < rows; i++){
        dfs(heights, i, 0, pacific); //left
        dfs(heights, i, cols-1, atlantic); //right
    }
    vector<vector<int>> res;
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            if(pacific[r][c] == true && atlantic[r][c] == true) res.push_back({r, c});
        }
    }
    return res;
}

void print(vector<vector<int>> arr){
    for(int r = 0 ; r < arr.size() ; r++){
        cout<<"{ ";
        for(int c = 0 ; c < arr[0].size() ; c++){
            cout<<arr[r][c]<<" ";
        }
        cout<<"} ";
    }
}

int main(){
    vector<vector<int>> heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    vector<vector<int>> result = pacificAtlantic(heights);
    print(result);
}

//Firstly create two bool 2d grid for pacific and atlantic initially false
//use dfs or bfs to mark "true" for those grids that can be reachable from pacific or atlantic ocean
//use left and upper boundary cell for multisource bfs/dfs for pacific ocean and similarly right and lower boundary for atlantic ocean
// once dfs/bfs is applied for both pacific and atlantic, return only those cell (i, j), which is commonly true in both grids
