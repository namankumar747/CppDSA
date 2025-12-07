//Leetcode 198. House Robber
#include <iostream>
#include <vector>
using namespace std;

//Tabulation
int rob(vector<int>& nums) {
    int n =  nums.size();
    if(n == 1) return nums[0];
    vector<int> dp(n, -1);
    dp[n-1] = nums[n-1];
    dp[n-2] = max(nums[n-1], nums[n-2]);
    for(int i = n-3; i >= 0; i--){
        dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
    }
    return dp[0];
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
   We use a dynamic programming approach to solve this problem. We create a dp array where dp[i] represents the maximum amount of money that can be robbed from house i to the last house.
   The recurrence relation is: 
    dp[i] = max(nums[i] + dp[i+2], dp[i+1])
    This means that for each house, we have two choices: either rob the current house and add its value to the maximum amount from house i+2, or skip the current house and take the maximum amount from house i+1.
3. Time Complexity: O(n), where n is the number of houses. We traverse the list of houses once.
4. Space Complexity: O(n), for the dp array used to store the maximum amounts.
Algorithm: Dynamic Programming - Tabulation
*/