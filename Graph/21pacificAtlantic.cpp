//Leetcode 417 Pacific Atlantic Water Flow
//bfs
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<bool>> bfs(vector<vector<int>> &heights, queue<pair<int, int>> &qu){
    int rows = heights.size();
    int cols = heights[0].size();
    vector<vector<bool>> visited(rows , vector<bool> (cols, false));
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};//up, down, right, left
    while(qu.size() != 0){
        pair<int, int> curr = qu.front();
        qu.pop();
        int i = curr.first;
        int j = curr.second;
        visited[i][j] = true;
        for(int d = 0 ; d < 4 ; d++){
            int nr = i + direction[d][0];
            int nc = j + direction[d][1];
            if(nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue; //out of grid
            if(visited[nr][nc] == true) continue;
            if(heights[nr][nc] < heights[i][j]) continue;
            qu.push({nr, nc});
        } 
    }
    return visited;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights){
    int rows = heights.size();
    int cols = heights[0].size();
    queue<pair<int, int>> pacificbfs;
    queue<pair<int, int>> atlanticbfs;
    //multisource Bfs
    for(int i = 0 ; i < rows ; i++){
        pacificbfs.push({i, 0});
        atlanticbfs.push({i, cols-1});
    }
    for(int j = 1 ; j < cols ; j++){
        pacificbfs.push({0, j});
    }
    for(int j = 0 ; j < cols-1 ; j++){
        atlanticbfs.push({rows-1, j});
    }
    vector<vector<bool>> pacific = bfs(heights, pacificbfs);
    vector<vector<bool>> atlantic = bfs(heights, atlanticbfs);

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
