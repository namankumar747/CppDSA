#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> grid;

bool canPlaceQueen(int row, int col, int n){
    // Column check (Checks rows above the current row)
    for(int i = row - 1; i >= 0; i--){
        if(grid[i][col] == 'Q') return false;
    }
    // Left diagonal check (Up and Left)
    // i decreases, j decreases
    for(int i = row-1, j = col-1; i >= 0 && j >=0; i--, j--){
        if(grid[i][j] == 'Q') return false;

    }
    // Right diagonal check (Up and Right)
    // i decreases, j increases
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
        if(grid[i][j] == 'Q') return false;
        
    }
    return true;
}

void f(int row, int n){
    if(row == n){
        //one possible answer
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout<< grid[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    // Try placing a queen in the current row
    for(int col = 0; col < n; col++){
        if(canPlaceQueen(row, col, n) == true){
            // Place Queen
            grid[row][col] = 'Q';
            // Recurse to the next row
            f(row+1, n);
            // Backtrack: Remove Queen
            grid[row][col] = '.';
        }
    }
}


int main(){
    int n = 8;
    grid.resize(n, vector<char>(n, '.'));
    f(0, n);
}