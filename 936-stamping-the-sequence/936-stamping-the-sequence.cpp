class Solution {
public:
    bool isReplacable(int pos, string stamp,string &target){
        for(int i=0 ; i<stamp.size();i++){
            if(target[pos+i]!='?' && target[pos+i]!=stamp[i])
                return false;
        }
        return true;
    }
    int replace(int pos, string stamp,string &target){
        int cnt = 0;
        for(int i=0 ; i<stamp.size();i++){
            if(target[pos+i]!='?'){
                cnt++;
                target[pos+i]='?';
            }
        }
        return cnt;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int starCount = 0 ;
        int m = stamp.size();
        int n = target.size();
        vector<bool> vis(n+1,0) ;
        vector<int> res;
        
        int windowSize = n-m;
        
        while(starCount!=n){
            bool replaced = false;
            for(int i=0 ; i<=windowSize;i++){
                if(vis[i]==0 && isReplacable(i,stamp,target)){
                    vis[i]=1;
                    starCount+=replace(i,stamp,target);
                    replaced = true;
                    res.push_back(i);
                }
            }
            if(!replaced) return {} ;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    
};