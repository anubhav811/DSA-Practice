//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void swapIfGreater(long long arr1[],long long arr2[] , int i , int j){
            
            if(arr1[i]>arr2[j]){
                swap(arr1[i],arr2[j]);
            }
        }
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            
            // Optimal 2 : Gap Method TC:
            int len = n+m;
    int gap = (len / 2) + (len % 2);
            while(gap>0){
                int left = 0;
                int right = left + gap;
                while(right<len){
                    
                    // arr1 and arr2
                    if(left<n and right>=n){
                        swapIfGreater(arr1,arr2,left,right-n);
                    }
                    
                    // arr1 and arr1
                             else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }

                    
                    left++,right++;
                    
                }
                if(gap==1) break;
        gap = (gap / 2) + (gap % 2);
            }
            
            
            // Optimal 1 : TC : O(min(N,M) + O(nlogn) + O(mlogm))
                        // SC: O(1)
            // int i = n - 1;
            // int j = 0;
        
            // while (i >= 0 && j < m) {
            //     if (arr1[i] > arr2[j]) {
            //         swap(arr1[i], arr2[j]);
            //         i--, j++;
            //     }
            //     else {
            //         break;
            //     }
            // }
        
            // sort(arr1, arr1 + n);
            // sort(arr2, arr2 + m);
          

            // Brute Force  Tc:O(N+M) Sc:O(N+M)
            // long long arr3[n+m];
            // int i = 0 , j = 0;
            // int index = 0;
            // while(i<n and j<m){
            //     if(arr1[i]<=arr2[j]){
            //         arr3[index] = arr1[i];
            //         i++;
            //         index++;
            //     }
            //     else{
            //         arr3[index] = arr2[j];
            //         j++;
            //         index++;
            //     }
            // }
            
            // while(i<n) arr3[index++] = arr1[i++];
            // while(j<n) arr3[index++] = arr2[j++];
            
            // for(int i=0;i<n+m;i++){
            //     if(i<n) arr1[i]=arr3[i];
            //     else arr2[i-n] = arr3[i];
            // }
            
         } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends