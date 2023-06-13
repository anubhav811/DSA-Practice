//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    int base = 1e6;

    vector<int> rabinKarp(string pat,string txt){
        int m = pat.size();
        int n = txt.size();
        vector<int> res;
        
        int power = 1;
        // finding m-1th power
        for (int i = 0; i < m; i++)
        {
            power = (power *31) % base;
        }

        // finding patternCode
        int patCode = 0;
        for (int i = 0; i < m; i++)
        {
            patCode = (patCode *31 + pat[i]) % base;
        }
        int hashcode = 0;
        for (int i = 0; i < txt.size(); i++)
        {
            hashcode = (hashcode *31 + txt[i]) % base;
            if (i < m - 1) continue;
            if (i >= m)
            {
                hashcode = (hashcode - txt[i - m] *power) % base;
            }
            if (hashcode < 0) hashcode += base;
            if (hashcode == patCode)
            {
                if (txt.substr(i - m + 1, m) == pat) res.push_back(i - m + 2);
            }
        }
        
        return (res.size()) ? res : vector<int>(1,-1);
    }

    vector <int> search(string pat, string txt){
        return rabinKarp(pat,txt);
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