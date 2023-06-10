//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        
        int i=0,j=0;
        
        while(true){
        
            int temp=i;
            while(i<text.size() and j<pat.size() and text[i]==pat[j]){
                i++;
                j++;
            }
            if(j==pat.size()) return temp;
            else{
                j=0;
                i=temp+1;
            }

            if(i>=text.size() or j>=pat.size()) break;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends