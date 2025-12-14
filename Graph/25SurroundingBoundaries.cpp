//Leetcode 130 Surrounded Regions
#include<iostream>
#include<vector>
using namespace std;

void dfs( int currRow, int currCol, int rows, int cols, vector<vector<int>> &direction, vector<vector<char>> &board){
    if(currRow < 0 || currRow >= rows || currCol < 0 || currCol >= cols){
        return;
    }
    board[currRow][currCol] = 'V'; //marked visited
    for(int d = 0 ; d < 4 ; d++){
        int nr = currRow + direction[d][0];
        int nc = currCol + direction[d][1];
        if(nr >= 0 && nr < rows && nc >=0 && nc < cols && board[nr][nc] != 'X'){
            dfs(nr, nc, rows, cols, direction, board);
        }
    }
}

void solve(vector<vector<char>> &board){
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};//up, down, right, left

    //Horizontal Boundaries
    for(int i = 0 ; i < rows ; i++){
        if(board[i][0] == '0'){
            dfs(i, 0, rows, cols, direction, board);
        }
        if(board[i][cols-1] == '0'){
            dfs(i, cols-1, rows, cols, direction, board);
        }
    }
    //Vertical Boundaries
    for(int j = 1 ; j < cols-1 ; j++){
        if(board[0][j] == '0'){
            dfs(0, j, rows, cols, direction, board);
        }
        if(board[rows-1][j] == '0'){
            dfs(rows-1, j, rows, cols, direction, board);
        }
    }
    for(int r = 0 ; r < rows ; r++){
        for(int c = 0 ; c < cols ; c++){
            if(board[r][c] == '0'){
                board[r][c] = 'X';
            }
            if(board[r][c] == 'V'){
                board[r][c] = '0';
            }
        }
    }
}

void print(vector<vector<char>> grid){
    for(int r = 0 ; r < grid.size() ; r++){
        for(int c = 0 ; c < grid[0].size() ; c++){
            cout<<grid[r][c]<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', '0', '0', 'X'}, {'X', 'X', '0', 'X'}, {'X', '0', 'X', 'X'}};
    solve(board);
    print(board);
}
