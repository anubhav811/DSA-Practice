/*
In this LC version we have to find the best overall profit , only one buy-sell pair is allowed 
Check GFG version for different variant.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    // TC : O(N) and SC : O(1)
    int maxProfit(vector<int>& A) {
        
        int mini = A[0];
        int maxi = 0;
        for(int i=1;i<A.size();i++){
            mini = min(mini,A[i]);
            maxi = max(maxi , A[i]-mini);
        }

        return maxi;
    }
    
};

int main()
{

    return 0;
}