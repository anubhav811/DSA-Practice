class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        
        unordered_set<string> res;
        
        for(auto word : words){
            string curr="";
            for(auto letter : word){
               curr+=morse[letter-'a'];
            }
            res.insert(curr);
        }
        return res.size();
    }
};