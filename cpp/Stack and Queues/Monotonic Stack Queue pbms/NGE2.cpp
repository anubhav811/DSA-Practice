#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> res(nums.size());

        int n = nums.size();

        for(int i=2*n-1;i>=0;i--){
            while(!s.empty() and s.top()<=nums[i%n]) s.pop();

            res[i%n] = (s.empty()) ? -1 : s.top();

            s.push(nums[i%n]); 
         }

         return res;
    }
};
int main()
{

    return 0;
}