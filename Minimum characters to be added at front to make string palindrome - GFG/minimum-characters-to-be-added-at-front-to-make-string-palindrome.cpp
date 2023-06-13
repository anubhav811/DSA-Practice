//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
     vector<int> createLPStable(string str){
        int i=0,j=1;
        int n = str.size();
        vector<int> lps(n,0);
        while(j<n){
            if(str[i]==str[j]){
                lps[j]=i+1;
                i++;
                j++;
            }
            else{
                if(i==0){
                    lps[j]=0;
                    j++;
                }
                else{
                    i = lps[i-1];
                }
            }
        }
        return lps;
    }
    int minChar(string s){
        
        string rev = s;
        reverse(rev.begin(),rev.end());
        if(rev==s){
            return 0;
        } 
        string ns  = s +"&"+rev;
        vector<int> lps = createLPStable(ns);  

        int n = ns.size();

        // strip off lps substring
        ns = ns.substr(0,n-lps[n-1]);

        return ns.size()-s.size()-1;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends