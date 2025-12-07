//Leetcode 509. Fibonacci Number
#include <iostream>
#include <vector>  
using namespace std;

//T.C: O(n)
//S.C: O(n) (dp array)
//Tabulation, iterative approach, bottom-up
int fib(int n) {
    if(n <= 1) return n;
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n = 5;
    cout << fib(n) << endl;
}