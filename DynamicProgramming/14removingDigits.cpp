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

//Tabulation
int removeDigits(int n){
    if(n == 0) return 0;
    if(n < 10) return 1;

    vector<int> dp(n+1);
    for(int i = 0; i <= n; i++){
        if(i == 0) dp[i] = 0;
        else if(i < 10) dp[i] = 1;
        else{
            vector<int> digits = findDigits(i);
            int result = INT_MAX;
            for(int j = 0; j < digits.size(); j++) result = min(result, dp[i - digits[j]]);
            dp[i] = 1 + result;
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<removeDigits(n)<<endl;
}

//Algorithm: firstly try to write recursion code and find recurrence relation, then apply dp array for tabulation
