//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    long long mergeSort(long long arr[],int low,int high){
        long long count =0;
        if(low>=high)return count;
        int mid = (low+high)/2;
        count+=mergeSort(arr,low,mid);
        count+=mergeSort(arr,mid+1,high);
        count+=merge(arr,low,mid,high);
        return count;
    }
    
    long long merge(long long a[],int low,int mid,int high){
        long long count =0;
        int i=low,j=mid+1,k=0;
        long tmp[high+1];
        while(i<=mid && j<=high){
            if(a[i]<=a[j]){
                tmp[k] = a[i];
                i++;
                k++;
            }
            else{
                count+= mid-i+1;
                tmp[k] = a[j];
                j++;
                k++;
            }
        }
        while(i<=mid){
            tmp[k] = a[i];
            i++;
            k++;
        }
        while(j<=high){
            tmp[k] = a[j];
            j++;
            k++;
        }
        for(int l=low;l<=high;l++){
            a[l] = tmp[l-low];
        }
        return count;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        // Optimal Approach : Merge Sort
       return mergeSort(arr,0,(int)(N-1));

        // Brute Force  : O(N^2) Sc:O(1)
        // int cnt = 0;
        // for(int i=0;i<N;i++){
        //     int ele = arr[i];
        //     for(int j=i+1;j<N;j++){
        //         if(arr[j]<ele){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends