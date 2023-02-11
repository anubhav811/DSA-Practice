//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet
{

public:
    vector<int> rank, size, parent;
    
    // n is the number of nodes 
    DisjointSet(int n)
    {
        // considering 1 based indexing
        rank.resize(n + 1, 0);
        size.resize(n + 1, 0);
        parent.resize(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = i;
        }
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int upu = findUltimateParent(u);
        int ru = rank[upu];

        int upv = findUltimateParent(v);
        int rv = rank[upv];

        // if they are same , means same component , nothing to do
        if (upu == upv)
            return;
        if (ru < rv)
        {
            parent[upu] = upv;
        }
        else if (ru > rv)
        {
            parent[upv] = upu;
        }
        else
        {
            parent[upv] = upu;
            rank[upu]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int upu = findUltimateParent(u);
        int s_upu = rank[upu];

        int upv = findUltimateParent(v);
        int s_upv = rank[upv];

        if (upu == upv)
            return;

        if (s_upu < s_upv)
        {
            parent[upu] = upv;
            size[upv] += size[upu];
        }

        else // covers s_upu > s_upv and also equal case
        {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};

class Solution {
  public:
  // SOLUTION USING DISJOINT SET
    int numProvinces(vector<vector<int>> adj, int v) {
        DisjointSet ds(v);
        for(int i=0;i<v;i++) {
            for(int j=0;j<v;j++) {
                if(adj[i][j] == 1 && i!=j) {
                    ds.unionByRank(i,j);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<v;i++){/*          
        
            if(ds.parent[i]==i){     This would only work when parent array is declared under the public 
                                        scope of DisjointSet Class
                OR  
*/
            if(ds.findUltimateParent(i)==i){
                cnt++;
            }
        }
        
        return cnt;
    }
  
  // SIMPLE BFS SOLUTION
//   void dfs(int node, vector<int>adj[], vector<int>&vis) {
//         vis[node] = 1;
//         for(auto i: adj[node]) {
//             if(!vis[i])
//                 dfs(i,adj,vis);
//         }
//     }
//     int numProvinces(vector<vector<int>> adj, int v) {
//         vector<int>adjacent[v];
//         for(int i=0;i<v;i++) {
//             for(int j=0;j<v;j++) {
//                 if(adj[i][j] == 1 && i!=j) {
//                     adjacent[i].push_back(j);
//                     adjacent[j].push_back(i);
//                 }
//             }
//         }
        
//         vector<int>vis(v);
//         int count = 0;
//         for(int i=0;i<v;i++) {
//             if(!vis[i]) {
//                 count++;
//                 dfs(i,adjacent,vis);
//             }
//         }
        
//         return count;
//     }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends