#include<bits/stdc++.h>
using namespace std;


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

// ✍️ DFS(Depth First Search)
void dfsRec(vector<int> adj[], int s,vector<bool> &visited){
    visited[s] = true;
    cout<<s<<" "; // comment out it when you want to count the no. of disconnected graphs present.
    for(auto x : adj[s]){
        if(visited[x] == false){
            dfsRec(adj, x, visited);
        }
    }
}

void dfs(vector<int> adj[],int v, int s){
    vector<bool> visited(v,false);
    dfsRec(adj,s,visited);
}

void dfsDis(vector<int> adj[], int v){
    vector<bool> visited(v, false);
    for(int i = 0; i< v; i++){
        if(!visited[i]){
            dfsRec(adj,i, visited);
        }
    }
}
// Time complexity : 0(V+E)

// count connected component in an undirected graph
int countDis(vector<int> adj[], int v){
    vector<bool> visited(v, false);
    int count = 0;
    for(int i = 0; i< v; i++){
        if(!visited[i]){
            count++;
            dfsRec(adj,i, visited);
        }
    }
    return count;
}

// ✍️ Applications of DFS
// ✒️ Cycle detection
// ✒️ Topological Sorting
// ✒️ Strongly connected components
// ✒️ Solving maze and similar problems
// ✒️Finding path

int main()
{
    // ✒️ 1st graph

    // int v = 6;
    // vector<int> adj[v];
    // addEdge(adj,0,1);
    // addEdge(adj,0,2);
    // addEdge(adj,1,3);
    // addEdge(adj,1,4);
    // addEdge(adj,2,3);
    // addEdge(adj,4,5);

    // dfs(adj,v, 0);

    int v = 5;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,0);
    addEdge(adj,3,4);

    dfsDis(adj,v);
    cout<<"\nThe no. of disconnected graphs present: "<<countDis(adj, v);
    return 0;
}