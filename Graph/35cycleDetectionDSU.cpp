//Disjoint Set Union
#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& parent, int x){
    //T.C: O(log*n)
    if(parent[x] == x) return parent[x] = x;
    return parent[x] = find(parent, parent[x]);
}

bool Union(vector<int>& parent, vector<int>& rank, int a, int b){
    //T.C: O(log*n)
    a = find(parent, a);
    b = find(parent, b);
    if(a == b) return true;
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
    return false;
}

int main(){
    int n , m;
    cin>>n>>m; // n--> number of nodes , m--> number of edges
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    for(int i = 0; i <= n; i++) parent[i] = i;

    while(m--){
        int x, y; //enter edges (firstnode <space> secondnode)
        cin>>x>>y;
        bool res = Union(parent, rank, x, y); 
        if(res == true) cout<<"Cycle Detected"<<endl;
    }
}

//if two nodes belong to same group then definitely there is an alternative path between that nodes, so cycle is detected