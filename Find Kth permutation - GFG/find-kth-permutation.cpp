//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        k = k-1;
        while(k--){
            next_permutation(nums.begin(),nums.end());
        }
        
        string s="";
        for(int i=0;i<n;i++){
            s+=(nums[i]+'0');
        }
        
        return s;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends