//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   vector<int> tab2(int n , vector<int>& arr){
            
            vector<int> dp (n,1);
            vector<int> hash (n);
            
            
            sort(arr.begin(), arr.end());

            
            for(int i=0;i<n;i++){
                hash[i] = i;
                for(int prev=0;prev<=i-1;prev++){
                    if(arr[i]%arr[prev]==0){
                        if(1+dp[prev]>dp[i]){
                            dp[i] = 1+dp[prev];
                            hash[i] = prev;
                        }
                    }
                }
            }
            
            int maxVal = -1;
            int maxi = -1;
            
            for(int i=0;i<n;i++){
                if(dp[i]>maxVal){
                    maxVal = dp[i];
                    maxi = i;
                }
            }
            
            vector<int> res;
            res.push_back(arr[maxi]);            
            while(maxi!=hash[maxi]){
                maxi = hash[maxi];
                res.push_back(arr[maxi]);
            }
            
            reverse(res.begin(),res.end());
            return res;
    }
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        return tab2(n,arr);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends