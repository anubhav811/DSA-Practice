//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    int prime = 101;
    
    long calculateHash(string s , int len){
        long hash = 0;
        for(int i=0;i<len;i++){
            hash += s[i]*pow(prime,i);
        }
        return hash;
    }
    
    
    long recalculateHash(string s, int oldIdx , int newIdx , long oldHash, int patLen){
        long newHash = oldHash - s[oldIdx];
        newHash = newHash/prime;
        newHash += s[newIdx]*pow(prime,patLen-1);
        return newHash;
    }
    
    vector<int> rabinKarp(string pat,string txt){
        int m = pat.size();
        int n = txt.size();
        vector<int> res;
        
        // calculating pattern hash
        long patHash = calculateHash(pat,m);

        // calculating text hash (create upto size of pattern for now (m))
        long txtHash = calculateHash(txt,m);
        
        
        for(int i=1;i<=n-m+1;i++){
            if(patHash==txtHash){
                if(txt.substr(i-1,m)==pat){
                    res.push_back(i);
                }
            }
            
            // further string is left to be checked 
            if(i<n-m+1){
                txtHash = recalculateHash(txt, i - 1, i + m - 1, txtHash, m);
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