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

unordered_map<int, int> djikstra(int src, int vertex){ //O(VlogV + ElogV)
    priority_queue<pp, vector<pp>, greater<pp>> pq; //{wt, node}
    unordered_set<int> visited;
    vector<int> via(vertex);
    unordered_map<int, int> mp;
    for(int i = 0; i < vertex; i++) mp[i] = INT_MAX; //O(V)
    pq.push({0, src});
    mp[src] = 0;
    while(pq.size() != 0){ //O((V+E)logV)
        pp curr = pq.top();
        if(visited.count(curr.second) == 1){
            pq.pop();
            continue;
        }
        visited.insert(curr.second);
        pq.pop();

        for(auto neighbour : gr[curr.second]){
            if(visited.count(neighbour.first) == 0 && mp[neighbour.first] > mp[curr.second] + neighbour.second){
                pq.push({mp[curr.second] + neighbour.second, neighbour.first});
                via[neighbour.first] = curr.second;
                mp[neighbour.first] = mp[curr.second] + neighbour.second;
            }
        }
    }
    return mp;
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
    unordered_map<int, int> shortestPath = djikstra(src, vertex);
    for(auto p : shortestPath) cout<<p.first<<"  "<<p.second<<endl;
}

/*
7 9
0 1 1
0 2 5
1 2 4
1 3 1
3 4 1
2 4 1
3 6 2
6 5 1
4 5 5
0
*/