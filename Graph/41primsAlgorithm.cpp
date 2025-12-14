#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#define pp pair<int, int>
#define ll long long int
using namespace std;

vector<list<pp>> gr;
void add_edge(int u, int v, int wt, bool bi_dir = true){
    gr[u].push_back({v, wt});
    if(bi_dir == true) gr[v].push_back({u, wt});
}

ll prims(int src, int vertex){
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> visited;
    vector<int> par(vertex + 1);
    unordered_map<int, int> mp;
    for(int i = 0; i <= vertex; i++) mp[i] = INT_MAX;
    pq.push({0, src});
    mp[src] = 0;
    int total_count = 0; //0 to (vertex - 1) edges
    int result = 0;
    while(total_count < vertex && pq.size() != 0){
        pp curr = pq.top();
        if(visited.count(curr.second) == 1){
            pq.pop();
            continue;
        }
        visited.insert(curr.second);
        total_count++;
        result += curr.first;
        pq.pop();
        for(auto neighbour : gr[curr.second]){
            if(visited.count(neighbour.first) == 0 && mp[neighbour.first] > neighbour.second){
                pq.push({neighbour.second, neighbour.first});
                par[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    }
    return result;
}

int main(){
    int vertex, edges;
    cin>>vertex>>edges;
    gr.resize(vertex + 1, list<pp>());
    while(edges--){
        int u, v, wt;
        cin>>u>>v>>wt;
        add_edge(u, v, wt);
    }
    int src;
    cin>>src;
    cout<<prims(src, vertex)<<endl;
}