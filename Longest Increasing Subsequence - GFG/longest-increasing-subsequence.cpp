//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
     /*  BRUTE FORCE BAD

    vector<vector<int>> AllPossibleSubseq(int A[],int n) {
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

    int generateAllandThenFilter(int A[],int n){

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
    
    // Optimized solutions better
        int spaceOpt(int n , int A[]){
        
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
    int tab(int n , int A[]){
        
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
    int memo(int i , int prev, int a[] , int n,vector<vector<int>>&dp){
        
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        
        int pick = (prev==-1 || a[i]>a[prev] ) ? 1 + memo(i+1,i,a,n,dp) : 0;
        int notPick = 0 + memo(i+1,prev,a,n,dp);
        
        return dp[i][prev+1] = max(pick,notPick);
    }
    int recur(int i , int prev, int a[] , int n){
        
        if(i<0){
            return 0;
        }
        int pick = (prev==-1 || a[i]>a[prev] ) ? 1 + recur(i+1,i,a,n) : 0;
        int notPick = 0 + recur(i+1,prev,a,n);
        
        return max(pick,notPick);
    }
    int longestSubsequence(int n, int A[])
    {
        
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
        return spaceOpt(n,A);
      
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends