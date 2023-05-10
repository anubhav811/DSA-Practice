#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    static bool comp(Job &j1 , Job &j2){
        return j1.profit>j2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n){
        
        sort(arr,arr+n,comp);

        int maxiDead =  INT_MIN;
        for(int i = 0 ; i < n ; i++){
            maxiDead= max(maxiDead,arr[i].dead);
        }
        
        vector<int> jobsOnDays (maxiDead+1,-1);

        
        int maxProfit = 0 ;
        int jobs = 0;
        
        for(int i=0;i<n;i++){
            
            for(int j = arr[i].dead ; j>=1 ; j--){
                if(jobsOnDays[j]==-1){
                    // free slot available
                    jobsOnDays[j] = i;
                    jobs++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }
            

        return  {jobs,maxProfit};
    }
};
int main()
{return 0;}
