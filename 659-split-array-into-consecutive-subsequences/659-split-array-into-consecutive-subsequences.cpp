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
            
            if(want[it]>0){
                availability[it]--;
                want[it]--;
                want[it+1]++;
            }
            else if( availability[it] && availability[it+1] && availability[it+2]){
                availability[it]--;
                availability[it+1]--;
                availability[it+2]--;
                want[it+3]++;
            }
            else return false;
        }
    return true;
    }
};