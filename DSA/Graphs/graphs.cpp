#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bfs(int n, int **G, int start){
    //cout << "Entered" << endl;
    int i = start;
    queue<int> q;
    int *visited = new int[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    cout << i << " ";
    visited[i] = 1;
    q.push(i);
    while(!q.empty()){
        i = q.front();
        q.pop(); 
        for(int j = 1; j < n; j++){
            if(G[i][j] == 1 && visited[j] == 0){
                cout << j << " ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }
    cout << endl;
}
int m;

void dfs(int n, int **G, int start,vector<int> &visited){
    if(visited[start] == 0){
        cout << start << " ";
        visited[start] = 1;
        for(int j = 1; j < n; j++){
            if(G[start][j] == 1 && visited[j] == 0){
                dfs(n, G, j, visited);
            }
        }
    }
    //cout << endl;
   
}
int main(){
    int n;
    cin >> n;
    m = n;
    n+=1;
    int **T = new int *[n];
    for(int i = 0; i < n; i++)
        T[i] = new int[n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> T[i][j];
    /*for(int i = 1; i < n; i++)
        bfs(n, T, i);*/
    for(int i = 1; i < n ; i++){
        vector<int> visited(7,0);
        dfs(n, T, i, visited);
        cout << endl;
    }

    return 0;
}
/*
int G[7][7] =  {{0,0,0,0,0,0,0},
                   {0,0,1,1,0,0,0}, 
                   {0,1,0,0,1,0,0}, 
                   {0,1,0,0,1,0,0}, 
                   {0,0,1,1,0,0,0},  
                   {0,0,0,0,1,0,0}, 
                   {0,0,0,0,1,0,0}}; 
*/