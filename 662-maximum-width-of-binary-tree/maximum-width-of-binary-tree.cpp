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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        // level order traversal
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long  ans = 0;
        while(!q.empty()){
            int size = q.size();
            long long first = q.front().second;
            long long last = first;
            
            for(int i=0; i<size; i++){
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                long long  index = it.second;
                last = index;
                
                if(node->left){
                    q.push({node->left, 2*(index - first) + 1});
                }
                
                if(node->right){
                    q.push({node->right, 2* (index - first) + 2});
                }

                
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
}; 