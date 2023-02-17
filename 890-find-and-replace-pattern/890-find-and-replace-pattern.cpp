class Solution {
public:
    string getPattern(string pattern){
        string numeric;
        
        if(pattern.size() == 0) return {};
          
        int start = 0;
		
        map<char,int> mp;
        
        for(int i = 0; i<pattern.size(); ++i)
        {
           if(mp.find(pattern[i]) == mp.end())
           {
               mp.insert({pattern[i],start++});
               numeric += mp[pattern[i]];
           }
            else
            {
                numeric += mp[pattern[i]];
            }    
        }
        return numeric;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        string numeric = getPattern(pattern);
        vector<string> ans;
        for(int i = 0 ; i < words.size() ; i++){
            if(getPattern(words[i])==numeric){
                ans.push_back(words[i]);
            }
                
        }
        return ans;
    }
};