//Leetcode 1791 Find the Centre Of a Star Graph
#include<iostream>
#include<vector>
using namespace std;

int findCenter(vector<vector<int>> &edges){
    int a = edges[0][0];
    int b = edges[0][1];

    int c = edges[1][0];
    int d = edges[1][1];

    return (c == a || c == b)? c : d;
}

//Concept: Common Node of Any Two Edges of a Star Graph is the Centre

int main(){
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    cout<<"Centre of Star Graph is: "<<findCenter(edges)<<endl;
}