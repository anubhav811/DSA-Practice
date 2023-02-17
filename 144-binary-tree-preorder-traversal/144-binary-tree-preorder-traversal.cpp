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
        main.push_back(root->val);
        solveRecur(root->left,main);
        solveRecur(root->right,main);
    }

    vector<int> preorderTraversal(TreeNode* root) {
       
        // For recursive part

//         vector<int> main;
//         solveRecur(root,main);
//         return main;
        
        // Iterative Solution
        
        
//         vector<int> preorder;
//         if(root==NULL)
//             return preorder;
        
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty()){
//             root = st.top();
//             st.pop();
//             preorder.push_back(root->val);
//             if(root->right !=NULL){
//                 st.push(root->right);
//             }
//             if(root->left!=NULL){
//                 st.push(root->left);
//             }
//         }
//         return preorder;
        
        
        //          Morris Traversal O(n) O(1)
        vector<int> preorder; 
        TreeNode *curr = root;
        while(curr!=NULL){
            if(curr->left == NULL){
                // means that the their is no left and hence this curr is a root itself , thus add it
                preorder.push_back(curr->val);
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
                    // we are at the root of the subtree , now we push it (This step is done after returning from the right tree in INORDER , but here we are doing it while marking the thread)
                    preorder.push_back(curr->val);
                    // making the thread from righmost node to curr
                    // next time when the curr reaches the same node this condition will fail go in else block
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    // now the node is itself the root , so it will be taken
                    curr=curr->right;
                }
                
            }
        }
        
        return preorder;
        
    }
};