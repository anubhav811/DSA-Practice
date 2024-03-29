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
    int solveRecur(TreeNode* root, int &maxi){
        if(root==NULL) return  0 ;
        
        int max_l = max(0,solveRecur(root->left,maxi));
        int max_r = max(0,solveRecur(root->right,maxi));
      
        // why taking max with return value and zero?
        // -> because the function might return a negative value and there is not point of adding it to the maxi variable because a negative value would never give a "max" sum
        
        maxi = max(maxi,root->val+max_l+max_r);
        return max(max_l,max_r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        solveRecur(root,maxi);
        return maxi;
    }
};