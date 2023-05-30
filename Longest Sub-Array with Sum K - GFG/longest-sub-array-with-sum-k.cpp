//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int N, int K) 
    { 
        int sum = 0;
        int maxi = 0;
        map<int,int> mp;
        
        for (int i = 0; i < N; i++) {
            sum+=nums[i];
            
            if(sum==K){
                maxi = max(maxi,i+1);
            }
            
            int rem = sum-K;
            
            if(mp.find(rem)!=mp.end()){
                int len = i-mp[rem];
                maxi = max(maxi,len);
            }
            
            if(mp.find(sum)==mp.end()){
                mp[sum] = i;
            }
        }
        
        return maxi;
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