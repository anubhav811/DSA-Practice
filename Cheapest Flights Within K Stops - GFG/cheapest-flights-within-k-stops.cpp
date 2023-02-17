//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        
        // making adj list
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        //distance array
        vector<int> dist (n,INT_MAX);
        dist[src] = 0;
        
        // queue // stops,{node,dist}}

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
    
        while(!q.empty()){
            auto it = q.front();
            int s = it.first;
            int n = it.second.first;
            int c = it.second.second;
            
            q.pop();
            if(s>K) continue;
            
            for(auto it:adj[n]){
                int edgeWt = it.second;
                int adjNode = it.first;
                if(c+edgeWt<dist[adjNode] && s<=K){
                    dist[adjNode] = c+edgeWt;
                    q.push({s+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends