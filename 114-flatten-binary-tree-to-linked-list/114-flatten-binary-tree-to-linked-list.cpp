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
    
    // Morris traversal 
//  tC: O(n) 
//  Sc: O(1)
    
    void flatten(TreeNode* root){
        TreeNode* cur = root;
		while (cur)
		{
			if(cur->left)
			{
				TreeNode* pre = cur->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
    
    }
    
    // Recursion
//  tC: O(n) 
//  Sc: O(n){Worst case time complexity will be O(N) (in case of skewed tree).}

//     TreeNode* prev=NULL;
//     void flatten(TreeNode* root) {
//       if(root==NULL) return;
        
//         flatten(root->right);
//         flatten(root->left);
        
//         root->right=prev;
//         root->left=NULL;
//         prev=root;    
//     }
    
    
    
    // iterative using stack 
//  tC: O(n) 
//  Sc: O(n
    
    // void flatten(TreeNode* root) {

    // stack<TreeNode*> s;
    // if(!root)
    //     return;
    // s.push(root);
    // while(!s.empty()){
    //     TreeNode* curr = s.top();
    //     s.pop();
    //     if(curr->right)
    //         s.push(curr->right);
    //     if(curr->left)
    //         s.push(curr->left);
    //     if(!s.empty())
    //         curr->right = s.top();
    //     curr->left=NULL;
    // }
    // }
};