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
    int maxDepth(TreeNode* root){
        
        if(root==NULL){
            return  0 ;
        }
        int max_l = maxDepth(root->left);
        int max_r = maxDepth(root->right);
        
        // 1 is extra for the root nood;
        return 1 + max(max_l,max_r);

    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
       
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        if(abs(lh-rh)>1) return false;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        if(!left || !right){
            return false;
        }
        return true;
    }
};