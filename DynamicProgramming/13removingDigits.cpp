//Removing Digits
//Problem Link - https://cses.fi/problemset/task/1637/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> findDigits(int n){
    vector<int> result;
    while(n > 0){
        if(n%10 != 0) result.push_back(n%10);
        n /= 10;
    }
    return result;
}

//Memoization
int removeDigits(int n, vector<int>& dp){
    if(n == 0) return 0;
    if(n < 10) return 1;

    if(dp[n] != -1) return dp[n];

    vector<int> digits = findDigits(n);

    int result = INT_MAX;
    for(int i = 0; i < digits.size(); i++){
        result = min(result, removeDigits(n - digits[i], dp));
    }

    return dp[n] = 1 + result;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<removeDigits(n, dp)<<endl;
}
//Algorithm: firstly try to write recursion code and find recurrence relation, then apply dp array for memoization
//Recurrence Relation: f(n) = 1 + min(f(n - m)) where m is set of single digit integers of n 
