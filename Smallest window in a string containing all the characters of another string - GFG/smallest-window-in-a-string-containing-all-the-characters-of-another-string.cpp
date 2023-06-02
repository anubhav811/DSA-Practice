//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        unordered_map<char,int> mp;
        for(auto it:p) mp[it]++;
        
        // int ansSize
        pair<int,int>  ans ={0,s.size()} ;
        int count = mp.size();
        
        int i=0,j=0;
        
        bool flag = true;
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) count--;
            }
            
            if(count>0){
                j++;
            }
            else if(count==0){
                flag = false;
                while(count==0){
                    int winSize = j-i+1;
                    int currMin = ans.second-ans.first+1;
                    if(winSize<currMin){
                        ans={i,j};
                    }
                    if(mp.find(s[i]) != mp.end())
                    {
                        mp[s[i]]++;
                        if(mp[s[i]] == 1) 
                            count++; 
                    }
                    i++;
                }
                j++;
            }
        }
        
        if(flag) return "-1";
        
        string res;
        for(int x=ans.first;x<=ans.second;x++) res.push_back(s[x]);
        return res;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends