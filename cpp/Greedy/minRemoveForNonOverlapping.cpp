#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        int n = intervals.size();

        int l=0,r=1;
        int count = 0;
        
        while(r<n){
            // case 1 (Non overlapping)
            if(intervals[l][1]<=intervals[r][0]){
                l = r;
                r++;
                continue;
            }
            // case 2 (Overlapping : Remove Right Interval)
            else if(intervals[l][1]<=intervals[r][1]){
                r++;
                count++;
            }
            
            // case 3 (Overlapping : Remove left Interval)
            else if(intervals[l][1]>intervals[r][1]){
                count++;
                l=r;
                r++;
            }
        }
        
        return count;
    }
};
int main()
{return 0;}