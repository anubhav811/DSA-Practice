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
        q.push(NULL);
        
        vector<int> curr_vec;
        while(!q.empty()){
            Node* top = q.front();
            q.pop();
            
            if(!top){
                ans.push_back(curr_vec);
                curr_vec.resize(0);
                 if (q.size() > 0) {
                    q.push(NULL);
                }
                
            }
            else{
                curr_vec.push_back(top->val);
                if(top->children.size()){
                    for(auto it : top->children){
                        if(it)
                            q.push(it);
                    }
                }
            }
        }
        return ans;
    }
};