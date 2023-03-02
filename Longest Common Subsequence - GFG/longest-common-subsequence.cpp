//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int tab(int x, int y , string s1 , string s2){
        
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        
        for(int i=1;i<x+1;i++){
            for(int j=1;j<y+1;j++){
                    if(s1[i-1]==s2[j-1]){
                        dp[i][j] =  1 + dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
            }
        }
        
        return dp[x][y];

    }
    int memo(int i1, int i2 , string s1 , string s2,vector<vector<int>> &dp){
    
        if(i1<0 || i2<0){
            return 0 ;
        }
        
        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }
        
        if(s1[i1]==s2[i2])
            return 1+ memo(i1-1,i2-1,s1,s2,dp);
        else{
            return max (memo(i1-1,i2,s1,s2,dp) ,memo(i1,i2-1,s1,s2,dp));
        }
    }
    int recur(int i1, int i2 , string s1 , string s2){
        if(i1<0 || i2<0){
            return 0 ;
        }
        
        if(s1[i1]==s2[i2])
            return 1+ recur(i1-1,i2-1,s1,s2);
        else{
            return max (recur(i1-1,i2,s1,s2) ,recur(i1,i2-1,s1,s2));
        }
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        
        // return recur(x-1,y-1,s1,s2);     // TC : O(2^x *  2^y)
                                            // SC : O(X+Y)
        
        // vector<vector<int>> dp(x,vector<int>(y,-1));         // TC : O(X *  Y)
                                                                // SC : O(X*Y) + O(X+Y)
        // return memo(x-1,y-1,s1,s2,dp);
        
        return tab(x,y,s1,s2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends