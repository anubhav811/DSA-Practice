//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        // Optimal Approach TC: O(N)  Sc:O(1)
        unordered_set<int> s;
        for(int i=0;i<N;i++){
            s.insert(arr[i]);
        }
        
        int maxi = 0;
        
        for(int i=0 ;i<N;i++){
            if(s.find(arr[i]-1)==s.end()){
                int ele = arr[i];
                int count = 1;
                while(s.find(ele+1)!=s.end()){
                    ele++;
                    count++;
                }
                maxi = max(maxi,count);
            }
        }
        
        return maxi;
        
        
        // Better Approach : O(NLogN)
        // sort(arr,arr+N);
        // int maxi = 1;
        // int count = 1;
        // int lastTaken = arr[0];
        
        // for(int i=1;i<N;i++){
        //     if(arr[i]==lastTaken) continue;
        //     if(lastTaken+1==arr[i]){
        //         lastTaken = arr[i];
        //         count++;
        //     }
        //     else if(lastTaken!=arr[i]){
        //         count=1;
        //         lastTaken = arr[i];
        //     }
        //     maxi = max(count,maxi);
        // }
        
        // return maxi;
    }
    
    /*
    34 2 7 23 31 38 13 11 37 19 45 6
    
     2 6 7 11 13 19 23 31 34 37 38 45
     
     2 0 1 1 4
     0 1 1 2 4
    */
    
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends