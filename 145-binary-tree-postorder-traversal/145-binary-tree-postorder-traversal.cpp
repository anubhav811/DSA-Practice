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
        
    // Recursive solution function

    void solveRecur(TreeNode* root , vector<int> &main){
        if(root==NULL)
            return;
        solveRecur(root->left,main);
        solveRecur(root->right,main);
        main.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        // For recursive solution
        
//         vector<int> main;
//         solveRecur(root,main);
//         return main;
        
        // Iterative Solution using two stacks
        
        // vector<int> postorder;
        // if(root==NULL) return postorder;
        // stack<TreeNode*> s1,s2;
        // s1.push(root);
        // while(!s1.empty()){
        //     root = s1.top();
        //     s1.pop();
        //     s2.push(root);
        //     if(root->left != NULL)
        //         s1.push(root->left);
        //     if(root->right != NULL)
        //         s1.push(root->right);
        // }
        // while(!s2.empty())
        // {
        //     postorder.push_back(s2.top()->val);
        //     s2.pop();
        // }
        // return postorder;
        
    
        // Iterative Solution using one stack

    
//         vector<int> postorder;
//         if(root==NULL) return postorder;
//         stack<TreeNode*> s;
        
//         while(root!=NULL || !s.empty()){
//             if(root!=NULL){
//                 s.push(root);
//                 root = root->left;
//             }
//             else{
//                 TreeNode* temp  = s.top()->right;
//                 if(temp==NULL)
//                 {
//                     temp = s.top();
//                     s.pop();
//                     postorder.push_back(temp->val);
                    
//                     while(!s.empty() && temp==s.top()->right){
//                         temp=s.top();
//                         s.pop();
//                         postorder.push_back(temp->val);
//                     }
//                 }
//                 else
//                     root = temp;
//                 }
//             }
        
//         return postorder;
        
        
//          Morris Traversal O(n) O(1)
        vector<int> postorder; 
        TreeNode *curr = root;
        while(curr!=NULL){
            if(curr->right == NULL){
                // means that the their is no right and hence this curr is a root itself , thus add it
                postorder.push_back(curr->val);
                // now i have moved all the way right , add the root of the right subtree , now we go right
                curr = curr->left;
            }
            else{
                // right subtree exists
                // we will go to leftmost node of this subtree's right subtree (postorder ke hisaab se the last node to be visited of this subtree)
                // we will have to save the current node and then traverse 
                TreeNode *prev = curr->right;
                
                // the condition to be checked is that left exists and it doesnt point to curr (already)
                while(prev->left != NULL && prev->left != curr){
                    // keep going left
                    prev=prev->left;
                    
                }
                
                if(prev->left == NULL){
                    prev->left = curr;
                    // we are at the root of the subtree , now we push it 
                    // making the thread from leftmost node to curr
                    // next time when the curr reaches the same node this condition will fail go in else block
                    postorder.push_back(curr->val);
                    curr = curr->right;
                }
                else{
                    prev->left = NULL;
                    // now the node is itself the root , so it will be taken

                    // and then to continue the cycle point towards left
                    curr=curr->left;
                    
                }
                
            }
        }
        
        reverse(postorder.begin(),postorder.end());
        return postorder;
    
    }
};