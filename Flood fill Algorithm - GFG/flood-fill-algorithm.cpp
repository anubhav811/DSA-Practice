//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    void dfs(vector<vector<int>>& image ,vector<vector<int>> vis, int row , int col ,int pattern, int newColor){
                int n = image.size();
        int m = image[0].size();

        vis[row][col] = 1 ;
        image[row][col] = newColor;
        for(int delrow = -1 ; delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                if((delcol==-1 && delrow==1) || (delcol==1 && delrow==-1) || delrow==delcol){
                        continue;
                    }
                int x = row+delrow;
                int y = col+delcol;
                    
                if(x<n && x>=0 && y<m && y>=0 && image[x][y]==pattern && !vis[x][y]){
                    vis[x][y]=1;
                    image[x][y]=newColor;
                    dfs(image,vis,x,y,pattern,newColor);
                }
            }
        }
    }
    void bfs(vector<vector<int>>& image ,vector<vector<int>> vis, int row , int col ,int pattern, int newColor){
        vis[row][col] = 1 ;
        image[row][col] = newColor;
        
        queue<pair<int,int>> q;
        q.push({row,col});
        
        int n = image.size();
        int m = image[0].size();

        while(!q.empty()){
            int r = q.front().first;
            int l = q.front().second;
            
            q.pop();
            
            for(int delrow = -1 ; delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    if((delcol==-1 && delrow==1) || (delcol==1 && delrow==-1) || delrow==delcol){
                        continue;
                    }
                    int x = r+delrow;
                    int y = l+delcol;
                    
                    if(x<n && x>=0 && y<m && y>=0 && image[x][y]==pattern && !vis[x][y]){
                        vis[x][y]=1;
                        image[x][y]=newColor;
                        q.push({x,y});
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int pattern = image[sr][sc];
        
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        // bfs(image,vis,sr,sc,pattern,newColor);
        dfs(image,vis,sr,sc,pattern,newColor);
    
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends