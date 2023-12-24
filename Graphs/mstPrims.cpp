#include<bits/stdc++.h>
using namespace std;

// ✨ Minimum Spanning Tree ✨
// Sample Problem: Suppose there are n computers. So, you have to connected all the pc such that minimum length of the wire is used.
// A MST has precisely n-1 edges, where n is the number of the vertex.
// Given Weighted, undirected and connected graph.Find the minimum spannig tree

// ✍️ Prims Algorithm
// It is aṇ greedy Algorithm.

//✒️ Implementations
// The idea behind is that we make two sets - MST and not in MST. 
// In MST first set is already included.
// At each step it consider all the edges that connects the two sets and pick minimum weight edge.
// Now conecting the edge with vetex and we move that vertex from "not in MST" set in "MST" set.


void addEdge(vector<vector<int>> &adj,int u, int v,int w){
    adj[u][v] = w;
    adj[v][u] = w;
}

int primsAlgorithm(vector<vector<int>> &adj){
    int n = adj.size();
    vector<bool>mSet(n,false); // its the set which store edges into the mst
    vector<int> key(n,INT_MAX); // it defines available edges to visit based on min. weight
    key[0] = 0; // starting with 0th index
    int ans = 0; // define the ans to return

    for(int count = 0; count<n;count++){
        // here we find the vertex to be included into the mst based on the weight of the edges.
        int u = -1;
        for(int i = 0; i<n; i++){
            if(!mSet[i]&& (u==-1 || key[i]<key[u])){
                u = i;
            }
        }
        mSet[u] = true; // vertex is included in mst set
        ans += key[u];

        // updating key to minimum weight
        for(int v= 0; v<n;v++){
            if(adj[u][v] != 0 && !mSet[v]){
                key[v] = min(key[v],adj[u][v]);
            }
        }
    }
    return ans;
}
// time Complexity : 0(v^2)
int main()
{
    int v = 4;
    vector<vector<int>> adj(v,vector<int>(v));
    addEdge(adj,0,1,5);
    addEdge(adj,0,2,8);
    addEdge(adj,1,2,10);
    addEdge(adj,1,3,15);
    addEdge(adj,2,3,20);
    cout<<"abcd "<<endl;
    for(auto v:adj){
        for(auto x:v){
            cout<<x<<",";
        }
        cout<<endl;
    }
    cout<<primsAlgorithm(adj);
    return 0;
}