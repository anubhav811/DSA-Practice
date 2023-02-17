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
    bool isSameTree(TreeNode* p,TreeNode* q){
        
        if(p==NULL || q==NULL)
            return p==q;
        
        bool curr_pos = p->val == q->val;
        bool left_side = isSameTree(p->left,q->right);
        bool right_side = isSameTree(p->right,q->left);
        
        return curr_pos && left_side && right_side;
    }
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left,root->right);
    }
};