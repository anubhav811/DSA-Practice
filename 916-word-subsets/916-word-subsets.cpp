class Solution {
public:

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> ans;
        
        vector<int> mainFreq(26,0);
        for(auto word:words2){
            vector<int> currFreq(26,0);
            for(auto letter:word){
                currFreq[letter-'a']++;
                mainFreq[letter-'a'] = max(mainFreq[letter-'a'],currFreq[letter-'a']);
            }
        }
        
        for(auto word:words1){
            vector<int> currFreq(26,0);
            for(auto letter:word){
                currFreq[letter-'a']++;
            }
            bool flag = true;
            
            for(int i=0;i<26 ; i++){
                if(mainFreq[i]>currFreq[i]){
                    flag = false;
                    break;
                }
            }
             if(flag){
                    ans.push_back(word);
                }
        }
        return ans;
    
    }
};