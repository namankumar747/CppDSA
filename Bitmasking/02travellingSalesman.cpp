#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int grid[4][4] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};

int dp[10][(1<< 10)];
int tsp(int curr, int mask, int n){
    if(mask == ((1 << n) - 1)) return grid[curr][0]; // distance between current node and "0" node
    // mask == "1111" means all node is visited, in that case return distance between curr node and 0 node
    if(dp[curr][mask] != -1) return dp[curr][mask]; // memoization

    int ans = INT_MAX;
    for(int neigh = 0; neigh < n; neigh++){
        if((mask & (1 << neigh)) == 0) ans = min(ans, grid[curr][neigh] + tsp(neigh, (mask | (1 << neigh)), n));
        
    }
    return dp[curr][mask] = ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    cout<<tsp(0, 1, 4)<<endl;
}

// Recurrence Realtion => f(curr, mask) = minof: grid[curr][neigh] + f(neigh, (mask | (1 << neigh))) where neigh from 0 to n-1
// base case => if mask == "1111" means all node are visited then in that case return distance between curr node and 0 node
