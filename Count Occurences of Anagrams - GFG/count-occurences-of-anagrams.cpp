//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {

	    int i=0,j=0,ans = 0,count=0;
	    int k = pat.size();
	    
	    map<char,int> m;
	    for(auto s : pat){
	        m[s]++;
	    }
	    
	    count = m.size();
	    
	    int occ = 0;
	    
	    while(j<txt.size()){
	        
	        if(m.find(txt[j])!=m.end()){
	            m[txt[j]]--;
	            if(m[txt[j]]==0)
	                count--;
	        }
	        if(j-i+1<k){
	            j++;
	        }
	        else if(j-i+1==k){
	           if(count==0)
	               occ++;
	           if(m.find(txt[i]) != m.end()){
	                m[txt[i]]++;
	                if(m[txt[i]]==1){
	                    count++;
	                }
	           }
	           i++;
	           j++;
	        }
}
	    return occ;
	    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends