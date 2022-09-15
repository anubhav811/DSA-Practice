class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
 
        vector < int > res;
        if(changed.size() % 2)
            return res;
        
        sort(changed.begin(), changed.end());
        map<int, int> mp;
        
        for(auto val: changed)
            mp[val]++;
        
        for(auto val: changed)
        {
            if(mp[val])
            {
                mp[val]--;
                res.push_back(val);
                
                if(mp[val*2])
                    mp[val*2]--;
                else
                    return vector<int>();
            }
        }
        
        return res;
    }
};