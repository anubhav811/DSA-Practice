//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int recur(int i,int j1,int j2,vector<vector<int>>& grid,int n,int m){
        if(j1<0 || j1>=m || j2<0 || j2>=m)
            return -1e9;
        if(i==n-1){
            if(j1==j2)  
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        
        int maxi = INT_MIN;
        for(int d1=-1;d1<=1;d1++){
           for(int d2=-1;d2<=1;d2++){
               int ans = INT_MIN;
                if(j1==j2)  
                    ans = grid[i][j1] + recur(i+1,j1+d1,j2+d2,grid,n,m);
                else
                    ans= grid[i][j1] + grid[i][j2] + recur(i+1,j1+d1,j2+d2,grid,n,m);
                maxi = max(ans,maxi);
           } 
        }
        
        return maxi;
    }
    
    int memo(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, 
    vector<vector<vector<int>>> & dp) {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;
    
        if (i == n - 1) {
            if (j1 == j2)
              return grid[i][j1];
            else
              return grid[i][j1] + grid[i][j2];
        }
        
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        int maxi = INT_MIN;
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                int ans;
                if (j1 == j2)
                    ans = grid[i][j1] + memo(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
                else
                    ans = grid[i][j1] + grid[i][j2] + memo(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
                
                maxi = max(maxi, ans);
            }
          }
          return dp[i][j1][j2] = maxi;
    }
    
    
    
    int tab(int n, int m, vector<vector<int>>& grid) {
        
        vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, vector < int > (m, 0)));
        
          for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
              if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
              else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
          }
        
          //Outer Nested Loops for travering DP Array
          for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
              for (int j2 = 0; j2 < m; j2++) {
        
                int maxi = INT_MIN;
        
                //Inner nested loops to try out 9 options
                for (int di = -1; di <= 1; di++) {
                  for (int dj = -1; dj <= 1; dj++) {
        
                    int ans;
        
                    if (j1 == j2)
                      ans = grid[i][j1];
                    else
                      ans = grid[i][j1] + grid[i][j2];
        
                    if ((j1 + di < 0 || j1 + di >= m) ||
                      (j2 + dj < 0 || j2 + dj >= m))
        
                      ans += -1e9;
                    else
                      ans += dp[i + 1][j1 + di][j2 + dj];
        
                    maxi = max(ans, maxi);
                  }
                }
                dp[i][j1][j2] = maxi;
              }
            }
          }
        
          return dp[0][0][m - 1];
        
        }

    int spaceOpt(int n, int m, vector<vector<int>>& grid) {
        
        vector<vector<int>> front(m,vector<int> (m, 0));
        vector<vector<int>> curr(m,vector<int> (m, 0));
        
        vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, vector < int > (m, 0)));
        
          for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
              if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
              else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
          }
        
          //Outer Nested Loops for travering DP Array
          for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
              for (int j2 = 0; j2 < m; j2++) {
        
                int maxi = INT_MIN;
        
                //Inner nested loops to try out 9 options
                for (int di = -1; di <= 1; di++) {
                  for (int dj = -1; dj <= 1; dj++) {
        
                    int ans;
        
                    if (j1 == j2)
                      ans = grid[i][j1];
                    else
                      ans = grid[i][j1] + grid[i][j2];
        
                    if ((j1 + di < 0 || j1 + di >= m) ||
                      (j2 + dj < 0 || j2 + dj >= m))
        
                      ans += -1e9;
                    else
                      ans += front[j1 + di][j2 + dj];
        
                    maxi = max(ans, maxi);
                  }
                }
                curr[j1][j2] = maxi;
              }
            }
            front = curr;
          }
        
          return front[0][m - 1];
        
        }


    int solve(int n, int m, vector<vector<int>>& grid) {
        
        // Recursion              TC : O(3^n * 3^n)
        // TLE                    SC : O(n)
        // return recur(0,0,m-1,grid,n,m);    
        
        
        // Memoization  Passed    TC : O(N*M*M)*9
        //                        SC : O(N*M*M) + O(N)
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m, -1)));
        // return memo(0, 0, m - 1, n, m, grid, dp);
        
        
        // Tabulation             TC : O(N*M*M)*9
        //                        SC : O(N*M*M)
        // return tab(n,m,grid);
        
        // Space Optimized             TC : O(N*M*M)*9
        //                        SC : O(M*M)        
        return spaceOpt(n,m,grid);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends