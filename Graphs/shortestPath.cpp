#include<bits/stdc++.h>
using namespace std;

// Implementation of graph
void addEdge(vector<int>adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void addEdgeDir(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

// add weighted edge
void addEdgeDirW(vector<int> adj[],vector<vector<int>> &w, int u, int v, int weight){
    adj[u].push_back(v);
    w[u][v] = weight;
}

// ✒️ printing the list
void print(vector<int> adj[], int v){
    for(int i = 0; i< v; i++){
        for(int x : adj[i]){
            cout<< x<< " ";
        }cout<<endl;
    }
}

// finding shoetest path
void dfsR(vector<int> adj[],vector<bool> visited,vector<vector<int>>w,vector<int>&ans,int weight,int s){
    visited[s] = true;
    for(auto x: adj[s]){
        if(!visited[x] ){
            dfsR(adj,visited,w,ans,weight,x);
        }
        weight += w[s][x];
        if(weight<ans[x]) ans[x] = weight;
    }
}

int main()
{
    int v = 6;
    vector<int> adj[6];
    vector<vector<int>> w(v,vector<int>(v));
    addEdgeDirW(adj,w,0,1,2);
    addEdgeDirW(adj,w,0,4,1);
    addEdgeDirW(adj,w,1,2,3);
    addEdgeDirW(adj,w,2,3,6);
    addEdgeDirW(adj,w,4,2,2);
    addEdgeDirW(adj,w,4,5,4);
    addEdgeDirW(adj,w,5,3,1);
    vector<bool> visited(v,false);
    vector<int> ans(v,INT_MAX);
    dfsR(adj,visited,w, ans, 0,0);

    cout<< "shortest distance of the source to the vertex: ";
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}