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
        solveRecur(root->left,main);
        main.push_back(root->val);
        solveRecur(root->right,main);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        // For recursive part

        // vector<int> main;
        // solveRecur(root,main);
        // return main;
        
        // Iterative Solution
        
        vector<int> inorder;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            if(root!=NULL){
                st.push(root);
                root=root->left;
            }
            else{
                root = st.top();
                st.pop();
                inorder.push_back(root->val);
                root=root->right;
            }
        }
        return inorder;
        
    }
};