#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> grid;
int col_mask;
int r_d_mask;
int l_d_mask;

bool canPlaceQueen(int row, int col, int n){
    if((col_mask & (1 << col)) != 0) return false;
    if((r_d_mask & (1 << (row + col))) != 0) return false;
    if((l_d_mask & (1 << (row - col + (n - 1)))) != 0) return false;
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

    for(int col = 0; col < n; col++){
        if(canPlaceQueen(row, col, n) == true){

            grid[row][col] = 'Q';
            col_mask = (col_mask | (1 << col));
            r_d_mask = (r_d_mask | (1 << (row + col)));
            l_d_mask = (l_d_mask | (1 << (row - col + (n - 1))));

            f(row+1, n);

            col_mask = (col_mask & (~(1 << col)));
            r_d_mask = (r_d_mask & (~(1 << (row + col))));
            l_d_mask = (l_d_mask & (~(1 << (row - col + (n - 1))))); // Adjusted
            grid[row][col] = '.';
        }
    }
}

int main(){
    int n = 5;
    grid.resize(n, vector<char>(n, '.'));
    col_mask = r_d_mask = l_d_mask = 0;
    f(0, n);
}
