class Solution {
public:
    void removeDupWord(string str,vector<string> &s)
    {
    istringstream ss(str);
 
    string word; 
    while (ss >> word)
    {
        s.push_back(word);
    }
}
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        vector<vector<string>> res;
        unordered_map<string,set<string>> mp;
        
        
        for(auto it : paths){
            
            vector<string> s ;
            removeDupWord(it,s);
            vector<string> files(s.size(),"");
            copy(s.begin(),s.end(),files.begin());
            
            string mainRoot = files[0];
            
            for(int i=1 ;i<files.size();i++){
                
                string t = files[i];
                                
                unsigned first = t.find("(");
                unsigned last = t.find_last_of(")");
                string content = t.substr (first+1,last-first-1);
                
                unsigned last2 = t.find("(");
                string fileName = t.substr (0,last2);
                
                mp[content].insert(mainRoot+"/"+fileName);
            }
        }
        
        for(auto it: mp){
            vector<string> paths(it.second.begin(),it.second.end());
            if(paths.size()>1)
                res.push_back(paths);
        }
        return res;
    }
};