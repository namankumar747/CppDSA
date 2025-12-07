//Leetcioode 198. House Robber
#include <iostream>
#include <vector>
using namespace std;

//Memoization
int helper(vector<int>& nums, int i, vector<int>& dp){
    int n = nums.size();
    if(i == n-1) return nums[i];
    if(i == n-2) return max(nums[i], nums[i+1]);
    if(dp[i] != -1) return dp[i];
    return dp[i] = max(nums[i] + helper(nums, i+2, dp), 0 + helper(nums, i+1, dp));
}

int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    return helper(nums, 0, dp);
}

int main(){
    vector<int> nums = {2,7,9,3,1};
    cout << rob(nums) << endl;
}

/*
1. Problem Statement:
   You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
   the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and 
   it will automatically contact the police if two adjacent houses were broken into on the same night.
   Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
2. Explanation:
   We use a dynamic programming approach with memoization to solve this problem. We define a helper function that takes the current index and a dp array to store the maximum amounts.
   The recurrence relation is:  
    dp[i] = max(nums[i] + dp[i+2], dp[i+1])
    This means that for each house, we have two choices: either rob the current house and add its value to the maximum amount from house i+2, or skip the current house and take the maximum amount from house i+1.
3. Time Complexity: O(n), where n is the number of houses. We traverse the list of houses once, and each state is computed only once due to memoization.
4. Space Complexity: O(n), for the dp array used to store the maximum amounts and the recursion stack.
Algorithm: Dynamic Programming - Memoization
*/
