class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        vector<int> dummy ;
        for(int i = 0; i< nums.size();i++){
            if(nums[i]==0){
                zeroCount++;
            }
            else{
                dummy.push_back(nums[i]);
            }
        }
         for(int i = 0; i< zeroCount;i++){
             dummy.push_back(0);
         }
        
        nums = dummy;
    }
};