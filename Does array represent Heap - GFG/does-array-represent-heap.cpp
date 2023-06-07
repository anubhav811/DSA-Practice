//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool heapify(int arr[],int sz,int i){
    
        int parent = i;
        int left = 2*i+1;
        int right = 2*i+2;
    
        if(left<sz and arr[left]>arr[parent] and arr[left]>arr[right]){
            return false;
            swap(arr[left],arr[i]);
            parent=left;
        }
        else if(right<sz and arr[right]>arr[i] and arr[right]>arr[left]){
            return false;
            swap(arr[right],arr[i]);
            parent=right;
        }
        
        if(parent!=i)
            heapify(arr,sz,parent);
        
        return true;
    }
    bool isMaxHeap(int a[], int n)
    {
        // Your code goes here
        int sz = n;
        for(int i=sz/2;i>=0;i--){
            if(!heapify(a,sz,i)) return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends