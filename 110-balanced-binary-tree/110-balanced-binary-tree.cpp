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
   
    // Approach 2 : Optimised maxDepth function 
// TC : O(N)  . 
    
    int check(TreeNode* root){
          if(root==NULL){
            return 0;
        }
        
// If either of left subtree or right subtree is unbalanced we wil return -1
        
        int lh = check(root->left);
        if(lh == -1 )
            return -1;
        
        int rh = check(root->right);
        if(rh == -1 )
            return -1;
        
        // checking unbalance for the current node
        if(abs(lh-rh)>1)
            return -1;
        
        // finally returning the height
        return max(lh,rh) + 1 ;
    }
    
    bool isBalanced(TreeNode* root){
        return check(root) != -1;
    }
    
    
// Approach 1 : Naive . using maxDepth function to find lh and rh
// TC : O(N^2)  . The maxDepth functions are increasing the complexity to N^2 . In better approach 
    
/*    int maxDepth(TreeNode* root){
        
        if(root==NULL){
            return  0 ;
        }
        int max_l = maxDepth(root->left);
        int max_r = maxDepth(root->right);
        
        // 1 is extra for the root nood;
        return 1 + max(max_l,max_r);

    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL){
            return true;
        }
       
        // finding left and right height from the root node
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        // checking for un-balance condition
        if(abs(lh-rh)>1) return false;
        
        // above line did not execute means the tree is balanced from the root node perspspective , now we have to check for other nodes as well;
        // so first we move left then right
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        // if both the variables left and right are true it means that tree is balanced for every node 
        
        if(!left || !right){
            return false;
        }
        return true;
    }
*/
};