//Leetcode 994 Rotting Oranges
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int orangesRotting(vector<vector<int>> &grid){
    queue<pair<int, int>> qu;
    int freshoranges = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    for(int r = 0 ; r < rows ; r++){
        for(int c = 0 ; c < cols ; c++){
            if(grid[r][c] == 1) freshoranges++;
            else if(grid[r][c] == 2) qu.push({r, c});// multi sourse bfs
        }
    }
    qu.push({-1, -1});
    int mins = 0;
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};// up, down, left, right

    while(qu.size() != 0){
        pair<int, int> curr = qu.front();
        qu.pop();
        int i = curr.first;
        int j = curr.second;

        if(i == -1 && j == -1){
            if(qu.size() != 0){
                mins++;
                qu.push({-1, -1});
            }
            else break;
        }
        else{
            for(int d = 0 ; d < 4 ; d++){// going in all direction
                int nr = i + direction[d][0];
                int nc = j + direction[d][1];
                if(nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue; //out of grid
                if(grid[nr][nc] == 2 || grid[nr][nc] == 0) continue;//Visited or empty cell
                freshoranges--;
                grid[nr][nc] = 2;
                qu.push({nr, nc});
            }
        }
    }
    return (freshoranges == 0)? mins : -1;
}

int main(){
    vector<vector<int>> grid = {{2,1,1}, {1,1,0}, {0,1,1}};
    cout<<"Number of Minutes: "<<orangesRotting(grid)<<endl;
}
