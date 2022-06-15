class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> m;
        int major = 0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i : m){
            if(i.second >(nums.size()/2)){
                major = max(major,i.first);
            }
         }
        return major;
    }
};