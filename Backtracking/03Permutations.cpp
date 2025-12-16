#include <iostream>
#include <unordered_set>
using namespace std;

//Backtaracking
//Handled repeated values
void permutations(string& str, int i){
    if(i == str.length() - 1){
        cout<<str<<endl;
        return;
    }

    unordered_set<char> set;
    for(int idx = i; idx < str.length(); idx++){
        if(set.count(str[idx]) == 1) continue;

        set.insert(str[idx]);
        swap(str[idx], str[i]);
        permutations(str, i+1);
        swap(str[idx], str[i]); // after call
    }
}

int main(){
    string str = "aba";
    permutations(str, 0);
}
//unordered set to stroe visited character