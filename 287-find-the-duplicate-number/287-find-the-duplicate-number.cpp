class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
            
        int k = 0;
        
        for(int i =1; i<nums.size();i++){
            if(nums[i]==nums[k])
                return nums[k];
            k++;
        }
        return 0;
    }
};