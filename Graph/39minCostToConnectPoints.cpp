//Leetcode 1584. Min Cost to Connect All Points
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//DSU for detecting cycle
int find(vector<int>& parent, int x){
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

void Union(vector<int>& parent, vector<int>& rank, int a, int b){
    a = find(parent, a);
    b = find(parent, b);

    if(a == b) return;
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
}

struct Edge{
    int src;
    int dest;
    int wt;
};

static bool cmp(Edge e1, Edge e2){ //custom comparator for weight comparing
    return e1.wt < e2.wt;
}
int kruskals(vector<Edge>& input, int vertex){
    sort(input.begin(), input.end(), cmp); //sorting the edges in accending order of there edge weights
    vector<int> parent(vertex+1); //parent array for DSU
    vector<int> rank(vertex+1, 0); //rank array for DSU
    for(int i = 0; i <= vertex; i++) parent[i] = i; //initially all node are parent of itself
    int edgeCount = 0; //we have to take only (vertex - 1) number of edges maximum
    int i = 0;
    int ans = 0; //to store minimum weight sum
    while(edgeCount < vertex - 1 && i < input.size()){ //in tree number of edges is always less than or equal to (vertex - 1)
        Edge curr = input[i];
        int srcPar = find(parent, curr.src);
        int destPar = find(parent, curr.dest);
        if(srcPar != destPar){
            //parents are not same, so we can include this edge
            //this will not create cycle
            Union(parent, rank, curr.src, curr.dest);
            ans += curr.wt;
            edgeCount++;
        }
        i++; //moves to next edge
    }
    return ans;
}

int minCostConnectPoints(vector<vector<int>>& points) {
    int vertex = points.size();
    vector<Edge> edgeList;
    for(int i = 0; i < vertex; i++){ //constructing graph
        for(int j = i + 1; j < vertex; j++){
            Edge ed;
            ed.src = i;
            ed.dest = j;

            int a = points[i][0] - points[j][0];
            if(a < 0) a *= -1;
            int b = points[i][1] - points[j][1];
            if(b < 0) b *= -1;
            ed.wt = a + b;
            edgeList.push_back(ed);
        }
    }
    return kruskals(edgeList, vertex);
}

int main(){
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout<<minCostConnectPoints(points)<<endl;
}

//you are given points, first construct complete graph with nodes between every adjacent nodes
//then apply kruskals algorithm to get minimum cost of connecting all points