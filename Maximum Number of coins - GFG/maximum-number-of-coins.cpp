//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int tab(int n , vector<int> &a){
            vector<vector<int>> dp(n+2,vector<int>(n+2,0));
            
            for(int i=n;i>=1;i--){
                for(int j=1;j<=n;j++){
                    if(i>j) continue;
                    int maxi = INT_MIN;
                    for(int k=i;k<=j;k++){
                        int value = a[i-1]*a[k]*a[j+1] + dp[i][k-1]+ dp[k+1][j];
                        maxi = max(value,maxi);
                        dp[i][j] = maxi;
                    }
                }
            }
            
            return dp[1][n];
        }
        
        int memo(int i , int j , vector<int> &a ,vector<vector<int>> &dp){
            if(i>j) return 0;
        
            if(dp[i][j] != -1) return dp[i][j];
            int maxi = INT_MIN;
            for(int k=i;k<=j;k++){
                int value = a[i-1]*a[k]*a[j+1] + memo(i,k-1,a,dp)+ memo(k+1,j,a,dp);
                maxi = max(value,maxi);
            }
            
            return dp[i][j]=maxi;
        }
        int recur(int i , int j , vector<int> &a){
            
            if(i>j) return 0;
            int maxi = INT_MIN;
            for(int k=i;k<=j;k++){
                int value = a[i-1]*a[k]*a[j+1] + recur(i,k-1,a) + recur(k+1,j,a);
                
                maxi = max(value,maxi);
            }
            
            return maxi;
        }
        int maxCoins(int N, vector <int> &a)
        {
            a.insert(a.begin(),1);
            a.push_back(1);
            // return recur(1,N,a);           // TC : Exponential
            
            // vector<vector<int>> dp(N+1,vector<int>(N+1,-1));        // TC : (N*N*N)  SC:O(N*N) + O(N)
            // return memo(1,N,a,dp);
            
            return tab(N,a);                                        // TC : (N*N*N)  SC:O(N*N)
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends