//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
                       
        vector<vector<int>>effort(n,vector<int>(m,1e9));
         
        effort[0][0] = 0;
        
        pq.push({0,{0,0}});
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!pq.empty()){
            auto it=pq.top();
            int e = it.first;
            int r = it.second.first;
            int c = it.second.second; 
            pq.pop();
            
            if(r==n-1 && c==m-1)
                return e;
                
            for(int i=0;i<4;i++){
                int row = r+drow[i];
                int col = c+dcol[i];

                if(row>=0 && row<n && col>=0 && col<m){
                    int diff = max(abs(heights[row][col]-heights[r][c]),e);
                    if(diff<effort[row][col]){
                        effort[row][col] = diff;
                        pq.push({diff,{row,col}});
                    }
                }
                    
            }
        }
        return -1; 
 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends