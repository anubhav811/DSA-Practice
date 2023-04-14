#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tab (int k,int n,vector<int> & arr){
        vector<int> dp (n+1,0);
        dp[n] = 0;
        for(int i = n-1;i>=0;i--){
            int maxi = INT_MIN;
            int maxAns= INT_MIN;
            int sum = 0;
            int len = 0;

            for(int ind = i ; ind<min(n,i+k) ; ind++){
                len++;
                maxi = max(arr[ind],maxi);
                sum = maxi*len + dp[ind+1];
                maxAns = max(maxAns,sum);
            }   
            dp[i] = maxAns;
        }
        return dp[0];
    }
    int memo (int i, int k ,int n , vector<int>& arr,vector<int>& dp){
        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];
        int maxi = INT_MIN;
        int maxAns= INT_MIN;
        int sum = 0;
        int len = 0;

        for(int ind = i ; ind<min(n,i+k) ; ind++){
            len++;
            maxi = max(arr[ind],maxi);
            sum = maxi*len + memo(ind+1,k,n,arr,dp);
            maxAns = max(maxAns,sum);
        }   
        return dp[i] = maxAns;
    }
    int recur(int i, int k ,int n ,vector<int>& arr){

        if(i==n) return 0;

        int maxi = INT_MIN;
        int maxAns= INT_MIN;
        int sum = 0;
        int len = 0;

        for(int ind = i ; ind<min(n,i+k) ; ind++){
            len++;
            maxi = max(arr[ind],maxi);
            sum = maxi*len + recur(ind+1,k,n,arr);
            maxAns = max(maxAns,sum);
        }   
        return maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        // return recur(0,k,n,arr);    // TC :  Exponential 
                                       // SC : O(N)

        // vector<int> dp(n,-1);       // TC : O(N*k)
        // return memo(0,k,n,arr,dp);  // SC : O(N) + Auxiliary stack space O(N)

        return tab(k,n,arr);           // TC : O(N*k) 
                                       // SC : O(N)
    }   
};
int main()
{

    return 0;
}