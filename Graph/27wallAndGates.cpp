//Leetcode 286 Walls and Gates
#include<iostream>
#include<vector>
#include<queue>
#include <climits>
using namespace std;
//bfs

//0 -> Gate
//-1 -> Obstacle
//INF -> empty space (here we use INT_MAX)

void wallsAndGates(vector<vector<int>> &rooms){
    int rows = rooms.size();
    int cols = rooms[0].size();
    queue<pair<int, int>> qu;
    for(int r = 0 ; r < rows ; r++){
        for(int c = 0 ; c < cols ; c++){
            if(rooms[r][c] == 0){//gate
                qu.push({r, c});
            }
        }
    }

    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};//up, down, right, left
    while(qu.size() != 0){
        pair<int, int> curr = qu.front();
        qu.pop();
        int i = curr.first;
        int j = curr.second;

        for(int d = 0 ; d < 4 ; d++){
            int nr = i + direction[d][0];
            int nc = j + direction[d][1];
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && rooms[nr][nc] > rooms[i][j] + 1 && rooms[nr][nc] != -1){
                rooms[nr][nc] = rooms[i][j] + 1;
                qu.push({nr, nc});
            }
        }
    }
}

void print(vector<vector<int>> grid){
    for(int r = 0 ; r < grid.size() ; r++){
        for(int c = 0 ; c < grid[0].size() ; c++){
            cout<<grid[r][c]<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> rooms = {{INT_MAX, -1, 0, INT_MAX}, {INT_MAX, INT_MAX, INT_MAX, -1}, {INT_MAX, -1, INT_MAX, -1}, {0, -1, INT_MAX, INT_MAX}};
    wallsAndGates(rooms);
    print(rooms);
}
//Similar to 01 Matrix 
