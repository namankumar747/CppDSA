//Coins Combinations I
//Problem Link - https://cses.fi/problemset/task/1635
#include <iostream>
#include <vector>
using namespace std;

//Tabulation
int coinCombinationI(vector<int>& coins, int target){
    vector<int> dp(target+1, -1);

    dp[0] = 1;
    for(int i = 1; i <= target; i++){
        int sum = 0;
        for(int j = 0; j < coins.size(); j++){
            if(i - coins[j] >= 0) sum += dp[i - coins[j]];
        }
        dp[i] = sum;
    }
    if(dp[target] == 0) return -1;
    return dp[target];
}

int main(){
    int n, target;
    cin>>n>>target;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin>>coins[i]
    cout<<coinCombinationI(coins, target)<<endl;
}
