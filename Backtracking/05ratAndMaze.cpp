#include <iostream>
#include <vector>
using namespace std;

//you are given a grid with '0' as open cell and '1' as blocked cell, rat can move in all four directions (up, down, left, right).
//initially rat is at (0, 0) position. find number of ways to reach the last grid (n-1, n-1)

int ans;
bool canWeGo(vector<vector<int>>& grid, int n, int i, int j){
    return i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0;
}

void f(vector<vector<int>>& grid, int n, int i, int j){
    if(i == n-1 && j == n-1){
        ans += 1;
        return;
    }

    grid[i][j] = 2; //visited

    if(canWeGo(grid, n, i+1, j) == true){ //up
        f(grid, n, i+1, j);
    }
    if(canWeGo(grid, n, i-1, j) == true){ //down
        f(grid, n, i-1, j);
    }
    if(canWeGo(grid, n, i, j+1) == true){ //left
        f(grid, n, i, j+1);
    }
    if(canWeGo(grid, n, i, j-1) == true){ //right
        f(grid, n, i, j-1);
    }

    grid[i][j] = 0;
}

int ratMaze(vector<vector<int>>& grid, int n){
    ans = 0;
    f(grid, n, 0, 0);
    return ans;
}

int main(){
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 1, 0},
        {1, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 0, 0, 0}
    };

    int n = 7;
    cout<<ratMaze(grid, 7)<<endl;
}