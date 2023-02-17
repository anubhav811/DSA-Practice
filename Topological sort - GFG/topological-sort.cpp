//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

 public:

//  void solveDFS(int node,vector<int> adj[],stack<int> &st,  vector<int> &visited){

//      visited[node]=1;

//      for(auto nbr:adj[node]){

//          if(!visited[nbr]){

//              solveDFS(nbr,adj,st,visited);

//          }

//      }

//   st.push(node);

//  }

//  //Function to return list containing vertices in Topological order. 

//  vector<int> topoSort(int V, vector<int> adj[]) 

//  {

//      // code here

//      stack<int> st;

//       vector<int> visited(V,0);

//       for(int i=0;i<V;i++){

//           if(!visited[i])

//           solveDFS(i,adj,st,visited);

//       }

     

//      //cout<<st.size();

//      vector<int> ans;

//      while(!st.empty()){

//          ans.push_back(st.top());

//          st.pop();

//      }

//      return ans;

//  }

    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> res;
        vector<int> indegree(V,0);
        queue<int> q;
        
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
                
            }
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for(auto it:adj[node]){
                indegree[it]--;
                
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        
        return res;
    
}

};



//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends