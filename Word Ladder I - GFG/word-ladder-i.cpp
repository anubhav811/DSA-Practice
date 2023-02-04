//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        
        set<string> s(wordList.begin(),wordList.end());
        
        queue<pair<string,int>> q;
        
        q.push({startWord,1});
        
        int len = startWord.size();

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr.first==targetWord)
                return curr.second;
            auto bkp = curr;
            for(int i=0;i<len;i++){
                for (int j = 97; j <= 122; j++) {
                    curr.first[i]=(char)j;
                    if(s.find(curr.first)!=s.end()){
                        q.push({curr.first,curr.second+1});
                        s.erase(curr.first);
                    }
                }
                curr = bkp;
            }
        }
        
        return 0;       
        
    }
    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends