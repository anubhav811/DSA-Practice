#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int histogramArea(vector<int>& heights) {
        
        // Further optmized ()                         // TC : O( 2N )
                                                       // SC : O( N )
        stack < int > st;
        int maxA = 0;
        int n = heights.size();      
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
            
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<int> row (matrix[0].size(),0) ;
        for(int j=0;j<matrix[0].size();j++){
            row[j] = (matrix[0][j]-'0');
        }
        int maxArea = histogramArea(row);
        for(int i=1;i<matrix.size();i++){
             for(int j=0;j<matrix[0].size();j++){
                    if(matrix[i][j]=='0')
                        row[j] = 0;
                    else 
                        row[j]+=(matrix[i][j]-'0');
             }
             maxArea=max(maxArea,histogramArea(row));
        }

        return maxArea;
    }
};