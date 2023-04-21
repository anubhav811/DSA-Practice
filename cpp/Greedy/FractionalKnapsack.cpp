#include<bits/stdc++.h>
using namespace std;
class Solution
{
    static bool comp(Item a, Item b){
        return ((double)a.value/(double)a.weight > (double)b.value/(double)b.weight);
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        sort(arr,arr+n,comp);
        
        double res = 0;
        double wt = 0;
        
        int i = 0;
        
        while(i<n){
            
            if(wt==W)
                return res;

            if(wt+arr[i].weight <= W){
                res+=arr[i].value;
                wt+=arr[i].weight;
            }
            else{
                int extra = W-wt;
                res+=((double)arr[i].value/(double)arr[i].weight)*(double)(W-wt);
                break;
            }
            i++;
        }
        
        return res;
    }
        
};
