//Problem Link - https://atcoder.jp/contests/dp/tasks/dp_c
//C - Vacation
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Meomization
int helper(vector<vector<int>>& vacations, int day, int act, vector<vector<int>>& dp){
    if(day == 0) return vacations[0][act];

    if(dp[day][act] != -1) return dp[day][act];

    if(act == 0) return dp[day][act] = vacations[day][act] + max(helper(vacations, day-1, 1, dp), helper(vacations, day-1, 2, dp));
    if(act == 1) return dp[day][act]= vacations[day][act] + max(helper(vacations, day-1, 0, dp), helper(vacations, day-1, 2, dp));
    else return dp[day][act] = vacations[day][act] + max(helper(vacations, day-1, 0, dp), helper(vacations, day-1, 1, dp));
}


int vacation(vector<vector<int>>& vacations, int day, vector<vector<int>>& dp){
    int xa = helper(vacations, day, 0, dp);
    int xb = helper(vacations, day, 1, dp);
    int xc = helper(vacations, day, 2, dp);

    return max({xa, xb, xc});
}

int maxVacation(vector<vector<int>>& vacations){
    int n = vacations.size();
    vector<vector<int>> dp(n, vector<int>(3, -1));
    return vacation(vacations, n-1, dp);
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> vacations(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++) cin>>vacations[i][j];
    }

    cout<<maxVacation(vacations)<<endl;
}

/*
f(i, act) --> max profit on 0 to ith day when particular "act" is performed
Recurrence Relation: f(i, act) = max(xa, xb, xc) where 
    xa = ai + max(f(i-1, b), f(i-1, c))
    xb = bi + max(f(i-1, a), f(i-1, c))
    xc = ci + max(f(i-1, a), f(i-1, b))
*/
