class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        unordered_map<int,int> availability;
        unordered_map<int,int> want;
        
        for(auto it: nums)
            availability[it]++;
        
        for(auto it: nums)
        {
            if(!availability[it]) continue;
            availability[it]--;
            
            if(want[it-1]>0){
                want[it-1]--;
                want[it]++;
            }
            else if(availability[it+1] && availability[it+2]){
                availability[it+1]--;
                availability[it+2]--;
                want[it+2]++;
            }
            else return false;
        }
    return true;
    }
};