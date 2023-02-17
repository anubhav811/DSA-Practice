class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore voting
        int count = 0 ;
        int candidate = 0;
        
        for(auto i : nums){
            if(count==0)
                candidate = i;
            if(i == candidate) count++;
            else count--;
        }
     
        return candidate;
        
        
        //  HASHMAP APproach
        // unordered_map<int,int> m;
        // int major = 0;
        // for(int i=0;i<nums.size();i++){
        //     m[nums[i]]++;
        // }
        // for(auto i : m){
        //     if(i.second >(nums.size()/2)){
        //         major = max(major,i.first);
        //     }
        //  }
        // return major;
    }
};