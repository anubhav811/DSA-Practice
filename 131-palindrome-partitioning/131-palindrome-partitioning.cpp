class Solution {
public:
bool isPalindrome(string s){
    string temp = s;
    reverse(s.begin(),s.end());
    if(temp==s) return true;
    return false;
}
void findPartition(int start , vector<string> &partition , vector<vector<string>> &ans,string s){
    if(start == s.length()){
        ans.push_back(partition);
        return;
    }
    for(int i = start ; i<s.size();i++){
        if(isPalindrome(s.substr(start,i-start+1))){
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