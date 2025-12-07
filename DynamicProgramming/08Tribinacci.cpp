// Leetcode 1137. N-th Tribonacci Number
#include <iostream>
#include <vector>
using namespace std;

//Tabulation
int tribonacci(int n) {
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    vector<int> dp(n+1, -1);
    dp[0] = 0, dp[1] = 1, dp[2] = 1;
    for(int i = 3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    return dp[n];
}

int main(){
    int n = 25;
    cout << tribonacci(n) << endl;
}

// Algorithm: Same as Fabonacci number but sum of last three numbers
