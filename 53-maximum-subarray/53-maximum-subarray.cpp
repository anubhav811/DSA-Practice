class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int curr=0;
        int maxSum=0;
        bool hasPositives = false;
        for(int i = 0 ; i<nums.size();i++){
            if(nums[i]>=0){
                hasPositives = true;
                break;
            }
        }
        
        if(hasPositives){
        for(int i = 0 ; i<nums.size();i++){
            curr += nums[i];
            if(curr<0){
                curr = 0 ;
            }
            else if(curr>maxSum){
                maxSum = curr;
            }
        }
            return maxSum;

        }
        else{
            return *max_element(nums.begin(),nums.end());
        }
    }
};