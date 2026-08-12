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
 int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight , rightHeight);

 }
class Solution {
public:
    bool isBalanced(TreeNode* root) {

        if(root == NULL){
            return true;
        }
        int left =  height(root->left);
        int right = height(root->right);

        // 0 ya 1 ho sakta hai
        if(abs(left - right) > 1){
            return false;
        }
        return isBalanced(root->left) 
        && isBalanced(root->right);
    }
};