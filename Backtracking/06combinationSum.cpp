//Leetcode 40. Combination Sum II
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;

void f(vector<int>& candidates, int target, int idx, vector<int>& subset){
    if(target == 0){
        result.push_back(subset);
        return;
    }
    if(idx == candidates.size()) return;
    if(candidates[idx] <= target){ // pickup
        subset.push_back(candidates[idx]);
        f(candidates, target - candidates[idx], idx + 1, subset);
        subset.pop_back();
    }

    //not pickup
    int j = idx + 1;
    while(j < candidates.size() && candidates[j] == candidates[j-1]) j++;
    f(candidates, target, j, subset);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> subset;
    result.clear();
    f(candidates, target, 0, subset);
    return result;
}

int main(){
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> res = combinationSum2(candidates, target);
    for(auto vec : res){
        for(int ele : vec) cout<<ele<<" ";
        cout<<endl;
    }
}