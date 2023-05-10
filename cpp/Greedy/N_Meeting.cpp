#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> timings;
        
        for(int i=0 ; i<n ; i++){
            timings.push_back({end[i],start[i]});
        }
        
        sort(timings.begin(),timings.end());
        int count = 1;
        int lastMeetingEndTime = timings[0].first;
        
        for(int i=1;i<n;i++){
            if(timings[i].second>lastMeetingEndTime) {
                count++;
                lastMeetingEndTime=timings[i].first;
            }
        }
        
        return count;
    }
};

int main()
{   return 0;
}