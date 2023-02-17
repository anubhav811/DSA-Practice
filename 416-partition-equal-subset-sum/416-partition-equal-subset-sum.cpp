class Solution {
public:
    int t[201][20001];
    bool recur(vector<int> arr, int sum , int n){
        if(n==0 || sum<=0){
            if(sum==0)
                return true;
            return false;
        }
        if(t[n][sum]!=-1)
            return t[n][sum];
        return t[n][sum]=recur(arr,sum-arr[n-1],n-1) || recur(arr,sum,n-1);
    }
    bool canPartition(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int sum = 0;
        for(auto it: nums)
            sum+=it;
        
        if(sum%2!=0)
            return false;
        
        sum = sum/2;
        
        return recur(nums,sum,nums.size());
    }
};