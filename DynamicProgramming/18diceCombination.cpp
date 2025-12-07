//Dice Combinations
//Problem Link - https://cses.fi/problemset/task/1633
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

//Memoization
long long diceCombination(int n, vector<long long>& dp){
    if(n == 0) return 1;

    if(dp[n] != -1) return dp[n];

    long long sum = 0;
    for(int i = 1; i <= 6; i++){
        if(n - i >= 0) sum = (sum + diceCombination(n-i, dp))%MOD;
    }
    return dp[n] = sum;
}

int main(){
    int n;
    cin>>n;
    vector<long long> dp(n+1, -1);
    cout<<diceCombination(n, dp)<<endl;
}

//Recurrence Relation: f(n) = sum ( f(n - i) ) where i belongs to { 1, 2, 3, 4, 5, 6 }
//Base Case n == 0 --> 1  
//Base Case n < 0 --> 0
