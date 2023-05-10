#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> minPartition(int N){
        
        vector<int> den = {2000,500,200,100,50,20,10,5,2,1};
        
        int val=0 ,i=0;
        vector<int> coins ;

        while(i<den.size()){
            if(den[i]+val <= N){
                val+=den[i];
                coins.push_back(den[i]);
            }
            else i++;
        }
        return coins;
    }
};