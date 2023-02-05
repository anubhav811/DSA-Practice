//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    // USING SET
    
      vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
      {
        // set
        set<pair<int,int>> s;
        
        // distance vector
        vector<int> disVec(V,INT_MAX);
        // setting distance of Source S to S  =  0
        disVec[S] = 0;
        // {distance from Source, The node}
        s.insert({0,S});
        
        while(!s.empty()){
            auto it = s.begin();
            auto elem = *it;
            int node = elem.second;
            int dist = elem.first;
            
            s.erase(it);

            for(auto it: adj[node]){
                
                int adjNode = it[0];
                int edgeWt = it[1];
            
                if(dist+edgeWt<disVec[adjNode]){
                    disVec[adjNode] = dist + edgeWt;
                    s.insert({disVec[adjNode],adjNode});
                }
            }
        }
        
        return disVec;
    }

    // USING PQ
    
    // vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    // {
    //     // min heap
    //     priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
    //     // distance vector
    //     vector<int> disVec(V,INT_MAX);
    //     // setting distance of Source S to S  =  0
    //     disVec[S] = 0;
    //     // {distance from Source, The node}
    //     pq.push({0,S});
        
    //     while(!pq.empty()){
    //         int node = pq.top().second;
    //         int dist = pq.top().first;
    //         pq.pop();
            
    //         for(auto it: adj[node]){
                
    //             int adjNode = it[0];
    //             int edgeWt = it[1];
            
    //             if(dist+edgeWt<disVec[adjNode]){
    //                 disVec[adjNode] = dist + edgeWt;
    //                 pq.push({disVec[adjNode],adjNode});
    //             }
    //         }
    //     }
        
    //     return disVec;
    // }
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends