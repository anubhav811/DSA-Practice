#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
  // TC :  O(N^2) + O(len of LIS) <-  for printing we backtrack equal to len of lis
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
            vector<int> dp (n,1);
            vector<int> hash (n);
            
            for(int i=0;i<n;i++){
                hash[i] = i;
                for(int prev=0;prev<=i-1;prev++){
                    if(arr[prev]<arr[i]){
                        if(1+dp[prev]>dp[i]){
                            dp[i] = 1+dp[prev];
                            hash[i] = prev;
                        }
                    }
                }
            }
            
            int maxVal = -1;
            int maxi = -1;
            
            for(int i=0;i<n;i++){
                if(dp[i]>maxVal){
                    maxVal = dp[i];
                    maxi = i;
                }
            }
            
            
            vector<int> res;
            res.push_back(arr[maxi]);            
            while(maxi!=hash[maxi]){
                maxi = hash[maxi];
                res.push_back(arr[maxi]);
            }
            
            reverse(res.begin(),res.end());
            
            return res;
    }
};