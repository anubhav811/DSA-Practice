#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int greedy(int n , vector<int> &nums){
        
        int l = 0;
        int r = 0;

        int res = 0;

        while(r<n-1){
            int farthest = 0;-
            for(int i = l ; i<=r ; i++){
                farthest = max(farthest,i+nums[i]);
            }
            l = r+1;
            r = farthest;
            res++;
        }

        return res;
    }
};
int main()
{

    return 0;
}