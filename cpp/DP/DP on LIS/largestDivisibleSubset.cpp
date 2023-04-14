#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    // TC : O(N^2)  SC : O(2*N)
    vector<int> tab(int n , vector<int>& nums){
        
        vector<int> dp(n,1);
        vector<int> hash(n);
  
        // as its  a subset not subsequence we can reorder the array
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prev=0;prev<=i-1;prev++){
                if(nums[i]%nums[prev]==0){
                    if(1+ dp[prev]> dp[i]){
                        dp[i] = 1+ dp[prev] ;
                        hash[i] = prev;
                    }
                }
            }
        }

        int maxi = -1;
        int maxVal = -1;

        for(int i=0;i<n;i++){
            if(dp[i]>maxVal){
                maxVal = dp[i];
                maxi = i;
            }
        }

        vector<int> res;
        res.push_back(nums[maxi]);
        while(maxi!=hash[maxi]){
            maxi = hash[maxi];
            res.push_back(nums[maxi]);
        }

        reverse(res.begin(),res.end());

        return res;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();
            return tab(n,nums);   
    }
};
int main()
{

    return 0;
}