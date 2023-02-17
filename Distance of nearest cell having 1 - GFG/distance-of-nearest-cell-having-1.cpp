//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>> q;
	    
	    vector<vector<int>> distance(n,vector<int>(m,0));
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                vis[i][j]=1;
	            }
	        }
	    }
	
	   while(!q.empty()){
            auto node = q.front();
            
            int x = node.first.first;
            int y = node.first.second;
            int level = node.second;
            
            distance[x][y]=level;
            q.pop();
            
            int delrow[] = {-1,0,+1,0};
            int delcol[] = {0,+1,0,-1};
            
            for(int i = 0 ; i<4;i++){
                int row = x+delrow[i];
                int col = y+delcol[i];
                if(row<n && row>=0 && col<m && col>=0 && !vis[row][col]){
                        vis[row][col]=1;
                        q.push({{row,col},level+1});
                    }
                }
        }
	    return distance;
	    
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends