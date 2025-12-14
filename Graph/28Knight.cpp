//Problem Link - https://www.spoj.com/problems/NAKANJ/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int sx, int sy, int ex, int ey){
    if (sx == ex && sy == ey) return 0;
    vector<vector<int>> grid(8, vector<int>(8, -1));
    vector<vector<int>> dir = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}}; //order matter
    queue<pair<int, int>> qu;
    qu.push({sx, sy});
    grid[sx][sy] = 0;
    while(qu.size() != 0){
        pair<int, int> curr = qu.front();
        qu.pop();
        int i = curr.first;
        int j = curr.second;
        for(int d = 0; d < 8; d++){
            int nx = i + dir[d][0];
            int ny = j + dir[d][1];
            if(nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && grid[nx][ny] == -1){
                grid[nx][ny] = grid[i][j] + 1;
                if (nx == ex && ny == ey) return grid[nx][ny];
                qu.push({nx, ny});
            }
        }
    }
    return grid[ex][ey];
}
//dfs cannot be used in case of finding shortest distance
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcase;
    cin>>testcase;
    for(int i = 0; i < testcase; i++){
        string start, dest;
        cin >> start >> dest;
        int sx = start[0] - 'a';
        int sy = start[1] - '1';
        int ex = dest[0] - 'a';
        int ey = dest[1] - '1';
        cout<<bfs(sx, sy, ex, ey)<<endl;
    }
}
