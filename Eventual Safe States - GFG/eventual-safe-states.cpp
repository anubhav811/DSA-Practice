//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool checkDfs(int i , vector<int> adj[] , vector<int> &vis, vector<int> &path_vis,vector<int> &safe){
        
        vis[i]=1;
        path_vis[i]=1;
        
        for(auto it: adj[i]){
            if(!vis[it]){
                 if(checkDfs(it,adj,vis,path_vis,safe)==true){
                    safe[it]=0;
                    return true;
                 }
            }
            else if(path_vis[it]){
                    safe[it]=0;
                    return true;
            }
        }
        path_vis[i]=0;
        
        // didnt break out above , ie there wasnt any cycle ; Clearly a safe node
        safe[i]=1;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> safe(V,0);
        vector<int> path_vis(V,0);
        vector<int> res;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                checkDfs(i,adj,vis,path_vis,safe);
                }
        }
        
        
        for(int i=0;i<V;i++)
        {
            if(safe[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends