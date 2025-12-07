#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Tabulation
int minSteps(int n){
    if(n == 0 || n == 1) return 0;
    if(n == 2 || n == 3) return 1;
    vector<int> dp(n+1);
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= n; i++){
        int sub1 = dp[i-1];
        int div2 = (i % 2 == 0) ? dp[i/2] : INT_MAX;
        int div3 = (i % 3 == 0) ? dp[i/3] : INT_MAX;
        dp[i] = 1 + min(sub1, min(div2, div3));
    }
    return dp[n];
}

int main(){
    int n = 10;
    cout << minSteps(n) << endl;
}