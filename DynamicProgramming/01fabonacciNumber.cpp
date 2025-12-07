//Leetcode 509. Fibonacci Number

//Recursion + Memoization
//T.C: O(n)
//S.C: O(n) + O(n) (recursion stack space + dp array)
#include <iostream>
#include <vector>
using namespace std;

int fabo(int n, vector<int>& dp){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fabo(n-1, dp) + fabo(n-2, dp);
}

int fib(int n) {
    vector<int> dp(n+1, -1);
    return fabo(n, dp);
}

int main(){
    int n = 5;
    cout << fib(n) << endl;
}

/*
1. Create DP Array: Initialize a vector dp of size n+1 filled with -1 to store computed results.
2. Base Case: If n ≤ 1, return n directly (F(0) = 0, F(1) = 1).
3. Check Memoization: If dp[n] is already computed (not -1), return the cached result.
4. Recursive Computation: Otherwise, calculate dp[n] = fabo(n-1, dp) + fabo(n-2, dp):
    1. Recursively find the (n-1)th Fibonacci number
    2. Recursively find the (n-2)th Fibonacci number
    3. Add them together and store the result in dp[n]
5. Return: Return the computed Fibonacci number.
*/