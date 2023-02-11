//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet
{
    vector<int> rank, size, parent;

public:
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
class Solution
{
	public:
	
	// USING KRUSKAL's Algorithm
	int spanningTree(int V,vector<vector<int>> adj[]){
	    vector<pair<int,pair<int,int>>> edges;
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i]){
	            int adjNode = it[0];
	            int wt = it[1];
	            int node = i;
	            
	            edges.push_back({wt,{node,adjNode}});
	        }
	    }
	    
	    DisjointSet ds(V);
	    
	    sort(edges.begin(),edges.end());
	    int mstWt = 0;
	    
	    for(auto it : edges){
	        int wt = it.first;
	        int u = it.second.first;
	        int v = it.second.second;
	        
	        // checking if they are not part of same component 
	        if(ds.findUltimateParent(u)!=ds.findUltimateParent(v)){
	            mstWt+=wt;
	            ds.unionBySize(u,v);
	        }
	    }
	   return mstWt;
	}
	
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
//     int spanningTree(int V, vector<vector<int>> adj[]){
        
// 		priority_queue<pair<int, int>,
// 		               vector<pair<int, int> >, greater<pair<int, int>>> pq;
        
//         // vector<pair<int,int>> mst ;
//         vector<int> vis(V,0);
//         int sum = 0;
        
//         // wt, node
//         pq.push({0,0});
        
//         while(!pq.empty()){
//             int node = pq.top().second;
//             int wt = pq.top().first;
//             pq.pop();
            
//             // If its already part of the MST , then move on..
//             if(vis[node]) continue;
            
//             // it wasnt . So now become a part of MST :)
//             vis[node] = 1;
//             sum+=wt;
            
//             // we will check its adjacent nodes
//             for(auto it:adj[node]){
//                 int adjNode = it[0];
//                 int edgeWt = it[1];
//                 if(!vis[adjNode]){
//                     pq.push({it[1],it[0]});
//                     // Dont mark it as visited !!  . 
//                     // We only mark it visited when we are sure to add it to the MST
//                 }
//             }

//         }
        
//         return sum;
        
        
//     }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends