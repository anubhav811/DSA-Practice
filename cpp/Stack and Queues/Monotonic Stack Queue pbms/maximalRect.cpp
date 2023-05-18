#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int histogramArea(vector<int>& heights) {
        
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea=INT_MIN;

        vector<int> row(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    row[j]++;
                }
                else{
                    row[j] = 0;
                }
            }

            maxArea = max(maxArea,histogramArea(row));
        }
        return maxArea;
    }
};
int main()
{

    return 0;
}