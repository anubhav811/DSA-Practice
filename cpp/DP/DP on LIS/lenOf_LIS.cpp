#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int binSrch(int n , int a[]){
        
        vector<int> temp;
        temp.push_back(a[0]);
            
        for(int i=1;i<n;i++){
            
            if(a[i]>temp[temp.size()-1]){
                temp.push_back(a[i]);
            }
            else{
                int x = lower_bound(temp.begin(),temp.end(),a[i])-temp.begin();
                temp[x] = a[i];
            }
        }
        return temp.size();
    }
    
    
    int tab2(int n , int A[]){
        vector<int> dp(n,1);
        
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(A[prev]<A[i]){
                    dp[i] = max(dp[i],1+dp[prev]);
                }
    
            }
            maxi = max(dp[i],maxi);
        }
        
        return maxi;
        
    }
    int spaceOpt(int n , vector<int>&A){
        
        vector<int> curr(n+1,0) , next(n+1,0);

        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int pick= (j==-1 || A[i]>A[j]) ?  1+ next[i+1]: 0;
                int notPick = next[j+1];
                
                curr[j+1] = max(pick,notPick);
            }
            next = curr;
        }

        return curr[0];
    }
    int tab(int n , vector<int>&A){
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int pick= (j==-1 || A[i]>A[j]) ?  1+ dp[i+1][i+1]: 0;
                int notPick = dp[i+1][j+1];
                
                dp[i][j+1] = max(pick,notPick);
            }
        }

        return dp[0][0];
    }
    int memo(int i , int prev , vector<int>&A , int n ,vector<vector<int>> &dp){
        if(i==n) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int pick= (prev==-1 || A[i]>A[prev]) ?  1+ memo(i+1,i,A,n,dp) : 0;
        int notPick = memo(i+1,prev,A,n,dp);

        return dp[i][prev+1] = max(pick,notPick);
    }
    int recur(int i , int prev , vector<int>&A,int n){
        if(i==n) return 0;

        int pick= (prev==-1 || A[i]>A[prev]) ?  1+ recur(i+1,i,A,n) : 0;
        int notPick = recur(i+1,prev,A,n);

        return max(pick,notPick);
    }

    /*  BRUTE FORCE BAD

    vector<vector<int>> AllPossibleSubseq(vector<int> &A) {
	int n = A.size();
	vector<vector<int>>ans;
	for (int num = 0; num < (1 << n); num++) {
		vector<int> sub ;
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				sub.push_back(A[i]);
			}
		}
		if (sub.size() > 0) {
			ans.push_back(sub);
		}
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    int generateAllandThenFilter(vector<int> &A){

        // generating all subsequences
        vector<vector<int>> subs = AllPossibleSubseq(A); 

        int len = 0;
        for(auto sub : subs){
            bool flag = true;
            for(int i=0;i<sub.size()-1;i++){
                if(sub[i]>=sub[i+1]) {
                    flag = false;
                    break;
                }
            }
            if(flag){
                int n = sub.size();
                len = max(n,len);
            }
        }

        return len;

    }
    */
    int lengthOfLIS(vector<int>& A) {
        int n = A.size();
        
        // worst                                    TC : exponential ( 2n )  SC : bohot zyada
        // return generateAllandThenFilter(A);

        // ok                                   TC : 2^n ,  SC : O(N)
        // return recur(0,-1,A,n);

        // better                                     TC : O(N*N) ,  SC : O(N*N) + O(N)
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return memo(0,-1,A,n,dp);

        // best                                         TC: O(N*N) ,  SC : O(N*N)
        // return tab(n,A);
        
        // bestest                                       TC: O(N*N) ,  SC : O(N)
        // return spaceOpt(n,A);

        // bestum best (usefull when we need to trace the LIS (backtrack))    TC: O(N*N) ,  SC : O(N)
        // return tab2(n,A);
        
        // ye wala pakka best (Uses Binary Search) -> cant be used for printing LIS tho
                                                            // TC : O(N*Log(N)) SC : O(N)
        return binSrch(n,A);
    }
};



int main()
{

    return 0;
}