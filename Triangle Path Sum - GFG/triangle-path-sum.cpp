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
        

        int below=INT_MAX,belAdj = INT_MAX;
        
        if(i+1<triangle.size())
            below = triangle[i][j] + recur(i+1,j,triangle);
        if(i+1<triangle.size() && j+1<triangle[i].size())
            belAdj = triangle[i][j] + recur(i+1,j+1,triangle);
            
        return min(below,belAdj);
    }
    
    int memo(int i , int j ,  vector<vector<int>> &triangle,vector<vector<int>> &dp){
        if(i==triangle.size()-1 ){
            return triangle[i][j];
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int below=INT_MAX,belAdj = INT_MAX;
        
        if(i+1<triangle.size())
            below = triangle[i][j] + recur(i+1,j,triangle);
        if(i+1<triangle.size() && j+1<triangle[i].size())
            belAdj = triangle[i][j] + recur(i+1,j+1,triangle);
            
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
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        
        // Recursion
        // return recur(0,0,triangle);
        
        // Memoization
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return memo(0,0,triangle,dp);
        
        // Tabulation
            return tab(n,triangle);
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