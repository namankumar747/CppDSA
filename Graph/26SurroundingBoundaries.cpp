//Leetcode 130 Surrounded Regions
#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<char>>& board, int currRow, int currCol){
    int rows = board.size();
    int cols = board[0].size();

    if(currRow < 0 || currCol < 0 || currRow >= rows || currCol >= cols) return;
    if(board[currRow][currCol] == 'X' || board[currRow][currCol] == 'V') return;

    board[currRow][currCol] = 'V';
    dfs(board, currRow+1, currCol);
    dfs(board, currRow-1, currCol);
    dfs(board, currRow, currCol+1);
    dfs(board, currRow, currCol-1);
}

void solve(vector<vector<char>>& board) {
    int rows = board.size();
    int cols = board[0].size();
    if(board.empty() || board[0].empty()) return;
    
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            if(r == 0 && board[r][c] == 'O') dfs(board, r, c);
            else if(r == rows-1 && board[r][c] == 'O') dfs(board, r, c);
            else if(c == 0 && board[r][c] == 'O') dfs(board, r, c);
            else if(c == cols-1 && board[r][c] == 'O') dfs(board, r, c);
        }
    }
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            if(board[r][c] == 'O') board[r][c] = 'X';
            if(board[r][c] == 'V') board[r][c] = 'O';
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

//Apply dfs and mark those connected component with 'V' that have a boundary 'O' 
//when all dfs is done, then traverse through the grid and mark 'O' with 'X' and 'V' back to 'O'
