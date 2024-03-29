#include<bits/stdc++.h>
using namespace std;

// ✍️ Graph Implementation

// ✒️ Adjancy list

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

// Breadth First Search

void bfs(vector<int> adj[], int v, int r){
    vector<bool> visited(v+1,false);
    queue<int> q;
    visited[r] = true;
    q.push(r);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        cout<< temp<< " ";
        for(int x : adj[temp]){
            if(visited[x] == false){
                visited[x] = true;
                q.push(x);
            }
        }
    }

}

// no sourse given adj graph may be disconnected
void BFS(vector<int> adj[], vector<bool> &visit ,int s){
    queue<int> q;
    q.push(s);
    visit[s] = true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        cout<<temp<<" ";
        for(int x : adj[temp]){
            if(visit[temp] == false){
                visit[temp] = true;
                q.push(x);
            }
        }
    }
}

void bfsDis(vector<int> adj[], int v){
    vector<bool> visit(v+1, false);
    for(int i = 0; i< v; i++){
        if(visit[i] == false){
            BFS(adj, visit, i);
        }
    }
}

// Time Complexity: 0(V+E)
// E becacuse in undirected graph it is twice the total no. of edges. and in directed graph it is total no. of edges
// V because in disconnected graph we have to traverse each vertex.






int main()
{
    int v = 6;
    vector<int> adj[v];
    addEdge(adj,0,1);   
    addEdge(adj,0,2);   
    addEdge(adj,1,2);   
    addEdge(adj,1,3);
    addEdge(adj,4,5);
    print(adj, v);
    // bfs(adj,v, 0);
    
    bfsDis(adj,v);
    // dfs
    vector<bool> visited(v+1, false);
    return 0;
}