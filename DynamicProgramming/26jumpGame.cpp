//Leetcode 55. Jump Game
#include <iostream>
#include <vector>
using namespace std;

//Tabulation
bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n, false);
    dp[n-1] = true;
    for(int i = n-2; i >= 0; i--){
        for(int j = 1; j <= nums[i]; j++){
            if(i + j < n){
                if(dp[i+j] == true){
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[0];
}

int main(){
    vector<int> nums = {2, 3, 1, 1, 4};
    cout<<canJump(nums)<<endl;
}