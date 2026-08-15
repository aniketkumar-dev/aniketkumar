/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }

        while(root != NULL){
        if(root->val > p->val && root->val > q->val){
            // left
            root = root->left;
        }else if ( root->val < p->val && root->val < q->val){
            // right
            root = root->right;

        }else{
            return root;
        }
        }
        return NULL;

        
    }
};