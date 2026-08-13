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
 int leftheight(TreeNode* root){
    
    int h = 0;
    while(root != NULL){
        h++;
        root= root->left;
    }
    return h;   
 }

 int rightheight(TreeNode* root){
    
    int h = 0;
    while(root != NULL){
        h++;
        root= root->right;
    }
    return h;   
 }

class Solution {
public:
    int countNodes(TreeNode* root) {
       if(root == NULL){
        return 0;
       } 

       int leftHeight =  leftheight(root);
       int rightHeight = rightheight(root);

       if(leftHeight != rightHeight){
        // ab equal nhi hoga usko likhna hai yeha 
        return 1 + countNodes(root->left) + countNodes(root->right);

       }
       
       return pow(2, leftHeight) - 1;
       
    }
}; 