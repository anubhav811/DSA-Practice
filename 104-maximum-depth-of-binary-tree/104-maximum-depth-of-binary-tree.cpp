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
    int solveRecur(TreeNode* root){
        if(root==NULL){
            return  0 ;
        }
        int max_l = solveRecur(root->left);
        int max_r = solveRecur(root->right);
        
        // 1 is extra for the root nood;
        return 1 + max(max_l,max_r);
    }
    
    int maxDepth(TreeNode* root) {
        
        return solveRecur(root);
    }
};