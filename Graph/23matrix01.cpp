//Leetcode 542 01 Matrix
#include<iostream>
#include<vector>
#include<queue>
#include <climits>
using namespace std;
//multisource bfs
vector<vector<int>> updateMatrix(vector<vector<int>> &mat){
    int rows = mat.size();
    int cols = mat[0].size();
    vector<vector<int>> result(rows, vector<int>(cols, INT_MAX));
    queue<pair<int, int>> qu;

    for(int r = 0 ; r < rows ; r++){
        for(int c = 0 ; c < cols ; c++){
            if(mat[r][c] == 0){
                result[r][c] = 0;
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
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && result[nr][nc] > result[i][j] + 1){//Similar to shortest path (10)
                 result[nr][nc] = result[i][j] + 1;
                 qu.push({nr, nc});
            }
        }
    }
    return result;
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
    vector<vector<int>> mat = {{1, 1, 1, 1, 0, 1, 0}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 1, 1}, {1, 0, 1, 1, 1, 1, 1}};
    //vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> result = updateMatrix(mat);
    print(result);
}
