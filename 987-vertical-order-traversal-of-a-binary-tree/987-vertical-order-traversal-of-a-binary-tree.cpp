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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes; // for storing all the nodes with                                                               coordinates
        queue<pair<TreeNode* , pair<int,int>>> q ; // for level order traversal
        q.push({root,{0,0}});
        while(!q.empty()){
            auto frontItem = q.front();
            q.pop();
            TreeNode* nodeInFront =  frontItem.first;
            int vertical = frontItem.second.first ;// vertical
            int level = frontItem.second.second;
            nodes[vertical][level].insert(nodeInFront->val); // inserting node                                                                 value in                                                                            multiset
            if(nodeInFront->left!=NULL){
                q.push({nodeInFront->left,{vertical-1,level+1}});
            }
            if(nodeInFront->right!=NULL){
                q.push({nodeInFront->right,{vertical+1,level+1}});
            }
        }
        
        vector<vector<int>> res;
        
        for(auto it : nodes){
            vector<int> verticalCol;
            for(auto i : it.second){
        verticalCol.insert(verticalCol.end(),i.second.begin(),i.second.end());
            }
            
            res.push_back(verticalCol);
        }
        
        return res;
    }
};