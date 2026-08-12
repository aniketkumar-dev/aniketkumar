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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL){
            return ans;
        }
        queue<pair< TreeNode*, int>>q;
        q.push({root,0});
       
        while(!q.empty()){
             vector<int>lev;
            int size = q.size();
            
            for(int i=0; i<size; i++){
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                int level = it.second;
                lev.push_back(node->val);
                // left
                if(node->left != NULL){
                    q.push({node->left, level + 1});
                }

                // right
                if(node->right != NULL){
                    q.push({node->right, level+1});
                }
                
                
                
                
            }
            ans.push_back(lev);
            
        
        }
        return ans;
        
    }
};