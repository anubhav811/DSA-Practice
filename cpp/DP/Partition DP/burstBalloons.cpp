#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tab(int n,vector<int>&nums){
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                int maxi = 0 ;
                for(int k=i;k<=j;k++){
                    // Base Case
                    int cost = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi= max(maxi,cost);
                    dp[i][j] =  maxi; 
                }
            }
        }
        return dp[1][n];
    }
    int memo(int i , int j , vector<int> &nums,vector<vector<int>> &dp){

        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        int maxi = 0;
        for(int k=i;k<=j;k++){
            int cost = nums[i-1]*nums[k]*nums[j+1] + memo(i,k-1,nums,dp) + memo(k+1,j,nums,dp);
            maxi = max(maxi,cost);
        }

        return dp[i][j] = maxi;
    }
    int recur(int i , int j , vector<int> &nums){

        if(i>j) return 0;

        int maxi = 0;
        for(int k=i;k<=j;k++){
            int cost = nums[i-1]*nums[k]*nums[j+1] + recur(i,k-1,nums) + recur(k+1,j,nums);
            maxi = max(maxi,cost);
        }

        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);


        // return recur(1,n,nums);

        // vector<vector<int>> dp(n+2,vector<int>(n+2,-1));         // TC : O(N3) 
                                                                    // SC : O(N^2) + O(N)
        // return memo(1,n,nums,dp);

        return tab(n,nums);                                         // TC : O(N3) 
                                                                    // SC : O(N^2) 
    }
};