//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int x,int y,vector<vector<int>> &vis , vector<vector<int>> &grid,set<vector<pair<int,int>>> &s,
    vector<pair<int,int>> &shape ,int xi , int yi){
        vis[x][y]=1;
        
        shape.push_back({x-xi,y-yi});
        
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,1,0,-1};
        

        for(int i=0;i<4;i++){
            int row = x+delrow[i];
            int col = y+delcol[i];
            
            if(row<grid.size() && row>=0 && col<grid[0].size() && col>=0 && !vis[row][col] && grid[row][col]==1){
                dfs(row,col,vis,grid,s,shape,xi,yi);
            } 
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> s;     

        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]==1){
                        vector<pair<int,int>> shape;
                        dfs(i,j,vis,grid,s,shape,i,j);
                        s.insert(shape);
                }
            }
        }
        
        return s.size();

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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends