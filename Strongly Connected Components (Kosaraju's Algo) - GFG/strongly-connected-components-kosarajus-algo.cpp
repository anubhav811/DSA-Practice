//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    void dfsForCountingScc(int node , vector<int> revAdj[],vector<int> &vis){
        vis[node] = 1;
        for(auto it: revAdj[node]){
            if(!vis[it])
                dfsForCountingScc(it,revAdj,vis);
        }
    }
    void dfsForReversal(int node , vector<int> adj[],stack<int> &s,vector<int> &vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it])
                dfsForReversal(it,adj,s,vis);
        }
        
        s.push(node);
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        
        stack<int> s;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
                dfsForReversal(i,adj,s,vis);
        }
        
        vector<int> revAdj[V];
        for(int i=0;i<V;i++){
            // marking all the elements 0 so , visited can be used again for counting SCCs
            vis[i]=0;
            for(auto it:adj[i]){
                revAdj[it].push_back(i);
            }
        }
        
        int scc=0;
        
        while(!s.empty()){
            int top = s.top();
            s.pop();
            if(!vis[top]){
                scc++;
                dfsForCountingScc(top,revAdj,vis);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends