#include<bits/stdc++.h>
using namespace std;

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

// Counting connected components in an undirected graph

int countDis(vector<int> adj[], int v){
    vector<bool> visit(v+1, false);
    int count= 0;
    for(int i = 0; i<v; i++){
        for(int x : adj[i]){
            if(!visit[x]){
                count++;
                BFS(adj,visit, x);
            }
        }
    }
}

// ✍️ Applications of BFS
// ✒️ Shortest path in unweighted graph
// ✒️ crawlers in search engine
// ✒️ Peer to peer network
// ✒️ Broadcasting
// ✒️ Socaial Networking Search
// ✒️ In garbage collection (cheney's algorithm)
// ✒️ In cycle detection
// ✒️ Ford flukersion algorithm

int main()
{
    
    return 0;
}