//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    
	    map<char,int> mp1 , mp2;
	    for(auto it:pat) mp1[it]++;
	    
	    int K = pat.size();
	    
	    int i=0,j=0;
	    
	    int count = 0;
	    
	    while(j<txt.size()){
	        mp2[txt[j]]++;
	        
	        if(j-i+1<K){
	            j++;
	        }
	        else if(j-i+1==K){
	            if(mp2==mp1) count++;
	            
	            mp2[txt[i]]--;
	            if(mp2[txt[i]]==0) mp2.erase(txt[i]);
	  
	            i++;
	            j++;
	        }
	    }
	    
	    return count;
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