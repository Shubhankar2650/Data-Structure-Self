#include<bits/stdc++.h>
using namespace std;
// Implementation of graph
void addEdge(vector<int>adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// ✒️ printing the list
void print(vector<int> adj[], int v){
    for(int i = 0; i< v; i++){
        for(int x : adj[i]){
            cout<< x<< " ";
        }cout<<endl;
    }
}

// Finding shortest Path
// Here we finding the shortest distance  of the source vertex to all other of its vertex.
vector<int> shortestPath(vector<int> adj[],int v, int s){
    vector<int> dist(v, INT_MAX);
    vector<int> visited(v,false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int x : adj[u]){
            if(!visited[x]){
                dist[x] = dist[u] + 1;
                visited[x] = true;
                q.push(x);
            }

        }
    }
    return dist;
}

// Time complexity: Its equal to bfs

int main()
{
    int v = 4;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    vector<int> dist = shortestPath(adj,v,0);
    for(auto x: dist){
        cout<<x<<" ";
    }
    return 0;
}