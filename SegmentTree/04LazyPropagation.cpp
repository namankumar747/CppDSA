//Lazy Propogation
#include <iostream>
#include <vector>
using namespace std;

vector<int> st;
vector<int> lazy;
int n;
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

int getSum(int i, int lo, int hi, int l, int r){
    //lazy updates {check for pending lazy updates}
    if(lazy[i] != 0){
        int rangeSize = hi - lo + 1;
        st[i] = rangeSize*lazy[i];
        if(lo != hi){
            lazy[2*i + 1] += lazy[i];
            lazy[2*i + 2] += lazy[i];
        }
        lazy[i] = 0; 
    }
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

void updateRange(int i, int lo, int hi, int l, int r, int val){
    //lazy updates {check for pending lazy updates}
    if(lazy[i] != 0){
        int rangeSize = hi - lo + 1;
        st[i] = rangeSize*lazy[i];
        if(lo != hi){
            lazy[2*i + 1] += lazy[i];
            lazy[2*i + 2] += lazy[i];
        }
        lazy[i] = 0; 
    }
    if(l > hi || r < lo) return;
    if(l <= lo && hi <= r){
        int rangeSize = hi - lo + 1;
        st[i] += rangeSize*val;
        if(lo != hi){
            lazy[2*i + 1] += val;
            lazy[2*i + 2] += val;
        }
        return;
    }
    int mid = lo + (hi - lo)/2;
    updateRange(2*i + 1, lo, mid, l, r, val);
    updateRange(2*i + 2, mid+1, hi, l, r, val);
    st[i] = st[2*i + 1] + st[2*i + 2];
}
void update(int left, int right, int val){
    updateRange(0, 0, n-1, left, right, val);
}

int main(){
    vector<int> nums = {1, 4, 2, 8, 6, 4, 9, 3};
    n = nums.size();
    st.resize(4*n);
    lazy.resize(4*n, 0);
    buildSumTree(nums, 0, 0, n-1);

    cout<<sumRange(0, 2)<<endl;
    update(0, 2, 3);
    cout<<sumRange(0, 2)<<endl;
}
