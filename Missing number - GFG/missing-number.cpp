//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int missingNumber(int a[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i=0, n;
		cin>>n;
		int a[n+5];
		for(i=0;i<n-1;i++)
			cin>>a[i];
			
		cout<<missingNumber(a, n)<<endl;
	}
}
// } Driver Code Ends


int missingNumber(int nums[], int n)
{
        // TC: O(N) and SC:O(N)      
        int sum = (n*(n+1))/2;

        for(int i=0;i<n-1;i++){
            sum-=nums[i];
        }

        return sum;
        
        // TC: O(N) and SC:O(N)      
        // vector<int> vis(n+1);

        // for(int i=0;i<n;i++){
        //     vis[nums[i]]++;
        // }

        // for(int i=0;i<vis.size();i++){
        //     if(vis[i]==0) return i;
        // }

        // return 0;
}