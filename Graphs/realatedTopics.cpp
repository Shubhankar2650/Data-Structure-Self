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

// Time complexity: Its equal to bfs i.e 0(v+e)

// ✒️ Detect cycle in the undirected graph

bool DFSRec(vector<int> adj[], int s,vector<bool> visited, int p){ // p = parent, s= source
    visited[s] = true;
    for(int x : adj[s]){
        if(!visited[s]){
           if(DFSRec(adj,x,visited,s) == true) return true;
        }
        else if(s != p) return true;
    }
    return false;
}

bool cycle(vector<int> adj[], int v){
    vector<bool> visited(v, false);
    for(int i = 0; i< v; i++){
        if(!visited[i]){
            if(DFSRec(adj,i,visited,-1) == true) return true; 
        }
    }
    return false;
}

// 💠 for directed graph

bool DFSRecDir(vector<int> adj[], int s,vector<bool> &visited,vector<bool> recst){ // s= source
    visited[s] = true;
    recst[s] = true;
    for(int x : adj[s]){
        if(!visited[x] && DFSRecDir(adj,x,visited,recst)){
           return true;
        }
        else if(recst[x] == true) return true;
    }
    recst[s] = false;
    return false;
}


bool cycleDir(vector<int> adj[], int v){
    vector<bool> visited(v, false);
    vector<bool> recst(v, false);
    for(int i = 0; i< v; i++){
        if(!visited[i]){
            if(DFSRecDir(adj,i,visited,recst) == true) return true;
        }
    }
    return false;
}

// ✍️ Detect cycle part 2
// Using khans's algorithm

void findIndegree(vector<int> adj[], vector<int> &indegree, vector<bool> &visited, int s){
    queue<int> q;
    q.push(s); 
    visited[s] = true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int x : adj[temp]){
            indegree[x]++;
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

bool topological(vector<int> adj[], int v){
    vector<bool> visited(v, false);
    vector<int> indegree(v, 0);
    queue<int> qi;
    int count = 0;
    for(int i = 0; i<v; i++){
        if(!visited[i]){
            findIndegree(adj, indegree,visited,i);
        }
    }

    for(int i = 0; i<v; i++){
        if(indegree[i] == 0){
            qi.push(i);
        }
    }

    while(!qi.empty()){
        int temp = qi.front();
        qi.pop();
        count++;
        for(auto x : adj[temp]){
            indegree[x]--; 
            if(indegree[x] == 0){
                qi.push(x);
            }
        }
    }
    return(count != v);
}

int main()
{
    // int v = 4;
    // vector<int> adj[v];
    // addEdge(adj,0,1);
    // addEdge(adj,0,2);
    // addEdge(adj,1,2);
    // addEdge(adj,1,3);
    // addEdge(adj,2,3);
    // vector<int> dist = shortestPath(adj,v,0);
    // for(auto x: dist){
    //     cout<<x<<" ";
    // }
    int v = 4;
    vector<int> adj[v];
    addEdgeDir(adj,0,1);
    addEdgeDir(adj,1,3);
    addEdgeDir(adj,3,2);
    addEdgeDir(adj,2,1);
    cout<<"Is the graph contains the cycle or not: "<<cycleDir(adj,v);

    // checking cycle using khan's algorithm
    cout<<"\n Is the graph contains the cycle or not: "<<topological(adj,v);

    return 0;
}