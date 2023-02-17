class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
        deque<int>q;
        int i=0,j=0;
        vector<int>res;
        int n = arr.size();
        while(j<n){
            while(!q.empty() && q.back()<arr[j]) q.pop_back();
            q.push_back(arr[j]);
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                res.push_back(q.front());
                if(q.front()==arr[i]) q.pop_front();
                i++;
                j++;
            }
        }
        return res;
    }
};