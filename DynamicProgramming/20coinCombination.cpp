//Coins Combinations I
//Problem Link - https://cses.fi/problemset/task/1635
#include <iostream>
#include <vector>
using namespace std;

//Recursive Solution
int coinCombinationI(vector<int>& coins, int target){
    if(target == 0) return 1;

    int sum = 0;
    for(int i = 0; i < coins.size(); i++){
        if(target - coins[i] >= 0) sum += coinCombinationI(coins, target - coins[i]);
    }
    return sum;
}

int main(){
    vector<int> coins = {2, 3, 5};
    int target = 9;
    cout<<coinCombinationI(coins, target)<<endl;
}

//Recurrence Relation: f(n) = sum(f(n-i)) where i belongs to element in coins array
//Base Case n == 0 --> 1
//Base Case n < 0 --> 0
