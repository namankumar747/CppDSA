//Minimizing Coins
//Problem Link - https://cses.fi/problemset/task/1634
#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

//chatGPT Solution
int minimizeCoinsGPT(vector<int>& coins, int target, vector<int>& dp){
    if(target == 0) return 0;
    if(target < 0) return INT_MAX;

    if(dp[target] != -1) return dp[target];

    int result = INT_MAX;
    for(int c : coins){
        int sub = minimizeCoinsGPT(coins, target - c, dp);
        if(sub != INT_MAX)
            result = min(result, sub + 1);
    }

    return dp[target] = result;
}

//Memoization
int minimizeCoins(vector<int>& coins, int target, vector<int>& dp){
    if(target == 0) return 0;

    if(dp[target] != -1) return dp[target];

    int result = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        if(target - coins[i] >= 0){
            int subprob = minimizeCoins(coins, target - coins[i], dp);
            if(subprob != INT_MAX) result = min(result, 1 + subprob);
        }
    }
    return dp[target] = result;
}

int main(){
    int n, target;
    cin>>n>>target;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin>> coins[i];
    vector<int> dp(target+1, -1);

    int res = minimizeCoins(coins, target, dp);
    if(res == INT_MAX) cout<<-1<<endl;
    else cout<<res<<endl;
}
