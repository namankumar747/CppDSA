/*
Given a 2D grid (n * m) size, every cell in the grid is marked as "L", "R", "D", "U". character on grid cell denotes if you are atanding on that cell, what direction you can move. Initially you are at (0, 0) and you have to reach (n-1, m-1). Space Complexity should be O(1)
Note: using dfs / bfs uses space of stack / queue
Note: even if you use visited set then it also uses space
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<char>> grid = {{'R', 'R', 'D', 'R'}, {'D', 'L', 'D', 'L'}, {'U', 'D', 'L', 'D'}, {'U', 'R', 'R', 'R'}};
    int n = grid.size();
    int m = grid[0].size();
    int steps = 0;
    int r = 0, c = 0;

    while(steps < n*m){
        if(r == n-1 && c == m-1) break;
        char dir = grid[r][c];
        if(dir == 'R'){
            c += 1;
            if(c >= m) break;
            steps++;
        }
        else if(dir == 'L'){
            c -= 1;
            if(c < 0) break;
            steps++;
        }
        else if(dir == 'U'){
            r -= 1;
            if(r < 0) break;
            steps++;
        }
        else if(dir == 'D'){
            r += 1;
            if(r >= n) break;
            steps++;
        }
    }
    if(steps <= n*m){
        if(r == n-1 && c == m-1) cout<<"Reached Location"<<endl;
        else cout<<"Cant Reach"<<endl;
    }
    else cout<<"Cant Reach"<<endl;
}
// Maximum Steps that i can take while traveling grid is (n*m), if this limit exceeds then definetely there is any cycle