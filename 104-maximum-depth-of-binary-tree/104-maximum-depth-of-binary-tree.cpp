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
    int solveRecur(TreeNode* root){
        if(root==NULL){
            return  0 ;
        }
        int max_l = solveRecur(root->left);
        int max_r = solveRecur(root->right);
        
        // 1 is extra for the root nood;
        return 1 + max(max_l,max_r);
    }
    
    int maxDepth(TreeNode* root) {
        
        // Recursive method
        // return solveRecur(root);
        
        
        // Queue method
        if(root == NULL)
            return 0;

        int res = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            ++ res;
            for(int i = 0, n = q.size(); i < n; ++ i)
            {
                TreeNode *p = q.front();
                q.pop();

                if(p -> left != NULL)
                    q.push(p -> left);
                if(p -> right != NULL)
                    q.push(p -> right);
            }
        }

        return res;

    }
};