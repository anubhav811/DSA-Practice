class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        
        for(auto it:arr){
            mp[it]++;
        }
        
        priority_queue<int> q;
        for(auto it:mp){
            q.push(it.second);
        }
        
        int half = arr.size()/2;
        int count = 0;
        int removed = 0;
        
        while(count<half)
        {
            count += q.top();
            q.pop();
            removed++;
           
        }
        return removed;
    }
};