#include <iostream>
#include <vector>
using namespace std;

//Basic Approach
void permutations(vector<string>& ans, string str, string original){
    if(original == ""){
        ans.push_back(str);
        return;
    }
    for(int i = 0; i < original.length(); i++){
        char ch = original[i];
        string left = original.substr(0, i);
        string right = original.substr(i+1);
        permutations(ans, str+ch, left + right);
    }
}

int main(){
    string str = "1234";
    vector<string> ans;
    permutations(ans, "", str);
    for(string ele : ans){
        cout<<ele<<" ";
    }
    cout<<endl;
}
