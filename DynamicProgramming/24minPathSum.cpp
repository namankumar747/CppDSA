//Leetcode 64. Minimum Path Sum
#include <iostream>
#include <vector>
using namespace std;

//Memoization
int helper(vector<vector<int>>& grid, int sr, int sc, int er, int ec, vector<vector<int>>& dp){
    if(sr > er || sc > ec) return 1e9;
    if(sr == er && sc == ec) return dp[sr][sc] = grid[sr][sc];

    if(dp[sr][sc] != -1) return dp[sr][sc];
    int right = helper(grid, sr, sc + 1, er, ec, dp);
    int down  = helper(grid, sr + 1, sc, er, ec, dp);
    return dp[sr][sc] = grid[sr][sc] + min(right, down);
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(grid, 0, 0, m-1, n-1, dp);
}

int main(){
    vector<vector<int>> grid = {{1,3,1}, {1,5,1}, {4,2,1}};
    cout<<minPathSum(grid)<<endl;
}

//Recurrence Realtion: f(i, j) = grid[i][j] + min( f(i-1, j), f(i, j-1) )
//Base Case: out of grid --> return
// sr == er && sc == ec then grid[sr][sc]