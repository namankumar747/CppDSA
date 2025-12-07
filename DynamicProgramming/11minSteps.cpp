#include <iostream>
#include <climits>
#include <vector>
using namespace std;

/*
You are given a number 'n', you can perform any of the following steps any number of times:
    1. Subtract 1 from 'n'.
    2. If 'n' is divisible by 2, divide 'n' by 2.
    3. If 'n' is divisible by 3, divide 'n' by 3.
Your goal is to reduce the number 'n' to 0 in the minimum number of steps. 
Write a function that returns the minimum number of steps required to reduce 'n' to 1.
*/

//Memoization
int minSteps(int n, vector<int>& dp){
    if(n == 1) return 0;
    if(n ==2 || n == 3) return 1;
    if(dp[n] != -1) return dp[n];

    return dp[n] = (1 + min( minSteps(n-1, dp), min( n%2 == 0 ? minSteps(n/2, dp) : INT_MAX, n%3 == 0 ? minSteps(n/3, dp) : INT_MAX )) );
}

int main(){
    int n = 10;
    vector<int> dp(n+1, -1);
    cout << minSteps(n, dp) << endl;
}
//Algorithm: Try to solve using recursion and find recurrence relation, then apply dp array for memoization to store results of subproblems.
//Once Recusrrence relation is found, you can solve the code using memoization or tabulation both.
