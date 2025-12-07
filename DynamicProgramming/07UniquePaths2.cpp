//Leetcode 63. Unique Paths II
#include <iostream>
#include <vector>
using namespace std;

//Tabulation
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if(m == 1 && n == 1 && obstacleGrid[0][0] == 1) return 0;
    if(m == 1 && n == 1 && obstacleGrid[0][0] == 0) return 1;
    if (obstacleGrid[0][0] == 1) return 0;


    bool flagFirstRow = false;
    bool flagFirstCol = false;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(obstacleGrid[i][j] == 1) obstacleGrid[i][j] = -1;
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) continue;
            if(i == 0){
                if(obstacleGrid[i][j] == -1){
                    flagFirstRow = true;
                    obstacleGrid[i][j] = 0;
                }
                else if(flagFirstRow == false) obstacleGrid[i][j] = 1;
                else if(flagFirstRow == true) obstacleGrid[i][j] = 0;
            }
            else if(j == 0){
                if(obstacleGrid[i][j] == -1){
                    flagFirstCol = true;
                    obstacleGrid[i][j] = 0;
                }
                else if(flagFirstCol == false) obstacleGrid[i][j] = 1;
                else if(flagFirstCol == true) obstacleGrid[i][j] = 0;
            }
            else{
                if(obstacleGrid[i][j] == -1) obstacleGrid[i][j] = 0;
                else obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
    }
    return obstacleGrid[m-1][n-1];
}

int main(){
    vector<vector<int>> obstacleGrid = { {0,0,0}, {0,1,0}, {0,0,0}};
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
}

/*
1. Precheck: If the start cell obstacleGrid[0][0] is an obstacle, return 0. Handle the special 1x1 grid cases explicitly.

2. Mark obstacles: Replace every 1 in the grid with -1 as a marker for obstacles (to distinguish them from computed path counts).

3. First row / first column handling: Use two boolean flags flagFirstRow and flagFirstCol to record if an obstacle has already been encountered in the first row or first column. While iterating:
    1. For cells in the first row (i == 0): if you hit an obstacle, set the flag and store 0 for that cell; otherwise store 1 if no earlier obstacle in that row, or 0 if an earlier obstacle exists (because any cell after an obstacle on the same row is unreachable).
    2. For cells in the first column (j == 0): analogous handling with flagFirstCol.
4. General cells: For other cells (i > 0 and j > 0):
    1. If the cell is an obstacle (-1), set it to 0 (no paths through it).
    2. Otherwise set obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1] (sum of ways from top and left).
5. Result: After filling the grid, return obstacleGrid[m-1][n-1] (number of unique paths to bottom-right).
*/
