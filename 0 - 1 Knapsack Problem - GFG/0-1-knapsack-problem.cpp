//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{    
    public:
    int knapSackDp(int w,int wt[] , int val[] , int n) {
        vector<vector<int>> t(n + 1, vector<int>(w + 1, -1));
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<w+1;j++){
                if(i==0||j==0)
                    t[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<w+1;j++){
                if(wt[i-1]<=j){
                    t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]],t[i-1][j]);
                }
                else if(wt[i-1] > j){
                    t[i][j] = t[i-1][j];
                }
            }
            
        }
        
        return t[n][w];
        
    }  
    int knapsackMemoization(int w, int wt[], int val[], int n, vector<vector<int>> &t)
    {
        if (n == 0 || w == 0)
        {
            return 0;
        }
    
        if (t[n][w] != -1)
            return t[n][w];
    
        if (wt[n - 1] <= w)
        {
            return t[n][w] = max(val[n - 1] + knapsackMemoization(w - wt[n - 1], wt, val, n - 1, t), knapsackMemoization(w, wt, val, n - 1, t));
        }
        else if (wt[n - 1] > w)
        {
            return t[n][w] = knapsackMemoization(w, wt, val, n - 1, t);
        }
    
        return 0;
    }
    
    int knapSack(int w, int wt[], int val[], int n) {
        vector<vector<int>> t(n + 1, vector<int>(w + 1, -1));
        // return knapsackMemoization(w,wt,val,n,t);
        return knapSackDp(w,wt,val,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends