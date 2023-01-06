//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        int time = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i,j},time});
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            time = q.front().second;
            q.pop();
            for(int delrow = -1; delrow<=1;delrow++) {
              for(int delcol = -1; delcol <= 1; delcol++) {
                    if((delcol==-1 && delrow==1) || (delcol==1 && delrow==-1) || delrow==delcol)
                        continue;
                  int row = x + delrow; 
                  int col = y + delcol; 

                  if(row>=0 && row<m && col>=0 && col<n && vis[row][col]!=2 && grid[row][col]==1){
                      q.push({{row,col},time+1});
                      vis[row][col]=2;
                  }
            }
            }
        }
        for(int i=0;i<m;i++){
                  for(int j=0;j<n;j++){
                      if(vis[i][j] !=2 && grid[i][j]== 1){
                         return -1;
                      }
                  }
              }

        return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends