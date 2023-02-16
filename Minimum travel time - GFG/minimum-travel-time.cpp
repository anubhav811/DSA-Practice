//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& grid) {
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
      vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
      int num = grid[0][0];
      dist[0][0] = num;
      pq.push({num,{0,0}});
      vector<int>row = {-1,0,1,0};
      vector<int>col = {0,1,0,-1};
      while(!pq.empty()){
        int time = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        
        pq.pop();
        for(int i = 0 ; i<4 ; i++){
          int nrow = row[i] + r;
          int ncol = col[i] + c;
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){
            int curr = grid[nrow][ncol];
            int temp = max(time,curr);
            if(nrow==n-1 && ncol==n-1){
              return temp;
            }
            if(temp<dist[nrow][ncol]){
              dist[nrow][ncol] = temp;
              pq.push({temp,{nrow,ncol}});
             
            }
            
            
            
          }
        }
        
      }
      return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends