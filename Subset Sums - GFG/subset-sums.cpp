// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void solveRecur(int start ,int sum , vector<int> &arr, int N , vector<int> &sumSubset){
        
        // if start pointer reaches end
        if(start == N){
            sumSubset.push_back(sum);
            return;
        }
        
        // if picked
        solveRecur(start+1,sum + arr[start], arr, N , sumSubset);
        
        // if not picked
        solveRecur(start+1,sum,arr,N,sumSubset);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        solveRecur(0,0,arr,N,res);
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends