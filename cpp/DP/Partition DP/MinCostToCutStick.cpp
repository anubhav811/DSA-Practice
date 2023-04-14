#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int recur(int i , int j ,vector<int> &cuts){
        if(i>j) return 0;

        int mini = 1e9;
        for(int k=i;k<=j;k++){
            int cost = cuts[j+1] - cuts[i-1] + recur(i,k-1,cuts) + recur(k+1,j,cuts);
            mini = min(mini,cost);
        }
        return mini ;
    }
    int memo(int i , int j ,vector<int> &cuts,vector<vector<int>> &dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int mini = 1e9;
        for(int k=i;k<=j;k++){
            int cost = cuts[j+1] - cuts[i-1] + memo(i,k-1,cuts,dp) + memo(k+1,j,cuts,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini ;
    }
    int tab (int n,int c, vector<int> & cuts){
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));

        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                if(i>j) continue;
                int mini = 1e9;

                for(int k=i;k<=j;k++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini,cost);

                    dp[i][j] = mini;
                }
            }
        } 

        return dp[1][c];       
    }
    int minCost(int n, vector<int>& cuts) {
        
        int c = cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);

                             
        // return recur(1,c,cuts);                              // TC : Exponential  SC : O(N)
        // vector<vector<int>> dp(n,vector<int> (n,-1));        // TC : O(N*N) * N ~ O(N^3) 
                                                                // SC:O(N^2) + O(N)
        // return memo(1,c,cuts,dp);

        return tab(n,c,cuts);                                   // TC : O(N*N) * N ~ O(N^3) 
                                                                // SC:O(N^2)
    }
};