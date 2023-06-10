//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        
        if(n==1) return "1";

        string s = lookandsay(n-1);

        string res = "" ;

        for(int i=0;i<s.size();i++){
            int count = 1;
            char c = s[i];
            for(int j=i+1;j<s.size();j++){
                if(c!=s[j]) break;
                else{
                    i=j;
                    count++;
                }
            }
            res += to_string(count) + c;        
        }
        return res;
        
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends