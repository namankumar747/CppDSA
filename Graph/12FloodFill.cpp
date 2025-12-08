//Leetcode 733 Flood Fill
#include<iostream>
#include<vector>
using namespace std;

void PrintGrid(vector<vector<int>> grid){
    int n = grid.size();//rows
    int m = grid[0].size();//column
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void dfs(vector<vector<int>> &image, int currRow, int currCol, int initialColor, int newColor){
    int n = image.size();//rows
    int m = image[0].size();//column

    if(currRow < 0 || currCol < 0 || currRow >= n || currCol >= m){
        return; // Outside the Grid
    }

    //If cell Landed is not same color as initialcolor
    if(image[currRow][currCol] != initialColor) return;

    image[currRow][currCol] = newColor;
    dfs(image, currRow+1, currCol, initialColor, newColor);//down
    dfs(image, currRow-1, currCol, initialColor, newColor);//up
    dfs(image, currRow, currCol+1, initialColor, newColor);//right
    dfs(image, currRow, currCol-1, initialColor, newColor);//left
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color){
    if(image[sr][sc] == color) return image;
    dfs(image, sr, sc, image[sr][sc], color);
    return image;
}

int main(){
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1;//source row
    int sc = 1;//source column
    int color = 2;

    vector<vector<int>> newimage = floodFill(image, sr, sc, color);
    PrintGrid(newimage);
}