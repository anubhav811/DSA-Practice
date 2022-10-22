//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int l=0;
        int r=0;
        
        
        long sum = 0;
        long currSum = 0 ;
        while(r<N){
            currSum+=Arr[r];
            if(r-l+1<K){
                r++;
            }
            else if(r-l+1==K){
                sum = max(currSum,sum);
                currSum-=Arr[l];
                l++;
                r++;
            }
        }
        return sum;
        
        // TLE - BRUTE FORCE
        
        // for(int i=0;i<N-K+1;i++){
        //     long cursum = 0;
        //     for(int j=i;j<i+K;j++){
        //         cursum+=Arr[j];
        //     }
        //     sum = max(cursum,sum);
        // }
        // return sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends