//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,k});
        
        vector<pair<int,int>> adj[n+1];
        
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
    
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        
        while(!pq.empty()){
            int d = pq.top().first;
            int n = pq.top().second;
            
            pq.pop();
            for(auto it: adj[n]){
                int adjNode = it.first;
                int edgeWt = it.second;
                if(d+edgeWt<dist[adjNode])
                {
                    dist[adjNode] = d+edgeWt;
                    pq.push({dist[adjNode],adjNode});
                }
            }        
            
        }
        
        int maxi = -1;
        for(int i = 1 ; i <= n ; i++){
            if(dist[i] == 1e9)
                return -1;
            else{
                maxi = max(maxi , dist[i]);
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends