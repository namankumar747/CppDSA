//Leetcode 417 Pacific Atlantic Water Flow
//dfs
#include<iostream>
#include<vector>
using namespace std;

void dfs(int currRow, int currCol, int rows, int cols, vector<vector<int>> heights, vector<vector<int>> &direction, vector<vector<bool>> &visited){
    if(currRow < 0 || currRow >= rows || currCol < 0 || currCol >= cols) return;
    if(visited[currRow][currCol] == true) return;

    visited[currRow][currCol] = true;
    for(int d = 0 ; d < 4 ; d++){
        int nr = currRow + direction[d][0];
        int nc = currCol + direction[d][1];
         if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && heights[nr][nc] >= heights[currRow][currCol]) {
            dfs(nr, nc, rows, cols, heights, direction, visited);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights){
    int rows = heights.size();
    int cols = heights[0].size();
    vector<vector<bool>> pacific(rows , vector<bool> (cols, false));
    vector<vector<bool>> atlantic(rows , vector<bool> (cols, false));
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};//up, down, right, left
    //Multidource dfs
    for(int i = 0 ; i < rows ; i++){
        dfs(i, 0, rows, cols, heights, direction, pacific);
        dfs(i, cols-1, rows, cols, heights, direction, atlantic);
    }
    for(int j = 1 ; j < cols ; j++){
        dfs(0, j, rows, cols, heights, direction, pacific);
    }
    for(int j = 0 ; j < cols-1 ; j++){
        dfs(rows-1, j, rows, cols, heights, direction, atlantic);
    }
    vector<vector<int>> result;
    for(int r = 0; r < rows ; r++){
        for(int c = 0 ; c < cols ; c++){
            if(pacific[r][c] == true && atlantic[r][c] == true){
                result.push_back({r, c});
            }
        }
    }
    return result;
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
