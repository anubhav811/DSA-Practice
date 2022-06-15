class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        // int major = 0;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i : m){
            if(i.second >(nums.size()/3)){
                res.push_back(i.first);
            }
         }
        return res;
    }
    
};