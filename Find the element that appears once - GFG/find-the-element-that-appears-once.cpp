//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
        
        // approach 2 XOR TC:O(N) SC:O(1)
        int xorr = A[0];
        for(int i=1;i<N;i++){
            xorr^=A[i];
        }
        
        return xorr;
        
        // approach 1 hashmap TC:O(N) SC:O(N)
        // map<int,int> mp;
        // for(int i=0;i<N;i++){
        //     mp[A[i]]++;
        // }
        
        // for(auto it:mp){
        //     if(it.second==1)
        //         return it.first;
        // }
        // return -1;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends