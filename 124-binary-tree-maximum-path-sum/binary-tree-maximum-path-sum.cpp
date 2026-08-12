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
 int solve(TreeNode* root){
    
    if(root == NULL){
        return 0;
    }
    int left = solve(root->left);
    int right = solve(root->right);
    return root->val + max(0,max(left , right));
 }
class Solution {
public:
    int maxPathSum(TreeNode* root) {
       if(root == NULL){
        return INT_MIN;
       } 

       int leftSum = solve(root->left);
       int rightSum = solve(root->right);
       int ans = root->val + max(0,leftSum) + max(0,rightSum);
       
       int leftMax = maxPathSum(root->left);
       int rightMax = maxPathSum(root->right);
        return max(ans, max(leftMax, rightMax));
       
    }
   
};