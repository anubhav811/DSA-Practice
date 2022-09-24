class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int maxi =0;
        vector<int> dp(n,0);
        for(auto num:nums2)
        {
            for (int i=n-1; i>0; i--)
            {
                if (nums1[i]!= num)
                    dp[i] = 0;
                else
                {
                    dp[i] = dp[i-1]+1;
                    if(dp[i]>maxi) maxi = dp[i];
                }
            }
            if (num == nums1[0])
            {
                dp[0] = 1;
                if(maxi == 0) maxi = 1;
            }
            else  dp[0] = 0;
        }
       return maxi; 
    
    }
};