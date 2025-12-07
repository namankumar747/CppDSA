//Minimizing Coins
//Problem Link - https://cses.fi/problemset/task/1634
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Tabulation
int main() {
    int n, target;
    cin>>n>>target;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin>>coins[i];
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;

    for (int sum = 1; sum <= target; sum++) {
        for (int coin : coins) {
            if (sum - coin >= 0 && dp[sum - coin] != INT_MAX) {
                dp[sum] = min(dp[sum], 1 + dp[sum - coin]);
            }
        }
    }

    if (dp[target] == INT_MAX)
        cout << -1 << endl;     // CSES requires -1 if not possible
    else
        cout << dp[target] << endl;
}
