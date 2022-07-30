class Solution {
public:

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
       vector<int>freq(26,0);           
        for(auto word:words2){
            vector<int>temp(26,0);
            for(auto letter:word){
                temp[letter-'a']++;
                freq[letter-'a'] = max(freq[letter-'a'],temp[letter-'a']); 
            }
        }
        vector<string>res;
        for(auto word:words1){
            vector<int>temp(26,0);
            for(auto letter:word) 
            {   
                temp[letter-'a']++;
            }
            bool flag=true;
            for(int i=0 ; i<26 ; i++){
                if(freq[i]>temp[i]) {
                    flag=false;
                    break;
                }         
            }
            if(flag) {
                res.push_back(word);
            }
        }
        return res;
    
    }
};