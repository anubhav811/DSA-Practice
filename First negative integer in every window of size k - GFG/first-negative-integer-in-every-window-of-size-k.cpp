//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
        
        // Sliding Window
        
        int i=0;
        int j=0;
        queue<long long> q;
        vector<long long> res;
        
        while(j<N){
            if(A[j]<0)                    // Do the operation
                q.push(A[j]);
            
            if(j-i+1<K){                  // Window smaller
                j++;
            }
            else if(j-i+1==K){            //  Window size achieved
                if(q.empty())             // q empty means no negative in this window
                    res.push_back(0);
                    
                else{
                    res.push_back(q.front());         // not empty hence the first guy in q is the first neg
                                                      // FIFO
                    if(q.front()==A[i]) q.pop();      // if the first guy is also the leftmost (index i) guy
                                                      // he needs to be taken out as he wont be needed in
                                                      // next window
                }
                i++;              // Move the window
                j++;              // Move the window
            }
        }
        
        return res;


        // Brute force
        // vector<long long> res;
        // for(int i=0;i<=N-K;i++){
        //     bool flag = false;
        //     for(int j=i;j<i+K;j++){
        //         if(A[j]<0){
        //             flag = true;
        //             res.push_back(A[j]);
        //             break;
        //         }
        //     }
        //     if(!flag) res.push_back(0);
        // }
        
        // return res;
        
 }