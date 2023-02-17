class Solution {
public:
    vector<int> memo;
    
    bool recurSolve(int start,  string &s , vector<string> &wordDict){
        
       if (memo[start] >= 0)
            return memo[start];
        
        if (start == s.size())
        {
            return true;
        }        
        
        for (auto word: wordDict)
        {
            if (start + word.size()-1 <= s.size() && s.substr(start, word.size()) == word)
            {
                memo[start+word.size()] = recurSolve(start + word.size(),s, wordDict);
                if (memo[start+word.size()])
                    return true;
            }
        }
        
        memo[start] = false;
        return memo[start];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector<int>(s.size()+1, -1);
        return recurSolve(0,s,wordDict);
    }
};