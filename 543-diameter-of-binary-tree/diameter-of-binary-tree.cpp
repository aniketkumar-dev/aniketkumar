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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

       int left = height(root->left);
        int right = height(root->right);
        int ans = left + right;

       int leftMax = diameterOfBinaryTree(root->left);
       int rightMax = diameterOfBinaryTree(root->right);
        return max(ans , max(leftMax, rightMax));
        
    }
};