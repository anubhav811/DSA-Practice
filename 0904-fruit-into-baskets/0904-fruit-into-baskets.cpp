class Solution {
public:
    int totalFruit(vector<int>& s) {
        
        int ans=0;
        unordered_map<int,int> mp;
        int i=0,j=0;
        int idx = 0;
        
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()<2){
                j++;
            }
            else if(mp.size()==2){
                ans = max(ans,j-i+1);
                j++;
            }
            else if (mp.size()>2){
                while(mp.size()>2)
                {
                    mp[s[i]]--;
            
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);

                    }
                    i++;
                }
                j++;
            }
        }
        
        if(mp.size()==1){
            for(auto it: mp){
                int val = it.second;
                ans = max(ans,val);
            }
        }
      
        return ans;
    }
};