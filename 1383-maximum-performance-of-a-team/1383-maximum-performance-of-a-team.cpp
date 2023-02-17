class Solution {
public:        
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>> engineers(n);
        
        for(int i=0 ; i<n; i++){
            engineers[i] = {efficiency[i],speed[i]};
        }
        
        sort(engineers.rbegin(),engineers.rend());
        
        priority_queue <int, vector<int>, greater<int>> pq;
            
        long sumSpeed = 0;
        long perf = 0;
        for(auto& [e,s] : engineers){
            pq.push(s);
            sumSpeed+=s;
            if(pq.size()>k){
                sumSpeed-=pq.top();
                pq.pop();
            }
            perf = max(perf,sumSpeed*e);
        }
        
        return perf%(int)(1e9+7);
        
        
    }
};