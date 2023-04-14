//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool isPalindrome(int  i , int  j ,string &s){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }

    int tab(int n,string &s){

        vector<int> dp (n+1,0);
        dp[n] = 0;
        for(int i = n-1 ; i>=0;i--){
            int mini = INT_MAX;
            for(int j=i ; j<n;j++){
                if(isPalindrome(i,j,s)){
                    int cost = 1 + dp[j+1];
                    mini = min(mini,cost);
                }
            }
            dp[i] = mini;
        }

        return dp[0];
    }
    int memo(int i,int n ,string &s,vector<int> &dp){

        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];

        int mini = INT_MAX;
        for(int j=i ; j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost = 1 + memo(j+1,n,s,dp);
                mini = min(mini,cost);
            }
        }
        return dp[i] = mini;

    }
    int recur(int i,int n, string &s){

        if(i==n) return 0;
        int mini = INT_MAX;
        for(int j=i ; j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost = 1 + recur(j+1,n,s);
                mini = min(mini,cost);
            }
        }
        return mini;

    }
    int palindromicPartition(string str)
    {
        
        int n = str.size();

        // return recur(0,n,str) -1 ;          // TC :Exponential 
                                               // SC :O(N)
        // vector<int> dp(n,-1); 
        // return memo(0,n,str,dp) - 1;        // TC:O(N^3) 
                                               // SC:O(N) + O(N)


        return tab(n,str)-1;                   // TC:O(N^3) 
                                               // SC:O(N) 

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends