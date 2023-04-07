//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        // Code here
        vector<int> dp(n,1);
        vector<int> count(n,1);
        
        int maxi = -1;
        int maxVal = -1; 
        
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(dp[i]<dp[prev]+1 && arr[i]>arr[prev]){
                    dp[i] = dp[prev] + 1;
                    count[i] = count[prev];
                }
                else if(dp[i]==dp[prev]+1 && arr[i]>arr[prev]){
                    count[i] += count[prev] ;
                }
            }
            if(dp[i]>maxVal){
                maxVal = dp[i];
                maxi = i;
            }
            
        }
        
        int res = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxVal)
                res += count[i];
        }
        return res;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends