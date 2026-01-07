//2080. Range Frequency Queries
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RangeFreqQuery {
public:
    vector<unordered_map<int, int>> st;
    int n;
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        st.resize(4*n);
        buildFreqTree(arr, 0, 0, n-1);
    }
    unordered_map<int, int> addMaps(unordered_map<int, int>& mp1, unordered_map<int, int>& mp2){
        unordered_map<int, int> mp;
        for(auto x : mp1) mp.insert(x);
        for(auto x : mp2){
            int key = x.first, freq = x.second;
            if(mp.find(key) == mp.end()) mp.insert(x);
            else{
                mp[key] += freq;
            }
        }
        return mp;
    }
    void buildFreqTree(vector<int>& arr, int i, int lo, int hi){
        if(hi == lo){
            st[i][arr[lo]] = 1;
            return;
        }
        int mid = lo + (hi - lo)/2;
        buildFreqTree(arr, 2*i + 1, lo, mid);
        buildFreqTree(arr, 2*i + 2, mid + 1, hi);
        st[i] = addMaps(st[2*i + 1], st[2*i + 2]);
    }

    int getFreq(int i, int lo, int hi, int &l, int &r, int &key){
        if(hi < l || r < lo) return 0;
        if(lo >= l && hi <= r){
            if(st[i].find(key) == st[i].end()) return 0;
            else return st[i][key];
        }
        int mid = lo + (hi - lo)/2;
        int leftAns = getFreq(2*i + 1, lo, mid, l, r, key);
        int rightAns = getFreq(2*i + 2, mid + 1, hi, l, r, key);
        return leftAns + rightAns;
    }
    
    int query(int left, int right, int value) {
        return getFreq(0, 0, n-1, left, right, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

int main(){
    vector<int> nums = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
    RangeFreqQuery* rf = new RangeFreqQuery(nums);
    cout<<rf->query(1, 2, 4)<<endl;
}