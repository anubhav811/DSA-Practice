#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> mp;
        vector<int> res;
        stack<int> s;

        for(int i=nums2.size()-1;i>=0;i--){

            while(!s.empty() and s.top()<=nums2[i]) s.pop();

            if(s.empty()){
                mp[nums2[i]]  = -1;
            }
            else{
                mp[nums2[i]] = s.top();
            }
            
            s.push(nums2[i]);
        }

        for(auto it : nums1){
            res.push_back(mp[it]);
        }

        return res;
    }
};
int main()
{

    return 0;
}