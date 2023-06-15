//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int a[],  int N, int k) { 
       
         // Approach 2: Hashing 
         int maxi = 0;
         unordered_map<int,int> mp;
         int i=0;
         int sum = 0;
         while(i<N){
            sum+=a[i];
            if(sum==k)
                maxi=max(maxi,i+1);
            int target = sum-k;
            
            if(mp.find(target)!=mp.end()){
                int idx = mp[target];
                maxi = max(maxi,i-idx);
            }
            
            // if a sum previously exists we shouldnt re update . because we need longest subarray
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
            
            i++;
         }
         return maxi;
         
         
    //   // Approach 1  : For loops O(N^2)
    //   int maxi = 0;
    //   for(int i=0;i<N;i++){
    //       int sum = 0;
    //       for(int j=i;j<N;j++){
    //           sum+=a[j];
    //           if(sum==k){
    //               maxi = max(maxi,j-i+1);
    //           }
    //       }
    //   }
    //   return maxi;
    }

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends