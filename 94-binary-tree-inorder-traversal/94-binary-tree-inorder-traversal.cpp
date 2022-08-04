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
        
        // Iterative Solution  O(n) O(n)
        
        // vector<int> inorder;
        // stack<TreeNode*> st;
        // while(root || !st.empty()){
        //     if(root!=NULL){
        //         st.push(root);
        //         root=root->left;
        //     }
        //     else{
        //         root = st.top();
        //         st.pop();
        //         inorder.push_back(root->val);
        //         root=root->right;
        //     }
        // }
        // return inorder;
    
//          Morris Traversal O(n) O(1)
        vector<int> inorder; 
        TreeNode *curr = root;
        while(curr!=NULL){
            if(curr->left == NULL){
                // means that the their is no left and hence this curr is a root itself , thus add it
                inorder.push_back(curr->val);
                // now i have moved all the way left , printed root of the left subtree , now we go right
                curr = curr->right;
            }
            else{
                // left subtree exists
                // we will go to rightmost node of this subtree's left subtree (inorder ke hisaab se the last node to be visited of this subtree)
                // we will have to save the current node and then traverse 
                TreeNode *prev = curr->left;
                
                // the condition to be checked is that right exists and it doesnt point to curr (already)
                while(prev->right != NULL && prev->right != curr){
                    // keep going right
                    prev=prev->right;
                }
                
                if(prev->right == NULL){
                    prev->right = curr;
                    // making the thread from righmost node to curr
                    // next time when the curr reaches the same node this condition will fail go in else block
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    // now the node is itself the root , so it will be taken
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
                
            }
        }
        
        return inorder;
        
    }
};