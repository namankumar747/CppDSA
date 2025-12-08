//Problem Link - https://www.spoj.com/problems/MCOINS/
#include <iostream>
#include <vector>
using namespace std;


int main(){
    int k, l, m;
    cin>>k>>l>>m;

    vector<bool> dp(1000005, 0);

    dp[1] = 1; //winning state
    dp[l] = 1; //winning state
    dp[k] = 1; //winning state

    for(int i = 2; i < 1000000; i++){
        if(i == k || i == l) continue;
        dp[i] = !(dp[i-1] && ((i- k >= 1) ? dp[i-k] : 1) && ((i- l >= 1) ? dp[i-l] : 1));
        //if all three are winning state them definitely dp[i] is loosing state
        //if one of the three is loosing state then d[i] is winning state
        //Tabulation
    }

    for(int i = 0; i < m; i++){
        int n;
        cin>>n;
        if(dp[n] == 1) cout<<"A";
        else cout<<"B";
    }
}

/*
1 --> loosing state
2 --> winning state

f(n, k, l) --> winning state or loosing state when number of coins are "n"
Recurrence Relation: f(n, k, l) = !(f(n-1, k, l) && f(n-k, k, l) && f(n-l, k, l))
if anyone of f(n-1, k, l), f(n-k, k, l), f(n-l, k, l) is 0 i.e loosing state then f(n, k, l) is winning state
*/
