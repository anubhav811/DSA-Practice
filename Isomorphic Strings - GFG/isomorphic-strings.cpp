//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
        if(s.size()!=t.size()) return false;

        map<char,char> mp;
        set<int> st;

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                if(st.find(t[i])==st.end()){
                    mp[s[i]]=t[i];
                    st.insert(t[i]);
                }else{
                    return false;
                }
            }else{
                if(mp[s[i]]!=t[i])
                    return false;
            } 
        }

        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends