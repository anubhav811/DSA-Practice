//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int> res;
            int i=0,j=0;
            
            while(true){
            
                int temp=i;
                while(i<txt.size() and j<pat.size() and txt[i]==pat[j]){
                    i++;
                    j++;
                }
                
                if(j==pat.size())
                    res.push_back(temp+1);

                j=0;
                i=temp+1;
                
                if(i>=txt.size() or j>=pat.size()) break;
            }
            
            return (res.empty()) ? vector<int>(1,-1) : res;       
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends