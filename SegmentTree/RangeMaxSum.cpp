#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Maximum Element in the given range of index of an array
vector<int> st;
void buildMaxTree(int arr[], int i, int lo, int hi){
    if(hi == lo){
        st[i] = arr[lo];
        return;
    }
    int mid = lo + (hi - lo)/2;
    buildMaxTree(arr, 2*i + 1, lo, mid);
    buildMaxTree(arr, 2*i + 2, mid+1, hi);
    st[i] = max(st[2*i + 1], st[2*i + 2]);
}

int getMax(int i, int lo, int hi, int l, int r){
    if(l > hi || r < lo) return INT_MIN;
    if(lo >= l && hi <= r) return st[i];
    int mid = lo + (hi - lo)/2;
    int leftMax = getMax(2*i + 1, lo, mid, l, r);
    int rightMax = getMax(2*i + 2, mid + 1, hi, l, r);
    return max(leftMax, rightMax);
}

int main(){
    int arr[] = {1, 3, 7, 5, 4, 3, 2, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    st.resize(4*n);
    buildMaxTree(arr, 0, 0, n-1);
    int l, r;
    cin>>l>>r;
    cout<<getMax(0, 0, n-1, l, r)<<endl;
}
//consider Lecture Notes for Explaination
