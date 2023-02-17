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
    
    void recur(TreeNode* node,int currPathMax,int &good){
        if(!node)
            return;
        if(node->val>=currPathMax)
            good++;
        currPathMax = max(currPathMax,node->val);
        recur(node->left,currPathMax,good);
        recur(node->right,currPathMax,good);
    }
    int goodNodes(TreeNode* root) {
        int good = 0;
        recur(root,INT_MIN,good);
        return good;
    }
};