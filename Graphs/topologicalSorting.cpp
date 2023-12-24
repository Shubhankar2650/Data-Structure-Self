#include<bits/stdc++.h>
using namespace std;

// Implementation of graph
void addEdgeDir(vector<int>adj[],int u, int v){
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

// ✒️ Tropological Sorting
// Also known as "khan's algorithm"
// Here vertex represents "jobs" and edges represent dependencies. We print the independent job first then jobs dependent on it
// In other word if there is a vertex in DAG from u-v, then u comes before v in the ordering
// This sortig only works for the acyclic graph. If the graph contains the cycle then this sorting fails

// identify indegree of all verteces first
// store all 0 indegree vertex in queue



void findIndegree(vector<int> adj[],vector<bool> &visited,vector<int> &indegree, int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int x: adj[temp]){
            indegree[x]++;
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

// 📌 We can also find indegree by modifying addEdge function
//  in this we increment indegree by each adding edge

void topologicalSorting(vector<int> adj[], int v){
    vector<bool> visited(v, false);
    vector<int> indegree(v,0);
    queue<int> qi;
    for(int i = 0; i<v; i++){
        if(!visited[i]){
            findIndegree(adj,visited,indegree,i);
        }
    }
    for(int i = 0; i<v; i++){
        if(indegree[i] == 0){
            qi.push(i);
        }
    }

    // Printing the tropological sort
    while(!qi.empty()){
        int temp = qi.front();
        qi.pop();
        cout<<temp<<" ";
        for(int x: adj[temp]){
            --indegree[x];
            if(indegree[x] == 0){
                qi.push(x);
            }
        }
    }
    
}

// TIme complexity is as same as bfs

// ✍️ topological sorting using "dfs"
void dfsR(vector<int> adj[], vector<bool> &visited, stack<int> &st, int s){
    cout<<s;
    visited[s] = true;
    for(int x: adj[s]){
        if(!visited[x]){
            dfsR(adj, visited,st,x);
        }
    }
    st.push(s);
}

void dfsT(vector<int> adj[], int v){
    vector<bool> visited(v, false);
    stack<int> st;
    for(int i = 0; i< v; i++){
        if(!visited[i]){
            dfsR(adj,visited,st,i);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    int v = 5;
    vector<int> adj[5];
    addEdgeDir(adj,0,2);
    addEdgeDir(adj,0,3);
    addEdgeDir(adj,2,3);
    addEdgeDir(adj,1,3);
    addEdgeDir(adj,1,4);
    cout<<"Topological sorting using the bfs: ";
    topologicalSorting(adj,v);

    cout<<"\n Topological sorting using the dfs: ";
    dfsT(adj,v);
    return 0;
}