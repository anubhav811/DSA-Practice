#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        
        int pageFault = 0;
        unordered_set<int> s;
        unordered_map<int,int> mp;
        
        for(int i = 0 ; i < N ; i++){
            if(s.size()<C){
                if(s.find(pages[i])==s.end()){
                    s.insert(pages[i]);
                    pageFault++;
                }
                mp[pages[i]] = i;
            }
            else{
                if(s.find(pages[i])==s.end()){
                    pageFault++;
                    int lru = INT_MAX;
                    int val = 0;
                    for(auto it=s.begin(); it!=s.end();it++){
                        if(mp[*it]<lru){
                            lru = mp[*it];
                            val = *it;
                        }
                    }
                    s.erase(val);
                    s.insert(pages[i]);
                }
                mp[pages[i]]=i;
            }
        }
        return pageFault;
        
    }
};

int main()
{

    return 0;
}
