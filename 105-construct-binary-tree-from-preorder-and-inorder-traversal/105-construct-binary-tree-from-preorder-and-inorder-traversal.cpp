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
    map<int,int> inMap;
    TreeNode* solveRecur(vector<int> &preorder, int pre1,int pre2,vector<int> &inorder , int in1,int in2){
        if(pre1>pre2 || in1>in2)
            return NULL;
        TreeNode* root = new TreeNode(preorder[pre1]);
        
        int inRoot = inMap[root->val];
        
        int numsOnLeftSide = inRoot - in1;
        
        root->left = solveRecur(preorder,pre1+1,pre1+numsOnLeftSide,inorder,in1,inRoot-1);
        
        root->right = solveRecur(preorder,pre1+numsOnLeftSide+1,pre2,inorder,inRoot+1,in2);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        
        TreeNode* root = solveRecur(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        
        return root;
    }
};