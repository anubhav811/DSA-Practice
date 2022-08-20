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
    
void hasPathSum(TreeNode *root, int sum,vector<int> &curr , vector<vector<int>> &main) {
    
        if (root == NULL)
            return;
    
        curr.push_back(root->val);

        if (root->left ==  NULL && root->right == NULL) {
            if(root->val == sum){
                main.push_back(curr);
           }
        }
    hasPathSum(root->left, sum-root->val,curr,main);
        
    hasPathSum(root->right,sum-root->val,curr,main);
    curr.pop_back();
  
    
}  
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> main;
        vector<int> curr;
        
        hasPathSum(root,targetSum,curr,main);
            
        return main;
        
    }
};