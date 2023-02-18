//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int recur(int i, int j,vector<vector<int>> grid){
        if(j<0 || j>=grid.size())
        return -1e9;
        
        if(i==0)
        return grid[0][j];
        
        int up = grid[i][j] + recur(i-1,j,grid);
        int upL = grid[i][j] + recur(i-1,j-1,grid);
        int upR = grid[i][j] + recur(i-1,j+1,grid); 
        
        return max(up,max(upL,upR));
    }
    
    int memo(int i, int j,vector<vector<int>> grid, vector<vector<int>> dp){
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(j<0 || j>=grid.size())
        return -1e9;
        
        if(i==0)
        return grid[0][j];
            
        int up = grid[i][j] + memo(i-1,j,grid,dp);
        int upL = grid[i][j] + memo(i-1,j-1,grid,dp);
        int upR = grid[i][j] + memo(i-1,j+1,grid,dp); 
        
        return dp[i][j] =  max(up,max(upL,upR));
    }
    
    int tab(vector<vector<int>> grid){
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        // Initializing first row - base condition
        for(int j=0; j<m; j++){
            dp[0][j] = grid[0][j];
        }
        
        for(int i=1; i<n; i++){
            for(int j=0;j<m;j++){
                
                int up = grid[i][j] + dp[i-1][j];
                
                int leftDiagonal= grid[i][j];
                if(j-1>=0) leftDiagonal += dp[i-1][j-1];
                else leftDiagonal += -1e9;
                
                int rightDiagonal = grid[i][j];
                if(j+1<m) rightDiagonal += dp[i-1][j+1];
                else rightDiagonal += -1e9;
                
                dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
                
            }
        }
        
        int maxi = INT_MIN;
        
        for(int j=0; j<m;j++){
            maxi = max(maxi,dp[n-1][j]);
        }
        
        return maxi;
    }
    
    int spaceOpt(vector<vector<int>> grid){
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> prev(n);
        vector<int> curr(n);
        // Initializing first row - base condition
        for(int j=0; j<m; j++){
            prev[j] = grid[0][j];
        }
        
        for(int i=1; i<n; i++){
            vector<int> temp(n);
            for(int j=0;j<m;j++){
                
                int up = grid[i][j] + prev[j];
                
                int leftDiagonal= grid[i][j];
                if(j-1>=0) leftDiagonal += prev[j-1];
                else leftDiagonal += -1e9;
                
                int rightDiagonal = grid[i][j];
                if(j+1<m) rightDiagonal += prev[j+1];
                else rightDiagonal += -1e9;
                
               curr[j] = max(up, max(leftDiagonal,rightDiagonal));

            }
            prev = curr;
        }
        
        int maxi = INT_MIN;
        
        for(int j=0; j<m;j++){
            maxi = max(maxi,prev[j]);
        }
        
        return maxi;
    }

    
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        
        // int maxi = INT_MIN;
        // for(int j=0;j<Matrix.size();j++)
        //   maxi = max(maxi,recur(n-1,j,Matrix));
         // return maxi;
    
        // vector<vector<int>> dp(n,vector<int>(n,-1));         TC: O(N*M) SC: O(N) + O(N*M)   
        // int maxi = INT_MIN;
        // for(int j=0;j<Matrix.size();j++)
        //   maxi = max(maxi,memo(n-1,j,Matrix,dp));
        // return maxi;


        // return tab(Matrix);                              TC:O(N*M)  SC: O(N*M)
        
        
        return spaceOpt(Matrix);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends