//Problem Link - https://atcoder.jp/contests/dp/tasks/dp_o
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define mod 1000000007

int dp[22][1 << 22];
int f(int i, int mask, int n, vector<vector<int>>& c){
    if(i == n+1){
        if(mask == 0) return 1; // if crossed the grid and mask is zero, then 1 possible answer
        return 0;
    }
    if(dp[i][mask] != -1) return dp[i][mask]; // memoization
    int ans = 0;
    for(int w = 1; w <= n; w++){
        bool avail = (((1 << (w-1)) & mask) == 0) ? 0 : 1;
        // avail == 0 means particular w is occupied, avail == 1 means particular w is unoccupied
        // 0 => false , 1 => true
        if(avail && c[i][w]){
            ans = ((ans % mod) + f(i + 1, (mask ^ (1 << (w - 1))), n, c) % mod) % mod;
        }
        
    }
    return dp[i][mask] = ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> c(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>c[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout<< f(1, (1 << n) - 1, n, c)<<endl;
}

//Recurrence Relation => f(row, mask) = sumof: f(row+1, (mask ^ (1 << (w - 1))))  from row = 1 to n
//base condition => if row == n+1 and mask == 0 then one possible answer,  if row == n+1 and mask != 0 then no possible answer
