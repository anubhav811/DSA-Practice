//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 private:
 void bfs(int i,int j ,vector<vector<int>> &vis ,vector<vector<char>>& grid){
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});

        int m = grid.size();
        int n = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // traverse the 8 neighbours and mark them
            for(int delRow = -1; delRow<=1;delRow++){
                for(int delCol = -1; delCol<=1;delCol++){
                    int x = row + delRow;
                    int y = col + delCol;

                /* // conditions 
                    1. x should be within row limits;
                    2. y should be within col limits.
                    3. x,y should be a land.
                    4. x,y should be non visited.
                */

                  if(x >= 0 && x < m && y >= 0 && y < n 
                  && grid[x][y] == '1' && !vis[x][y]) {
                        vis[x][y]=1;
                        q.push({x,y});
                    }
            }
        }
    }
    }  
    public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1') {
                    bfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends