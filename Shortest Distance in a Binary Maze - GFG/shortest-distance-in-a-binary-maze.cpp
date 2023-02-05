//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {


        if (source.first == destination.first &&
            source.second == destination.second)
            return 0;

        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;    
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        
        dist[source.first][source.second] = 0;
        
        q.push({source,0});
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second; 
            int d = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int row = r+drow[i];
                int col = c+dcol[i];
            
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && d+1<dist[row][col]){
                    dist[row][col]=d+1;
                    if(row==destination.first && col==destination.second)
                        return d+1;
                    q.push({{row,col},dist[row][col]});
                    
                }
                    
            }
        }
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
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends