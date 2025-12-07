//Dice Combinations
//Problem Link - https://cses.fi/problemset/task/1633
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

//Tabulation
long long diceCombinations(int n){
    vector<long long> dp(n+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        long long sum = 0;
        for(int j = 1; j <= 6; j++){
            if(i - j >= 0) sum = (sum + dp[i-j])%MOD;
        }
        dp[i] = sum;
    }

    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<diceCombinations(n)<<endl;
}
