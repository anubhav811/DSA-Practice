//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
      
        int i = 0 , j=0;
        long currSum = 0 , maxSum = 0;
        
        while(j<N){
            currSum+=Arr[j];
            
            if(j-i+1<K){
                j++;
            }
            
            else if(j-i+1==K){
                maxSum = max(maxSum,currSum);
                currSum -= Arr[i];  // take off value from left side
                j++;
                i++;
            }
        }
        
        return maxSum;
        
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