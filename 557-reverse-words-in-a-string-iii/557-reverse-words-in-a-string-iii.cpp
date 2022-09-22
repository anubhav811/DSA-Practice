class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> tokens;
        string res; 
        
        stringstream check1(s);
     
        string intermediate;

        while(getline(check1, intermediate, ' '))
        {
            tokens.push_back(intermediate);
        }
        
        
        for(int i=0;i<tokens.size();i++){
            reverse(tokens[i].begin(),tokens[i].end());
            res+=tokens[i];
            res+=" ";
        }
        
        return res.substr(0,res.size()-1);
    }
};