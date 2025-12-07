//Leetcode 746. Min Cost Climbing Stairs
#include <iostream>
#include <vector>
using namespace std;

//T.C: O(n)
//S.C: O(1)
//Tabulation
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    for(int i = 2; i < n; i++){
        cost[i] += min(cost[i-1], cost[i-2]);
    }
    return min(cost[n-1], cost[n-2]);
}

int main(){
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost) << endl;
}

/*
1. In-Place DP Update: Instead of using a separate DP array, update the input cost array to store the minimum costs directly.
2. Iterative Computation: Start from step 2 and iterate to the last step, updating each step's cost as:
    1. cost[i] = cost[i] + min(cost[i-1], cost[i-2])
    2. This means: cost to reach this step + minimum of (cost to reach from previous step OR cost to reach from two steps back)
3. Final Calculation: Return the minimum of the last two steps:
    1. min(cost[n-1], cost[n-2])
    2. (You can reach the top by stepping on either of the last two steps)
*/