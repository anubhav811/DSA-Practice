//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // optimal
        unordered_map<int,int> mp;
        int i=0;
        int maxi = 0;
        int sum = 0;
        while(i<n){
            sum+=A[i];
            if(sum==0){
                maxi = i+1;
            }
            else{
                if(mp.find(sum)!=mp.end()){
                    // means two sub arrays have the same prefix sum
                    // i.e   index a->b =sum and index a->c = sum
                    //       this means b->c will have sum=0;
                    maxi = max(maxi,i-mp[sum]);
                }
                if(mp.find(sum)==mp.end()){
                    mp[sum] = i;
                }
            }
            i++;
        }
        return maxi;
        
        // brute force
        // int maxi = 0;
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum+=A[j];
        //         if(sum==0){
        //             maxi = max(maxi,j-i+1);
        //         }
        //     }
        // }
        
        // return maxi;
    }
    
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends