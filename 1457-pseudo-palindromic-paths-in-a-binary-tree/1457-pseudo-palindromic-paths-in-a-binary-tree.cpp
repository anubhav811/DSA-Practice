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
private:
    unordered_map<int,int> mp;
    int res;
public:
    void helper(TreeNode* root){
        if(!root)
            return;
        
        mp[root->val]++;
        if(!root->left && !root->right){
            int oddCount = 0;
            for(auto it:mp) {
                if(it.second%2!=0) 
                    oddCount++;
            }
            if(oddCount<=1) res++;
        }
        helper(root->left);
        helper(root->right);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        helper(root);
        return res;
    }
};