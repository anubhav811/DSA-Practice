#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool recur(int i , int j , string p ,string s){

        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;    
        if(j<0 && i>=0){
            for(int a = 0 ; a<=i ; a++){
                if(p[a]!='*') return false;
            }
            return true;
        }

        if(p[i]==s[j] || p[i]=='?'){
            return recur(i-1,j-1,p,s);
        }
        if(p[i]=='*'){
            return recur(i-1,j,p,s) || recur(i,j-1,p,s);
        }
        return false;

    }
    bool memo(int i , int j , string p , string s , vector<vector<int>> &dp){
        
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;    
        if(j<0 && i>=0){
            for(int a = 0 ; a<=i ; a++){
                if(p[a]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(p[i]==s[j] || p[i]=='?'){
            return  dp[i][j] = memo(i-1,j-1,p,s,dp);
        }
        if(p[i]=='*'){
            return dp[i][j] = memo(i-1,j,p,s,dp) || memo(i,j-1,p,s,dp);
        }
        return  dp[i][j] =  false;
    }

    bool tab(int n , int m,string p , string s){
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));

        dp[0][0] = true;

        for(int j=1;j<m+1;j++){
            dp[0][j] = false;
        }

        for(int i=1;i<n+1;i++){
            bool flag = true;
            for(int x = 1 ; x<= i ;x++){
                if(p[x-1]!='*'){
                    flag = false;
                    break;
                }
            }

            dp[i][0] = flag;
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(p[i-1]==s[j-1] || p[i-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(p[i-1]=='*') dp[i][j] =  dp[i][j-1] + dp[i-1][j];
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }

    bool spaceOpt(int n , int m , string pat , string str){
        vector<bool> prev(m+1,false), curr(m+1,false);
        
        prev[0] = true;
        
        for(int i=1;i<n+1;i++){
            bool flag = true;
            for(int x=1;x<=i;x++){
                if(pat[x-1]!='*'){
                    flag = false;
                    break;
                }
            }
            // for every row we are assigning the zeroth column's value. Every time we go across i=0
            curr[0] = flag;
            // curr is the current rows
            // and the zeroth column has to be assigned everytime
            
            for(int j=1;j<m+1;j++){
                
                if(pat[i-1] == str[j-1] || pat[i-1]=='?'){
                    curr[j] = prev[j-1];
                }
                else if(pat[i-1]=='*'){
                    curr[j] = prev[j] + curr[j-1];
                }
                
                else{
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return curr[m];
    }
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        if(n==0 && m==0){
            return true;
        }

        // return recur(n-1,m-1,p,s);

        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return memo(n-1,m-1,p,s,dp);

        // return tab(n,m,p,s);

        return spaceOpt(n,m,p,s);
    }
};
int main()
{

    return 0;
}