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
    int solveRecur(TreeNode* root , int &maxi){
    if(!root){
        return  0 ;
    }
    int max_l = solveRecur(root->left,maxi);
    int max_r = solveRecur(root->right,maxi);
    maxi = max(maxi,max_l+max_r);
    // 1 is extra for the root nood;
    return max(max_l,max_r)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        solveRecur(root,maxi);
        return maxi;
    }
};