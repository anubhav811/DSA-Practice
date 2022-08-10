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
    TreeNode* getNode(vector<int> &nums,int l,int r){
        
        if(l>r)
            return NULL;
        int middle = l + (r - l)/2;
        TreeNode* root = new TreeNode();
        root->val = nums[middle];
        root->left = getNode(nums,l,middle-1);
        root->right = getNode(nums,middle+1,r);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getNode(nums,0,nums.size()-1);
    }
};