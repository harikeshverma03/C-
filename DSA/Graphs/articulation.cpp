#include<iostream>
#include<bits/stdc++.h>
using namespace std;
set<int> ans;
void dfs(int node, int parent, vector<int> &vis, vector<int> &low,vector<int> &tin, int &timer, vector<vector<int>> &adj){
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;
    for(auto it: adj[node]){
        if(it == parent) continue;

        if(vis[it])
            low[node] = min(low[node], tin[it]);
        else{
            dfs(it, node, vis, low, tin, timer, adj);
            low[node] = min(low[node],  low[it]);
            if(low[it] >= tin[node] && parent != -1)
                ans.insert(node);
            child++;
        }
    }
    if(parent == -1 && child > 1)
        ans.insert(node);
}

int main(){
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(e, vector<int>(2));
    for(int i = 0; i < e; i++) cin >> edges[i][0] >> edges[i][1];
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < e; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> visited(n+1,0);
    vector<int> tin(n+1,-1);
    vector<int> low(n+1, -1);
    int time = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            dfs(i, -1, visited, low, tin, time, adj);
    }
    for(auto it: ans)
        cout  << it << endl;


    return 0;

}