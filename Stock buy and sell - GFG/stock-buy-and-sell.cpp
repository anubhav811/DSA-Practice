//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

/*
In this GFG version we have to find all the segments where we can make a local maximal profit , multiple buy-sell pair are allowed 
Check LC version for different variant.

Approach :
1) We put buy and sell pointer at 0.
2)We check if next element is bigger than the current i , if it is then we can move sell ahead by 1 (implying that we can sell at a greater amount)
3) If its not bigger , that means the current position of sell shows the max profit we can make in the particular segment , so now we reset buy and sell to i+1
4) Before reseting just add the pair of buy,sell to the result array

As the loop works till n-1
we have to check step 3 and 4 for one last time after the loop ends.
*/ 

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> stockBuySell(vector<int> A, int n){
        
        vector<vector<int>> res;
        
        int buy = 0;
        int sell = 0;
        
        for(int i=0;i<n-1;i++){
           if(A[i+1]>A[i]){
               sell++;
           }
           else{
               if(sell>buy){
                   res.push_back({buy,sell});
               }
               sell = i+1;
               buy = i+1;
           }
        }
       
        if(sell>buy){
            res.push_back({buy,sell});
        }
        
        return res;
        
    }
};


//{ Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}


// } Driver Code Ends