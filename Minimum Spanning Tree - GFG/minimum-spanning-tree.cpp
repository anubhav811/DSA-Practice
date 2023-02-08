//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        
		priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;
        
        // vector<pair<int,int>> mst ;
        vector<int> vis(V,0);
        int sum = 0;
        
        // wt, node
        pq.push({0,0});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            // is it already part of the MST
            if(vis[node]) continue;
            
            // it wasnt . So now become a part of MST :)
            vis[node] = 1;
            sum+=wt;
            
            // we will check its adjacent nodes
            for(auto it:adj[node]){
                int adjNode = it[0];
                int edgeWt = it[1];
                if(!vis[adjNode]){
                    pq.push({it[1],it[0]});
                    // Dont mark it as visited !!  . 
                    // We only mark it visited when we are sure to add it to the MST
                }
            }

        }
        
        return sum;
        
        
    }
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