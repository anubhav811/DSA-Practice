class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
            
        int size = strs.size();
            
        int dp[size+1][m+1][n+1];
        int ans = 0;
        
        for(int i=0;i<=size;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    dp[i][j][k]=0;
                }
            }
        }
        
        for(int i=1;i<=size;i++){
            
            int zCount=count(strs[i-1].begin(),strs[i-1].end(),'0');
            int oCount=count(strs[i-1].begin(),strs[i-1].end(),'1');
            
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    
                    dp[i][j][k] = dp[i-1][j][k];
                    
                    if(j-zCount>=0 and k-oCount>=0){
                     dp[i][j][k] = max(dp[i][j][k],1+dp[i-1][j-zCount][k-oCount]);
                    }
                      ans = max(ans,dp[i][j][k]);
                }
                
            }
        }
       
        
       return ans;
    }
};