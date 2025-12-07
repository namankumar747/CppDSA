//Minimizing Coins
//Problem Link - https://cses.fi/problemset/task/1634
#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

//Recursive Solution
int minimizeCoins(vector<int>& coins, int target){
    if(target == 0) return 0;
    if(target < 0) return INT_MAX;

    int result = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        result = min(result, minimizeCoins(coins, target - coins[i]));
    }
    if(result == INT_MAX) return 0;
    return 1 + result;
}

int main(){
    vector<int> coins = {16, 51, 71};
    int target = 11;

    cout<<minimizeCoins(coins, target)<<endl;
}

//Recurrence Relation: f(n) = 1 + min(f(n-m)) where m is each element of coins array