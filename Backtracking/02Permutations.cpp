#include <iostream>
using namespace std;

//Backtaracking
void permutations(string& str, int i){
    if(i == str.length() - 1){
        cout<<str<<endl;
        return;
    }
    for(int idx = i; idx < str.length(); idx++){
        swap(str[idx], str[i]);
        permutations(str, i+1);
        swap(str[idx], str[i]); // after call
    }
}

int main(){
    string str = "abc";
    permutations(str, 0);
}
