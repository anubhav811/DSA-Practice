#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
         
        // Brute Force -> O(NLogn) + O(N^2)     : Passed
        
        // int i = 0;
        // while(i<n){
        //     if(!res.empty() and res[res.size()-1][1]>=intervals[i][0]){
        //         i++;
        //         continue;
        //     }
        //     int lastStart = intervals[i][0];
        //     int lastEnd = intervals[i][1];
        //     for(int j=i+1;j<n;j++){
        //         if(intervals[j][0]<=lastEnd){
        //             lastStart = min(lastStart,intervals[j][0]);
        //             lastEnd = max(lastEnd,intervals[j][1]);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     res.push_back({lastStart,lastEnd});
        //     i++;
        // }
        // return res;
        
        
        // Optmized => O(NLogN) + O(N)  
        vector<int> pair = intervals[0];
        
        for(int i=1;i<n;i++){
            
            if(intervals[i][0]<=pair[1]){
                pair[0]=min(pair[0],intervals[i][0]);
                pair[1]=max(pair[1],intervals[i][1]);
            }
            else{
                res.push_back(pair);
                pair[0]=intervals[i][0];
                pair[1]=intervals[i][1];
            }
        }
        res.push_back(pair);
        return res;
    }
};
int main()
{

    return 0;
}
