//Leetcode 746. Min Cost Climbing Stairs
#include <iostream> 
#include <vector>  
using namespace std;

//T.C: O(n)
//S.C: O(n) + O(n) (dp array + recursion stack)
//Memoization, recursive approach, top-down
int helper(vector<int>& cost, int i, vector<int>& dp){
    if(i == 0 || i == 1) return cost[i];
    if(dp[i] != -1) return dp[i];
    return dp[i] = cost[i] + min(helper(cost, i-1, dp), helper(cost, i-2, dp));
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n, -1);
    return min(helper(cost, n-1, dp), helper(cost, n-2, dp));
}

int main(){
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost) << endl;
}

/*
1. Initialize DP Array: Create a DP array of size n (where n is the number of steps) filled with -1 to store computed minimum costs.
2. Define Base Cases: If at step 0 or 1, return the cost of that step directly.
3. Check Memoization: If the minimum cost for step i is already computed (dp[i] != -1), return the cached result.
4. Recursive Computation: For each step i, calculate:
    1. dp[i] = cost[i] + min(helper(i-1), helper(i-2))
    2. This means: cost to reach this step + minimum of (cost to reach from previous step OR cost to reach from two steps back)
5. Return Final Answer: Return the minimum of:
    1. helper(n-1) - reaching the last step
    2. helper(n-2) - reaching the second-to-last step
    3. (You can reach the top by stepping on either of the last two steps)
*/