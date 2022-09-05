/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        queue<Node*> q;
        
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        q.push(root);        
        
        while(!q.empty()){
         
            int size = q.size();
            vector<int> curr;
            
            for(int i=0;i<size;i++){
                Node* top = q.front();
                q.pop();
            
                for(int j=0;j<top->children.size();j++){
                    if(top->children[j])
                        q.push(top->children[j]);
                }
                curr.push_back(top->val);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};