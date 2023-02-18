//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int recur(int i , int j ,  vector<vector<int>> &triangle){
        if(i==triangle.size()-1 ){
            return triangle[i][j];
        }

        int below = triangle[i][j] + recur(i+1,j,triangle);
        int belAdj = triangle[i][j] + recur(i+1,j+1,triangle);
            
        return min(below,belAdj);
    }
    
    int memo(int i , int j ,  vector<vector<int>> &triangle,vector<vector<int>> &dp){

        if(dp[i][j]!=-1)
            return dp[i][j];
            
        if(i==triangle.size()-1 ){
            return triangle[i][j];
        }
        
        int below = triangle[i][j] + recur(i+1,j,triangle);
        int belAdj = triangle[i][j] + recur(i+1,j+1,triangle);
       
        return dp[i][j] = min(below,belAdj);
    }
    
    int tab(int n , vector<vector<int>>& triangle){
        vector<vector<int>> dp;
        
        for(int i=0;i<triangle.size();i++){
            vector<int> temp(i+1,INT_MAX);
            dp.push_back(temp);
        }
        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                    int below = triangle[i][j] + dp[i+1][j];
                    int belAdj = triangle[i][j] + dp[i+1][j+1];
                    dp[i][j] = min(below,belAdj);
                
            }
        }

        return dp[0][0];
    }
    
    int spaceOpt(int n , vector<vector<int>>& triangle){
        vector<int> prev(n);
        
        
        for(int j=0;j<n;j++){
            prev[j] = triangle[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--){
            vector<int> temp(n,INT_MAX);
            for(int j=i;j>=0;j--){
                    int below = triangle[i][j] + prev[j];
                    int belAdj = triangle[i][j] + prev[j+1];
                    temp[j] = min(below,belAdj);
            }
            prev = temp;
        }

        return prev[0];
    }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        
        // Recursion
        // return recur(0,0,triangle);
        
        // Memoization                                  TC : O(N*N)
        //                                              SC : O(N) + O(N*N)
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return memo(0,0,triangle,dp);
        
        // Tabulation                                   TC : O(N*N)
        //                                              SC : O(N*N)
        // return tab(n,triangle); 
        
        // Space Optimization                           TC : O(N*N)
        //                                              SC : 0(N)
        return spaceOpt(n,triangle);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends