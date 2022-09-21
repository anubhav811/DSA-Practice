class Solution {
public:

    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> res ;
        int sum = 0;
        for(auto it:nums){
            if(it%2==0){
                sum+=it;
            }
        }
        
        for(auto it : queries){
            
            int original = nums[it[1]];
            int toBeAdded = it[0];
            
            nums[it[1]] += toBeAdded; 
            int current =  nums[it[1]];
            
            if(current%2==0){
                if(original%2==0)
                    sum+=current-original;
                else
                    if(current%2==0)
                     sum+=current;
            }
            else{
                if(original%2==0)
                    sum-=original;
            }
            cout<<current;
            res.push_back(sum);  
        }
        return res;
    }
};