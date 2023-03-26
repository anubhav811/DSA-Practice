//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	int tab(int x, int y, string s1,string s2){
	    
	    vector<vector<int>> dp(x+1,vector<int>(y+1,0));
	    
	    for(int i=1;i<x+1;i++){
	        for(int j=1;j<y+1;j++){
	            if(s1[i-1]==s2[j-1]){
	                dp[i][j] = 1 + dp[i-1][j-1];
	            }
	            else{
	                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    
	    return dp[x][y];
	}

	public:
	int minOperations(string str1, string str2) 
	{ 
        
        if(str1==str2)
            return 0;
        
        int m = str1.size();
        int n = str2.size();
    
	    int l = tab(m,n,str1,str2);
	   
	    int deletions = m-l;
	    
        int insertions = n-l;
        
        return deletions + insertions;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends