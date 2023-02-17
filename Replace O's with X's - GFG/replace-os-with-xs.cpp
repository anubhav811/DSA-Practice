//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int x , int y , vector<vector<int>> &vis , vector<vector<char>> &mat,int &n , int &m){
        vis[x][y] = 1;
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        for(int i=0;i<4;i++){
            int row = x+delrow[i];
            int col = y+delcol[i];
            if(row>=0 && row<n && col>=0 && col<m && vis[row][col]==0 && mat[row][col]=='O'){
                dfs(row,col,vis,mat,n,m);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(mat[0][j]=='O' && vis[0][j]==0){
                dfs(0,j,vis,mat,n,m);
            }
            if(mat[n-1][j]=='O' && vis[n-1][j]==0){
                dfs(n-1,j,vis,mat,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && vis[i][0]==0){
                dfs(i,0,vis,mat,n,m);
            }
            if(mat[i][m-1]=='O' && vis[i][m-1]==0){
                dfs(i,m-1,vis,mat,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && vis[i][j]==0){
                        mat[i][j]='X';
                    }
                }
            }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends