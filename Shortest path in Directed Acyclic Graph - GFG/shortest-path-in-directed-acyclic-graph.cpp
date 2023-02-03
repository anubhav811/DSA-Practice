//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void dfs(int node,vector<int> &vis,stack<int> &s,vector<pair<int,int>> adj[]){
         vis[node]=1;
         for(auto it:adj[node]){
             if(!vis[it.first])
                dfs(it.first,vis,s,adj);
         }
         s.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        // topo sort
        vector<int> vis(N,0);
        stack<int> s;
        
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,vis,s,adj);
            }
        }
        
        vector<int> dist (N,INT_MAX);
        dist[0]=0;
        bool flag = true;
        while(!s.empty()){
            int node = s.top();
            if(node != 0 && flag){
                s.pop();
                continue;
            } 
            if(node==0){
                flag = false;
            }

            for(auto it:adj[node]){
                dist[it.first] = min(dist[it.first],dist[node]+it.second);
            }
            s.pop();
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends