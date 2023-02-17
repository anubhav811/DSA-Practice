class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        int n = 0 ;
        n+= mp[s[s.length()-1]];
        for(int i=s.length()-1;i>0;i--){
            if(mp[s[i]]>mp[s[i-1]]){
                n -=mp[s[i-1]];
            }
            else{
                n+=mp[s[i-1]];
            }
        }
    
        return n;
    }
};