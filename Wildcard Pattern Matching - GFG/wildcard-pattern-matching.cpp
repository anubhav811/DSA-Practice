//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/

    bool recur(int i , int j , string pat , string str){
        
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(i>=0 && j<0) {
            for(int x=0;x<=i;x++){
                if(pat[x]!='*'){
                    return false;
                }
            }
            return true;
        }
        
        if(pat[i] == str[j] || pat[i]=='?'){
            return recur(i-1,j-1,pat,str);
        }
        
        if(pat[i]=='*'){
             return recur(i-1,j,pat,str) || recur(i,j-1,pat,str);
        }
        
        return false;
    }
    
    int memo(int i , int j , string pat , string str,vector<vector<int>> &dp){
        
        
        if(i<0 && j<0) return 1;
        if(i<0 && j>=0) return 0;
        if(i>=0 && j<0) {
            for(int x=0;x<=i;x++){
                if(pat[x]!='*'){
                    return 0;
                }
            }
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(pat[i] == str[j] || pat[i]=='?'){
            return dp[i][j]=memo(i-1,j-1,pat,str,dp);
        }
        
        if(pat[i]=='*'){
             return dp[i][j]=memo(i-1,j,pat,str,dp) || memo(i,j-1,pat,str,dp);
        }
        
        return dp[i][j]=0;
    }
    int wildCard(string pat,string str)
    {
        int n = pat.size();
        int m = str.size();
        
        
        // return recur(n-1,m-1,pat,str);
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return (memo(n-1,m-1,pat,str,dp)) ? 1 : 0;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends