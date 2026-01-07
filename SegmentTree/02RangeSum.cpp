//307. Range Sum Query - Mutable
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> st;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4*n);
        buildSumTree(nums, 0, 0, n-1);
    }
    void buildSumTree(vector<int>& nums, int i, int lo, int hi){
        if(lo == hi){
            st[i] = nums[lo];
            return;
        }
        int mid = lo + (hi - lo)/2;
        buildSumTree(nums, 2*i + 1, lo, mid);
        buildSumTree(nums, 2*i + 2, mid+1, hi);
        st[i] = st[2*i + 1] + st[2*i + 2];
    }
    
    void updateVal(int i, int lo, int hi, int index, int val){
        if(lo == hi){
            st[i] = val;
            return;
        }
        int mid = lo + (hi - lo)/2;
        if(index <= mid) updateVal(2*i + 1, lo, mid, index, val);
        else updateVal(2*i + 2, mid+1, hi, index, val);
        st[i] = st[2*i + 1] + st[2*i + 2];
    }
    void update(int index, int val) {
        updateVal(0, 0, n-1, index, val);
    }
    
    int getSum(int i, int lo, int hi, int l, int r){
        if(hi < l || r < lo) return 0;
        if(lo >= l && hi <= r) return st[i];
        int mid = lo + (hi - lo)/2;
        int leftSum = getSum(2*i + 1, lo, mid, l, r);
        int rightSum = getSum(2*i + 2, mid + 1, hi, l, r);
        return leftSum + rightSum;
    }
    int sumRange(int left, int right) {
        return getSum(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main(){
    vector<int> nums = {1, 4, 3, 6, 4, 7, 5, 8, 7, 9};
    NumArray* np = new NumArray(nums);
    cout<<np->sumRange(0, 4)<<endl;
    np->update(2, 8);
    cout<<np->sumRange(0, 4)<<endl;
    np->update(5, 7);
    cout<<np->sumRange(2, 5)<<endl;

}