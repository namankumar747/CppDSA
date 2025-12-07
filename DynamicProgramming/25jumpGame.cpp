//Leetcode 55. Jump Game
#include <iostream>
#include <vector>
using namespace std;

//Memoization
bool helper(vector<int>& nums, int currIdx, vector<int>& dp){
    if(currIdx == nums.size()-1) return true;
    if(currIdx >= nums.size()) return false;

    if(dp[currIdx] == 0) return true;
    if(dp[currIdx] == -1) return false;

    for(int i = 1; i <= nums[currIdx]; i++){
        if(currIdx + i < nums.size()){
            if(helper(nums, currIdx + i, dp) == true){
                dp[currIdx] = 0;
                return true;
            }
        }
    }
    dp[currIdx] = -1;
    return false;
}

bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -2);
    // -2 unvisited, -1 false, 0 true;
    return helper(nums, 0, dp);
}

int main(){
    vector<int> nums = {2, 3, 1, 1, 4};
    cout<<canJump(nums)<<endl;
}

/*
1. Approach: Top‑down recursion with memoization (DFS + DP). Try all reachable next indices from the current index and cache results to avoid recomputation.

2. State / Function: helper(nums, currIdx, dp) returns true if index currIdx can reach the last index.

3. Memo table (dp) meaning: -2 = unvisited, 0 = true (can reach end), -1 = false (cannot reach end).

4. Base cases:
    1. If currIdx == n-1 return true.
    2. If currIdx >= n return false.
    3. If dp[currIdx] is cached return the cached boolean.

5. Transition / Recurrence: For step from 1 to nums[currIdx]:
    1. If currIdx + step < n and helper(nums, currIdx + step, dp) is true, set dp[currIdx] = 0 and return true.
    2. If no reachable next index leads to the end, set dp[currIdx] = -1 and return false.
6. Driver: canJump(nums) initializes dp with -2 and returns helper(nums, 0, dp).
*/