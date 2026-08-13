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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*, int>>q;
        if(root == NULL){
            return ans;
        }
         bool leftToRight = true;
         // left se right jayega tab 1 
         // nhi to right se left gya to 0
        q.push({root,0});
        while(! q.empty()){
            vector<int>level;
            int size = q.size();
            for(int i=0; i<size; i++){
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                int lev = it.second;
                level.push_back(node->val);

                if(node->left != NULL){
                    // left ko push karege
                    q.push({node->left, lev + 1});

                }

                if(node->right != NULL){
                    // right ko push karege
                    q.push({node->right, lev + 1});

                }




            }
            // for loop khatam 
            if(!leftToRight){
                reverse(level.begin(), level.end());
            }
            ans.push_back(level);

            leftToRight = !leftToRight;
        }
        return ans;
    }
};