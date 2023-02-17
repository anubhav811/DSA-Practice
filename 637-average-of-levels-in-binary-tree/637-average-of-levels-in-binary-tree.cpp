/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> res;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()){
            double levelSum = 0;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* child = q.front();
                q.pop();
                if(child->left) 
                    q.push(child->left);
                if(child->right)
                    q.push(child->right);   
                levelSum += child->val;
            }
            
            res.push_back((double)levelSum/n);
            
        }
        return res;
    }
};