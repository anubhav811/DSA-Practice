//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
      // only works for positive elements
    
    int lenOfLongSubarr(int A[],  int N, int K) {
        
        // Optimized
        unordered_map<int,int> mp;
        int sum=0;
        int res=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(sum==K){
                res=i+1;
            }
            else if(mp.find(sum-K) != mp.end()){
                res = max(res,i-mp[sum-K]);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum]=i;
            }
        }
        
        return res;
     
        
        // Brute force -> store sum as key , and the length with which we get that sum as value
        
        // unordered_map<int,int> mp;
        // for(int i=0;i<N;i++){
        //     int sum = 0;
        //     for(int j=i;j<N;j++){
        //         sum+=A[j];
        //         if(mp.find(sum)!=mp.end()){
        //             int val = max(mp[sum],j-i+1);
        //             mp[sum] = val;
        //         }else{
        //             mp[sum] = j-i+1;
        //         }
        //     }
        // }
        // return mp[K]!=NULL?mp[K]:0;
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