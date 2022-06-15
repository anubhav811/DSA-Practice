class Solution {
public:
    static bool comp(string& s1, string& s2){
        return s1.length()<s2.length();
    }
  
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),comp);
        unordered_map<string,int> dp;
        int maxVal=0;
        for(string word:words){
            for(int i=0; i<word.length();i++){
                string pred = word.substr(0,i) + word.substr(i+1);
                dp[word] = max(dp[word],dp[pred]+1);
            }
            maxVal = max(maxVal,dp[word]);
        }
        return maxVal;
    }
};