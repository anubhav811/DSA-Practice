//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int N, int k) { 
        map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < N; i++) {
            //calculate the prefix sum till index i:
            sum += a[i];
    
            // if the sum = k, update the maxLen:
            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }
    
            // calculate the sum of remaining part i.e. x-k:
            int rem = sum - k;
    
            //Calculate the length and update maxLen:
            if (preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }
    
            //Finally, update the map checking the conditions:
            if (preSumMap.find(sum) == preSumMap.end()) {
                preSumMap[sum] = i;
            }
        }
        
        return maxLen;
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