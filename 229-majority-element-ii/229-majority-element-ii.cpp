class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> m;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i : m){
            if(i.second>(nums.size()/3)){
                res.push_back(i.first);
            }
         }
        return res;
//         int count = 0 ;
//         int candidate = 0;
        
//         vector<int> res;
//         for(auto i : nums){
//             if(count==0)
//                 candidate = i;
//             if(i == candidate) count++;
//             else count--;
            
//             if(count>nums.size()/3)
//                 res.push_back(candidate);
//         }
     
//         return candidate;
    }
    
};