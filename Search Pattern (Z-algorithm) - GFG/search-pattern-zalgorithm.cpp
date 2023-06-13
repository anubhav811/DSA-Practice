//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int p = pat.size() ;
            int t = txt.size() ; 
            string ns = pat+"#"+txt ;
            int n = ns.length() ; 
            vector<int> z (n);
            
            // Creating Z Table O(M*N)
            // int i = 0 ; 
            // while(i<n){
            //   if(i<=p) z.push_back(0) ; 
            //   else{
            //       int t_ptr = 0 , p_ptr = 0 ; 
            //       if(ns[p_ptr] ==ns[i]){
            //           t_ptr = i ; 
            //           while(ns[t_ptr] == ns[p_ptr] and t_ptr<n){
            //               t_ptr++ ; 
            //               p_ptr++ ; 
            //           }
            //       }
            //       z.push_back(p_ptr) ; 
            //   }
            //   i++;
            // }
            
            // Creating Z Table O(M+N)
            int l=0,r=0;
            for(int i=1;i<n;i++){
                if(i>r){
                    l=r=i;
                    while(r<n and ns[r]==ns[r-l]){
                        r++;
                    }
                    z[i] = r-l;
                    r--;
                }
                else{
                    int idx = i-l;
                    if(i+z[idx]<=r){
                        z[i] = z[idx];
                    }
                    else{
                        l=i;
                        while(r<n and ns[r]==ns[r-l]){
                            r++;
                        }
                        z[i] = r-l;
                        r--;                
                    }
                }
            }

            // Result
            vector<int> ans ; 
            for(int i = 0 ;i<n;i++){
                if(z[i] == p) ans.push_back(i-p) ; 
            }
            return ans ; 
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
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends