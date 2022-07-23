class Solution {
public:
bool isPalindrome(string s,int st,int e) {
        while(st <= e) {
            if(s[st] != s[e])
                return false;
            st++;
            e--;
        }
    return true;
  }
void findPartition(int start , vector<string> &partition , vector<vector<string>> &ans,string s){
    if(start == s.length()){
        ans.push_back(partition);
        return;
    }
    for(int i = start ; i<s.size();i++){
        if(isPalindrome(s,start,i)){
            partition.push_back(s.substr(start,i-start+1));
            findPartition(i+1,partition,ans,s);
            partition.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<string> partition;
    vector<vector<string>> ans;
    findPartition(0,partition,ans,s);
    
    return ans;
}
};