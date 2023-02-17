//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
      void dfs(int x , int y , vector<vector<int>> &vis , vector<vector<int>> &mat,int &n , int &m){
        vis[x][y] = 1;
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        for(int i=0;i<4;i++){
            int row = x+delrow[i];
            int col = y+delcol[i];
            if(row>=0 && row<n && col>=0 && col<m && vis[row][col]==0 && mat[row][col]==1){
                dfs(row,col,vis,mat,n,m);
            }
        }
    }

    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && vis[0][j]==0){
                dfs(0,j,vis,grid,n,m);
            }
            if(grid[n-1][j]==1 && vis[n-1][j]==0){
                dfs(n-1,j,vis,grid,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && vis[i][0]==0){
                dfs(i,0,vis,grid,n,m);
            }
            if(grid[i][m-1]==1 && vis[i][m-1]==0){
                dfs(i,m-1,vis,grid,n,m);
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                        count++;
                    }
                }
            }
        
        return count;
    

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
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends