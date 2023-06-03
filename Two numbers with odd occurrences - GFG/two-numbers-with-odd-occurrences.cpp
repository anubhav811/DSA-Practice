//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int xorr = Arr[0];
        for(long long int i=1;i<N;i++) xorr^=Arr[i];
        
        // find first set bit from right side
        
        long long int ind = 0;
        while(xorr!=0){
            if(xorr&1){
                break;
            }
            ind++;
            xorr=xorr>>1;
        }
        
        long long int xor1=0,xor2=0;
        for(long long int i=0;i<N;i++){
            if(Arr[i]&(1<<ind)){
                xor1^=Arr[i];
            }
            else{
                xor2^=Arr[i];
            }
        }
        
        if(xor1>xor2) return {xor1,xor2};
        return {xor2,xor1};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends