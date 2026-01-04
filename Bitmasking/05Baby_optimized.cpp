//Problem Link - https://www.spoj.com/problems/BABY/
#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
using namespace std;

vector<int> dp;
int minCost(int row, int mask, int n, vector<vector<int> >& cost){
    if(row == n) return 0;

    if(dp[mask] != -1) return dp[mask];
    int ans = INT_MAX;
    for(int col = 0; col < n; col++){
        if((mask & (1 << col)) == 0){
            int newMask = mask | (1 << col);
            ans = min(ans, cost[row][col] + minCost(row+1, newMask, n, cost));
        }
    }
    return dp[mask] = ans;
}

int main(){
    while(true){
        int n;
        cin>>n;
        if(n == 0) break;

        vector<int> baby(n);
        vector<int> valid(n);

        for(int i = 0; i < n; i++) cin>>baby[i];
        for(int i = 0; i < n; i++) cin>>valid[i];

        vector<vector<int> > cost(n, vector<int>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cost[i][j] = abs(i - j) + abs(baby[i] - valid[j]);
        }

        dp.assign(1 << n, -1);
        cout<<minCost(0, 0, n, cost)<<endl;
    }
}
//first create cost array to save distances of every valid position from every initail position
// after that logic is same as travelling salesman problem