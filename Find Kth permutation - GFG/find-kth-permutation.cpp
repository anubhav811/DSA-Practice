//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void nextPerm(vector<int> &nums){
        int pivot = -1;
        int n = nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot = i;
                break;
            }
        }
        if(pivot==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        else{
            for(int j=n-1;j>=0;j--){
                if(nums[j]>nums[pivot]){
                    swap(nums[j],nums[pivot]);
                    break;
                }
            }
            reverse(nums.begin() + pivot + 1, nums.end());
        }
        return ;
    }
    string kthPermutation(int n, int k)
    {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        k = k-1;
        while(k--){
            nextPerm(nums);
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