class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
    
        // const int mod = 1e9 + 7;
        int n = arr.size();
        int s1 =0,sum=0;
        for(auto it:arr){
            sum+=it;
        }
        if (sum < abs(d) || (sum - d) % 2) {
            return 0;
        }
        s1 = (d+sum)/2;

        int dp[n+1][s1+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<s1+1;j++)
            {
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<s1+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]);
                }
                else
                    dp[i][j] = (dp[i-1][j]);
            }
        }
        return (dp[n][s1]);
    }
};