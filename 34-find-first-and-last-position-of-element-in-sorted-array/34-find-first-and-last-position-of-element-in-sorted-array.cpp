class Solution {
public:
    
    int binSrch(int l , int r , vector<int> nums , int target, bool checkLeft){
        
        int ans = -1;
        while(l<=r){
            int m = (l+r)/2;
            
            if(nums[m]>target){
                r=m-1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
             else{
                ans = m;
                if(checkLeft) r=m-1;
                else l=m+1;
            }
        }
        return ans;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>  ans={binSrch(0,nums.size()-1,nums,target,true),binSrch(0,nums.size()-1,nums,target,false)} ;
        return ans;
    }
};