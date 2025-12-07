//Coins Combinations I
//Problem Link - https://cses.fi/problemset/task/1635
#include <iostream>
#include <vector>
using namespace std;

//Memoization
int coinCombinationI(vector<int>& coins, int target, vector<int>& dp){
    if(target == 0) return 1;

    if(dp[target] != -1) return dp[target];

    int sum = 0;
    for(int i = 0; i < coins.size(); i++){
        if(target - coins[i] >= 0) sum += coinCombinationI(coins, target - coins[i], dp);
    }
    return dp[target] = sum;
}

int main(){
    int n, target;
    cin>>n>>target;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin>>coins[i]
    cout<<coinCombinationI(coins, target)<<endl;
}
