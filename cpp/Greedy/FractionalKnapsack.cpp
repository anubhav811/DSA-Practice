#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    static bool comp(Item i1,Item i2){
        return (double)i1.value/(double)i1.weight > (double)i2.value/(double)i2.weight;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double res = 0 ;
        sort(arr,arr+n,comp);
        
        int totWt = 0;
        for(int i=0;i<n;i++){
            if(totWt + arr[i].weight <=W){
                res+=arr[i].value;
                totWt+=arr[i].weight;
            }
            else{
                int rem = W - totWt;
                double fraction = arr[i].value/(double)arr[i].weight;
                double val = fraction * (double)rem;
                res+=val;
                totWt+=rem;
                break;
            }
        }
        
        return res;
    }
        
};
