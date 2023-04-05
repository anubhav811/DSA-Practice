//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long spaceOpt(int n ,vector<long long> & prices){
        vector<vector<long long>> curr(2,vector<long long>(2,0)),next(2,vector<long long>(2,0));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int t=0;t<=1;t++){
                    if(j==0){
                        if(t==1){
                            curr[j][t] = next[0][0];
                        }
                        else{
                            curr[j][t] = max(next[0][0], -prices[i] + next[1][1]);
                        }  
                    }
                    if(j==1){
                            curr[j][t] = max(next[1][0] , prices[i] + next[0][1]);
                    }   
                }
            }
            next=next;
        }

        return curr[0][0];
    }
    long long tab(int n ,vector<long long>& prices){
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(2,vector<long long>(2,0)));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int t=0;t<=1;t++){
                    if(j==0){
                        if(t==1){
                            dp[i][j][t] = dp[i+1][0][0];
                        }
                        else{
                            dp[i][j][t] = max(dp[i+1][0][0], -prices[i] + dp[i+1][1][1]);
                        }  
                    }
                    if(j==1){
                            dp[i][j][t] = max(dp[i+1][1][0] , prices[i] + dp[i+1][0][1]);
                    }   
                }
            }
        }

        return dp[0][0][0];

    }
    long long memo(int i , int buy , int cooldown , vector<long long>& prices,vector<vector<vector<long long>>> &dp){
            
        if(i==prices.size()) return 0;

        if(dp[i][buy][cooldown] != -1) return dp[i][buy][cooldown];
        int profit ;
        if(buy==0){
            if(cooldown){
                profit = memo(i+1,0,0,prices,dp);
            }
            else{
                profit = max(memo(i+1,0,0,prices,dp) , -prices[i] + memo(i+1,1,1,prices,dp));
            }
        } 
        if(buy==1){
    
            profit = max(memo(i+1,1,0,prices,dp) , prices[i] + memo(i+1,0,1,prices,dp));
            
        }   
        
        return dp[i][buy][cooldown] = profit;

    }
    
    long long recur(int i , int buy , int cooldown, vector<long long> &prices){

        if(i==prices.size()) return 0;
        int profit ;
        if(buy==0){
            if(cooldown){
                profit = recur(i+1,0,0,prices);
            }
            else{
                profit = max(recur(i+1,0,0,prices) , -prices[i] + recur(i+1,1,1,prices));
            }
        } 
        if(buy==1){
    
            profit = max(recur(i+1,1,0,prices) , prices[i] + recur(i+1,0,1,prices));
            
        }   
        
        return profit;
    }    
    
    long long maximumProfit(vector<long long>&prices, int n) {
        
        // return recur(0,0,0,prices);    // TC : Exponential     SC : O(N*2*2) +  O(N)

        // vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(2,vector<long long>(2,-1)));
        // return memo(0,0,0,prices,dp);   // TC :  O(N*2*2)      SC : O(N*2*2) +  O(N)
 
        return tab(n,prices);           // TC : O(N*2*2)       SC : O(N*2*2)
 
        // return spaceOpt(n,prices);          // TC : O(N*2*2)       SC : O(2*2) ~ O(K)
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends