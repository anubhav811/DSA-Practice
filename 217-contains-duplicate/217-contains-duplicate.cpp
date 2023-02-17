class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        set<int> myset;
        for(auto it:nums){
            if(myset.find(it)!=myset.end())
                return true;
            myset.insert(it);
        }
        return false;
    }
};