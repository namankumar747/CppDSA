#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

void Print(vector<string> arr){
    for(string ele : arr){
        cout<<ele<<endl;
    }
}

//All Paths Between Two Nodes
void add_edge(vector<list<int>> &graph, int source, int destination, bool bi_dirc = true){
    graph[source].push_back(destination);
    if(bi_dirc == true){
        graph[destination].push_back(source);
    }
}


void dfs(vector<list<int>> graph, int curr, int end, string s, vector<string> &ans, unordered_set<int> &visited){
    string a = to_string(curr);
    if(curr == end){
        s = s + a;
        ans.push_back(s);
        return;
    }
    visited.insert(curr);
    for(auto neighbour : graph[curr]){
        if(visited.count(neighbour) == 0){
            dfs(graph, neighbour, end, s+a+"->", ans, visited);
        }
    }
    visited.erase(curr);
    
}

vector<string> AllPath(vector<list<int>> graph, int curr, int end){
    unordered_set<int> visited;
    vector<string> ans;
    dfs(graph, curr, end, "", ans, visited);
    return ans;
}

int main(){
    vector<list<int>> graph;
    int vertex;
    cout<<"Enter No Of Vertices ";
    cin>>vertex;
    graph.resize(vertex, list<int> ());
    int edges;
    cout<<"Enter No Of Edges ";
    cin>>edges;
    cout<<"Enter Edges (source <space> destination)"<<endl;
    while(edges != 0){
        int s, d;
        cin>>s>>d;
        add_edge(graph, s, d);
        edges = edges -1;
    }
    vector<string> ans = AllPath(graph, 0, 6);
    Print(ans);
}

/*No of vertices 7 
no of edges 8*/
/*
0 1
0 3
3 4    
1 4
1 2
2 5
5 6
2 6
*/