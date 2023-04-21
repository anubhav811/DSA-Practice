#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> coins = {2000,500,200,100,50,20,10,5,2,1};
        
        vector<int> ans ;
        int i = 0;
        int sum = 0;
        while(i<coins.size()){
            
            if(sum==N) break;
            
            if(sum+coins[i]<=N){
                sum+=coins[i];
                ans.push_back(coins[i]);
            }else{
                i++;
            }
        }
        
        return ans;

    }
};