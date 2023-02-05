//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        
        queue<pair<int,int>> pq;
        // steps,startnode
        pq.push({0,start});
        
        vector<int> dist(100000,INT_MAX);
        dist[start] = 0 ;
        
        while(!pq.empty()){
            auto it = pq.front();
            int node = it.second;
            int steps = it.first;
            pq.pop();
            
         
            for(auto it:arr){
                int prod = (it*node)%100000;
                if(steps+1<dist[prod]){
                    dist[prod] = steps+1;
                    if(prod==end)
                        return dist[prod];
                    pq.push({steps+1,prod});
                }
              
            }
            
        }
        
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends