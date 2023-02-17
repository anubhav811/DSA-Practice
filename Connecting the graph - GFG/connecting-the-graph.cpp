//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
    int Solve(int n, vector<vector<int>>& edges) {
        // code here
        DisjointSet ds(n);
        int extraEdges = 0 ;
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
                if(ds.findUltimateParent(u) == ds.findUltimateParent(v)){
                    extraEdges++;
                }else{
                    ds.unionBySize(u,v);
                }
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)
                cnt++;
        }
        int ans = cnt-1;
        if(extraEdges>=ans)
            return ans;
        return -1;
    
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends