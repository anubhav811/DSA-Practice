#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> res;
        deque<int> dq;
        
        for(int i=0;i<n;i++){
            if(!dq.empty() and dq.front() == i-k) 
                dq.pop_front();
            while(!dq.empty() and  arr[dq.back()]<arr[i]) 
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i>=k-1){
                res.push_back(arr[dq.front()]);
            }
        }
        return res;

    }
};
int main()
{

    return 0;
}