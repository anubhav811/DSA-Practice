//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    int tab(int x , int y , string str1, string str2,vector<vector<int>> &dp){
        
        for(int i=1;i<x+1;i++){
            for(int j=1;j<y+1;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        int lcs = tab(m,n,X,Y,dp);
        
        // IF WE NEED TO PRINT THE SHORTEST COMMON 
        // string ans = "";
        
        // int i = m;
        // int j = n;
        
        // while(i>0 || j>0){
        //     if(X[i-1]==Y[j-1]){
        //         ans+=X[i-1];
        //         i--;
        //         j--;
        //     }
        //     else if(dp[i-1][j] > dp[i][j-1]){
        //         ans+=X[i-1];
        //         i--;
        //     }
        //     else {
        //         ans+=Y[j-1];
        //         j--;
        //     }
        // }
        
        // while(i>0) {
        //    ans+=X[i-1];
        //     i--;
        //}   
        // while(j>0) {
        //    ans+=Y[j-1];
        //     j--;
        //}   
        
        // reverse(ans.begin(),ans.end());
        // cout<<ans<<endl;
        int res = m+n-lcs;
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends