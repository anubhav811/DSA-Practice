class Solution {
public:
  public:
    // for sorting descending order
      static bool cmp(string &a, string &b){
        return a.length() < b.length();
    }
    
    // LCS APPROACH (Extra O(N^2) Total N*N*N*N)
    int lcs(string a, string b)
    {
        int n = a.size(), m = b.size();
        int dp[n+1][m+1];
        
        int i,j;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max({dp[i-1][j],dp[i][j-1]});
            }
        }
        
        return dp[n][m];
    }

    // Compare function APPROACH 
    //     // TC : O(N*N * l) -> l is the length of longest string 

    bool compare(string& s1, string& s2){
        if(s1.size() != s2.size()+1) return false;
        
        int first = 0 ;
        int second = 0;
        
        while(first<s1.size()){
            if(s1[first]==s2[second] and second<s2.size()) {
                first++;
                second++;
            }
            else{
                first++;               
            }
        }
        
        if(first==s1.size() and second==s2.size()) return true;
        return false;
    }


    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
        vector<int> dp(n,1);
        int maxi = 0;
        
        sort(words.begin(),words.end(),cmp);
        
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(dp[prev]+1 >=  dp[i] and compare(words[i],words[prev])){
                    dp[i] = 1+ dp[prev];
                }
            }
            maxi = max(dp[i],maxi);
        }
        
        return maxi;
    }
};