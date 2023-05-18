#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        vector<int> NSL(n),NSR(n);

        stack<int> s;

        // finding nearest smallest to left

        for(int i=0;i<n;i++){
            while(!s.empty() and heights[s.top()]>=heights[i])
                s.pop();
            if(s.empty()) NSL[i]=-1;
            else NSL[i] = s.top();

            s.push(i);
        }

        while(!s.empty()) s.pop();

        // finding nearest smallest to right

        for(int i=n-1;i>=0;i--){
            while(!s.empty() and heights[s.top()]>heights[i])
                s.pop();
            if(s.empty()) NSR[i] = n;
            else NSR[i] = s.top();

            s.push(i);
        }

        int area=INT_MIN;
        for(int i=0;i<n;i++){
            area=max(area,heights[i]*(NSR[i]-NSL[i]-1));
        }

        return area;
    }
};
int main()
{

    return 0;
}