//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node, int col, int color[], vector<int> adj[]) {
        color[node] = col; 
        
        // traverse adjacent nodes
        for(auto it : adj[node]) {
            // if uncoloured
            if(color[it] == -1) {
                if(dfs(it, !col, color, adj) == false) return false; 
            }
            // if previously coloured and have the same colour
            else if(color[it] == col) {
                return false; 
            }
        }
        
        return true; 
    }

    bool bfs(int start,int V , vector<int> adj[],int color[]){
        queue<int> q;
	    color[start]=0;
	    q.push(start);
	    while(!q.empty()){ 
	        int node = q.front();
	        q.pop();
	        
	        for(auto it: adj[node]){
	            if(color[it]=-1){
	                 color[it] = !color[node];
	                 q.push(it);
	            }
	            else if(color[it]==color[node]){
	                return false;
	            }
	        }
	    }
	    return true;

    }
	bool isBipartite(int V, vector<int>adj[]){
	    
	    int color[V];
	    for(int i=0;i<V;i++){
	        color[i]=-1;
	    }
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(dfs(i,0,color,adj)==false) {
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends