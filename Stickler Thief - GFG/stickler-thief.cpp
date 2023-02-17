//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int spaceOpt(vector<int> arr)
    {
        // int n = arr.size();
        // int prev = arr[0]; // this is zero wala (agar i=1 hai , matlab usse just pehle wala isliye 'prev' )
        // int prev2 = 0;     // this is negative wala (agar i=1 hai , usee pehle ke pehle wala isliye 'prev2')
        // for (int i = 1; i < n; i++)
        // {
        //     int take = arr[i];
        //     if (i > 1)
        //         take += prev2;
        //     int nottake = 0 + prev;

        //     int curr = max(take, nottake);

        //     prev2 = prev;
        //     prev = curr;
        // }

        // return prev;
            int n = arr.size();
    long long int prev = arr[0];
    long long int prev2 =0;
    
    for(int i=1; i<n; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        int long long nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;

    }
    int FindMaxSum(int arr[], int n)
    {
        vector<int> arr1;
        vector<int> arr2;
        
        if(n==1)
           return arr[0];
        
        if(arr[0]!=arr[n-1]){
            vector<int> v;
            for(int i=0;i<n;i++){
                v.push_back(arr[i]);
            }
            return spaceOpt(v);
}
for(int i=0; i<n; i++){
            
            if(i!=0) arr1.push_back(arr[i]);
            if(i!=n-1) arr2.push_back(arr[i]);
        }
        
        long long int ans1 = spaceOpt(arr1);
        long long int ans2 = spaceOpt(arr2);
        
        return max(ans1,ans2);

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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends