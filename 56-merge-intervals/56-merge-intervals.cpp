class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res ; 
        
        sort(intervals.begin(),intervals.end());
        vector<int> pair = intervals[0];
        
        for(auto it:intervals){    
            
            if(it[0]<=pair[1]){
                pair[1]=max(it[1],pair[1]);
            }
            else{
                res.push_back(pair);
                pair = it;
            }
        }
        res.push_back(pair);
        return res;
    }
};