//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    void quickSort(int arr[], int low, int high)
    {
        if(low<high){
            int partition_idx = partition(arr,low,high);
            quickSort(arr,low,partition_idx-1);
            quickSort(arr,partition_idx+1,high);
        }
    }
    int partition (int arr[], int low, int high)
    {
        int i=low;
        int j=high;
        
        while(i<j){
            while(i<=high and arr[i]<=arr[low]) 
                i++;
            while(j>=low and arr[j]>arr[low]) 
                j--;
            
            if(i<j)
                swap(arr[i],arr[j]);
        }
        
        swap(arr[low],arr[j]);
        return j;

    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends