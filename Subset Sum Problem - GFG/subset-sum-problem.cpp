//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public: 
    bool recur(vector<int> arr, int i , int sum){
        
        if(sum==0)
            return true;
            
        if(i==0)
            return arr[0]==sum;


        bool pick = (arr[i]<=sum) ? recur(arr,i-1,sum-arr[i]) : false;
        bool notPick = recur(arr,i-1,sum);
        
        return pick||notPick;
        
    }
    bool memo(vector<int> &arr, int i , int sum, vector<vector<int>> &dp){
        
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(sum==0)
            return true;
            
        if(i==0)
            return arr[0]==sum;

        bool pick = (arr[i]<=sum) ? recur(arr,i-1,sum-arr[i]) : false;
        bool notPick = recur(arr,i-1,sum);
        
        return dp[i][sum] = pick||notPick;
        
    }
    
    bool tab(vector<int>arr , int n,int sum){
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
       
        for(int i=0;i<n;i++)
            dp[i][0] = true;
        
        dp[0][arr[0]] = true;
      
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++){

                bool pick = (arr[i]<=j) ? dp[i-1][j-arr[i]] : false;
                bool notPick = dp[i-1][j];
                dp[i][j] = pick||notPick;       
            }
        }
        
        return dp[n-1][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        
        
        int n = arr.size();
        
        // Recursion                      TC : O(2^N)
        //                                SC : O(N)
        // return recur(arr,n-1,sum);
        
        // Memoization                      TC : O(N*target)
        //                                  SC : O(N*target) + O(N)
        // vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        // return memo(arr,n-1,sum,dp);
        
        // Tabulation                       TC : O(N*target)
        //                                  SC : O(N*target) 
        return tab(arr,n,sum);
        
        // S
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends