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
        // Recursive solution

    void solveRecur(TreeNode* root , vector<int> &main){
        if(root==NULL)
            return;
        main.push_back(root->val);
        solveRecur(root->left,main);
        solveRecur(root->right,main);
    }

    vector<int> preorderTraversal(TreeNode* root) {
       
        // For recursive part

        vector<int> main;
        solveRecur(root,main);
        return main;
        
        // Iterative Solution
    }
};