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
    TreeNode* solveRecur(vector<int> &postorder, int post1,int post2,vector<int> &inorder , int in1,int in2){
        if(post1>post2 || in1>in2)
            return NULL;
        TreeNode* root = new TreeNode(postorder[post2]);
        
        int inRoot = inMap[root->val];
        
        int numsOnLeftSide = inRoot - in1;
        
        root->left = solveRecur(postorder,post1,post1+numsOnLeftSide-1,inorder,in1,inRoot-1);
        
        root->right = solveRecur(postorder,post1+numsOnLeftSide,post2-1,inorder,inRoot+1,in2);
        
        return root;
    
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        
        TreeNode* root = solveRecur(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
        
        return root;
    }
};