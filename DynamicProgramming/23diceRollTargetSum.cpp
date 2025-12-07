//Leetcode 1155. Number of Dice Rolls With Target Sum
#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

long long roll(int n, int k, int t, vector<vector<long long>>& dp){
    if(n == 0 && t == 0) return 1;
    if(n == 0) return 0;

    if(dp[n][t] != -1) return dp[n][t];

    long long sum = 0;
    for(int i = 1; i <= k; i++){
        if(t- i >= 0) sum = (sum + roll(n-1, k, t - i, dp))%MOD;
    }
    return dp[n][t] = sum;
}

int numRollsToTarget(int n, int k, int target) {
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, -1));
    return roll(n, k, target, dp);
}

int main(){
    int n = 30, k = 30, target = 500;
    cout<<numRollsToTarget(n, k, target)<<endl;
}

//Recurrence Relation f(n, k, t) = sumof f(n-1, k, t - v),   v --> (1, k)