//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
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
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        vector<int> row (m,0) ;
        for(int j=0;j<m;j++){
            row[j] = M[0][j];
        }
        int maxArea = histogramArea(row);
        for(int i=1;i<n;i++){
             for(int j=0;j<m;j++){
                    if(M[i][j]==0)
                        row[j] = 0;
                    else 
                        row[j]+=M[i][j];
             }
             maxArea=max(maxArea,histogramArea(row));
        }

        return maxArea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends