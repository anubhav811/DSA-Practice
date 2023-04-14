#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
class Solution {
public:

    // TC: O(N*N)  SC:O(2*N)

    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);

        int maxi = 0;

        for(int i = 0 ; i <n ;i++){
            for(int prev = 0 ; prev<i; prev++){
                if(1 + dp[prev] > dp[i] && nums[i]>nums[prev]){
                    dp[i] = dp[prev] + 1;
                    count[i] = count[prev];
                }
                else if(1+dp[prev]==dp[i] && nums[i]>nums[prev]){
                    count[i] += count[prev];
                }
            }
            maxi = max(maxi,dp[i]);
        }

        int res = 0;
        for(int i = 0 ; i<n ;i++){
            if(dp[i]==maxi) res+=count[i];
        }
        
        return res;

    }
};